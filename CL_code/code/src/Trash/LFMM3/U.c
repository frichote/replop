/*
   LFMM, file: U.c
   Copyright (C) 2012 Eric Frichot

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include "U.h"
#include "data_lfmm.h"
#include "../matrix/matrix.h"
#include "../matrix/cholesky.h"
#include "../matrix/inverse.h"
#include "../io/read.h"
#include "../matrix/rand.h"
#include "error_lfmm.h"

#ifndef WIN32
#include "thread_U.h"
#include "thread_lfmm.h"
#endif

// create_m_U

void create_m_U(double *V, float *R, double *m_U,
		int M, int N, int Kp, int num_thrd)
{
	int i, j, k;

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(R, NULL, NULL, V, NULL, NULL, m_U, NULL, NULL,
				Kp, 0, M, N, num_thrd, slice_mU_U, 0, 0);
	} else { 
#endif
		// V * R
		for (i = 0; i < N; i++) {
			for (k = 0; k < Kp; k++) {
				m_U[i * Kp + k] = 0;
				for (j = 0; j < M; j++)
					m_U[i * Kp + k] += V[k * M + j] * R[i * M + j];
			}
		}
#ifndef WIN32
	}
#endif
}

// create_inv_cov_U

void create_inv_cov_U(double *inv_cov_U, double *cov_U, double* alpha_U, 
		double alpha_R, double *V, int Kp, int M, int num_thrd)
{
	int k1, k2, j;
	// allocate memory

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, NULL, V, NULL, NULL, NULL, cov_U, NULL,
				Kp, 0, M, 0, num_thrd, slice_inv_cov_U, alpha_U, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		// calculate _cov_U = alphaR V %*% t(V) + diag(alpha)
		for (k1 = 0; k1 < Kp; k1++) {
			for (k2 = 0; k2 < k1; k2++) {
				cov_U[k1 * Kp + k2] = 0;
				for (j = 0; j < M; j++)
					cov_U[k1 * Kp + k2] +=
						(V[k1 * M + j] * V[k2 * M + j]);
				cov_U[k1 * Kp + k2] *= alpha_R;
				cov_U[k2 * Kp + k1] = cov_U[k1 * Kp + k2];

			}
			cov_U[k1 * (Kp + 1)] = 0;
			for (j = 0; j < M; j++)
				cov_U[k1 * (Kp + 1)] +=
					(V[k1 * M + j] * V[k1 * M + j]);
			cov_U[k1 * (Kp + 1)] *= alpha_R;
			cov_U[k1 * (Kp + 1)] += alpha_U[k1];
		}
#ifndef WIN32
	}
#endif

	// inverse  
	if (Kp == 1) {
		inv_cov_U[0] = 1 / cov_U[0];
	} else {
		fast_inverse(cov_U, Kp, inv_cov_U);
	}
	// free memory
}

// rand_U

void rand_U(double *U, double *m_U, double *inv_cov_U, double alpha_R,
		int K, int D, int N, int num_thrd)
{
	int i, k, kp, j;
        double *mu;
        double *y;
	int Kp = K + D;
	// allocate memory
	double *L = (double *)calloc(Kp * Kp, sizeof(double));

	// cholesky of inv_cov_U
	cholesky(inv_cov_U, Kp, L);

#ifndef WIN32
        // multithread non windows version
	
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, U, NULL, NULL, NULL, m_U, inv_cov_U, L,
				K, D, 0, N, num_thrd, slice_rand_U, 0, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		// allocate memory
        	mu = (double *)calloc(Kp, sizeof(double));
        	y = (double *)calloc(Kp, sizeof(double));
		for (i = 0; i < N; i++) {
			for (k = 0; k < Kp; k++) {
				// inv_cov_U %*% m_u
				mu[k] = 0;
				for (kp = 0; kp < Kp; kp++) {
					mu[k] +=
						inv_cov_U[k * Kp + kp] * m_U[i * Kp + kp];
				}
				// times alpha_R
				mu[k] *= alpha_R;
			}
			// rand U
			mvn_rand(mu, L, Kp, y);
			for (k = D; k < K+D; k++)
				U[k * N + i] = y[k];
		}
		// free memory
		free(mu);
		free(y);
#ifndef WIN32
	}
#endif
	// free memory
	free(L);
}

// update_U

void update_U(float *dat, double *U, double *V,
		double *m_U, double *inv_cov_U, double *cov_U, double *alpha_U, 
		double alpha_R, int M, int N, int K, int D, int num_thrd)
{
	// m_U = (I.*R) * V';                        (N,K+D)
	create_m_U(V, dat, m_U, M, N, K+D, num_thrd);

	// cov_U = alpha .* eye(K) + alpha_R .* V*V';           (K+D,K+D)
	create_inv_cov_U(inv_cov_U, cov_U, alpha_U, alpha_R, V, K+D, M, num_thrd);

	/*      mu_U = alpha_R .* inv(cov_U) * m_U';                    (N,K+D)
		for i=1:N
		U(:,i) = mvnrnd(mu_U(:,i),inv(cov_U));
		end                                                             */
	rand_U(U, m_U, inv_cov_U, alpha_R, K, D,N, num_thrd);

	if (isnan(U[0]))
		print_error_global("nan", NULL, 0);

}

// update_alpha_U

void update_alpha_U(double *U, double *alpha_U, double epsilon, int K, int D, int N, int M)
{
	int k;

	int a = (int)0 + N / 2;
	// b = 1/2*sum(sum(U.^2)) + eps;
	double *bb = (double *)calloc(D + K, sizeof(double));

        dble_sum2(U, D+K, N, bb, epsilon);     // beta(K,M)

	// update alpha_U
	for (k = 0; k < D; k++) 
		alpha_U[k] = 0;
	for (k = D; k < (K+D); k++)  {
		// b = 0.5 * dble_sum(&(U[k*N]), N) + epsilon;	// U(D,N) V(D,M)
		alpha_U[k] = rand_gamma(a, 1.0 / (double)bb[k]);
	}

	free(bb);
}
