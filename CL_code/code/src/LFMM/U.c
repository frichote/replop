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

void create_m_U(double *V, float *R, double *C, double *beta, double *m_U,
		int M, int N, int D, int K, int num_thrd)
{
	int i, j, k, d;
	double *tmp_i;

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(R, NULL, NULL, V, C, beta, m_U, NULL, NULL,
				K, D, M, N, num_thrd, slice_mU_U, 0, 0);
	} else { 
#endif
                // uni-threaded or windows version
                // TODO: check time
                // allocate memory 
		tmp_i = (double *) malloc(M * sizeof(double));


		for (i = 0; i < N; i++) {
                        // calculate tmp_i = R - X B
			for (j = 0; j < M; j++)
				tmp_i[j] = (double)(R[i * M + j]);
			for (d = 0; d < D; d++) {
				for (j = 0; j < M; j++)
					tmp_i[j] -= C[i * D + d] * beta[d * M + j];
			}
                        // calculate tmp_i * V
			for (k = 0; k < K; k++) {
				m_U[i * K + k] = 0;
				for (j = 0; j < M; j++)
					m_U[i * K + k] += V[k * M + j] * tmp_i[j];
			}
		}
		// free memory
		free(tmp_i);
#ifndef WIN32
	}
#endif
}

// create_inv_cov_U

void create_inv_cov_U(double *inv_cov_U, double alpha, double alpha_R,
		double *V, int K, int M, int num_thrd)
{
	int k1, k2, j;
	// allocate memory
	double *tmp2 = (double *)calloc(K * K, sizeof(double));

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, NULL, V, NULL, NULL, NULL, tmp2, NULL,
				K, 0, M, 0, num_thrd, slice_inv_cov_U, alpha, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		// calculate _cov_U = alphaR V %*% t(V) + diag(alpha)
		for (k1 = 0; k1 < K; k1++) {
			for (k2 = 0; k2 < k1; k2++) {
				tmp2[k1 * K + k2] = 0;
				for (j = 0; j < M; j++)
					tmp2[k1 * K + k2] +=
						(V[k1 * M + j] * V[k2 * M + j]);
				tmp2[k1 * K + k2] *= alpha_R;
				tmp2[k2 * K + k1] = tmp2[k1 * K + k2];

			}
			tmp2[k1 * (K + 1)] = 0;
			for (j = 0; j < M; j++)
				tmp2[k1 * (K + 1)] +=
					(V[k1 * M + j] * V[k1 * M + j]);
			tmp2[k1 * (K + 1)] *= alpha_R;
			tmp2[k1 * (K + 1)] += alpha;
		}
#ifndef WIN32
	}
#endif

	// inverse  
	if (K == 1) {
		inv_cov_U[0] = 1 / tmp2[0];
	} else {
		fast_inverse(tmp2, K, inv_cov_U);
	}
	// free memory
	free(tmp2);
}

// rand_U

void rand_U(double *U, double *m_U, double *inv_cov_U, double alpha_R,
		int K, int N, int num_thrd)
{
	int i, k, kp;
        double *mu;
        double *y;
	// allocate memory
	double *L = (double *)calloc(K * K, sizeof(double));

	// cholesky of inv_cov_U
	cholesky(inv_cov_U, K, L);

#ifndef WIN32
        // multithread non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, U, NULL, NULL, NULL, m_U, inv_cov_U, L,
				K, 0, 0, N, num_thrd, slice_rand_U, 0, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		// allocate memory
        	mu = (double *)calloc(K, sizeof(double));
        	y = (double *)calloc(K, sizeof(double));
		for (i = 0; i < N; i++) {
			for (k = 0; k < K; k++) {
				// inv_cov_U %*% m_u
				mu[k] = 0;
				for (kp = 0; kp < K; kp++) {
					mu[k] +=
						inv_cov_U[k * K + kp] * m_U[i * K + kp];
				}
				// times alpha_R
				mu[k] *= alpha_R;
			}
			// rand U
			mvn_rand(mu, L, K, y);
			for (k = 0; k < K; k++)
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

void update_U(double *C, float *dat, double *U, double *V, double *beta,
		double *m_U, double *inv_cov_U, double alpha_U, double alpha_R,
		int M, int N, int K, int D, int num_thrd)
{
	// m_U = (I.*(R - C*beta)) * V';                        (N,K)
	create_m_U(V, dat, C, beta, m_U, M, N, D, K, num_thrd);

	// cov_U = alpha .* eye(K) + alpha_R .* V*V';           (K,K)
	create_inv_cov_U(inv_cov_U, alpha_U, alpha_R, V, K, M, num_thrd);

	/*      mu_U = alpha_R .* inv(cov_U) * m_U';                    (N,K)
		for i=1:N
		U(:,i) = mvnrnd(mu_U(:,i),inv(cov_U));
		end                                                             */
	rand_U(U, m_U, inv_cov_U, alpha_R, K, N, num_thrd);

	if (isnan(U[0]))
		print_error_global("nan", NULL, 0);

}

// update_alpha_U

void update_alpha_U(double *U, double *alpha_U, double epsilon, int K, int N)
{
	epsilon = 0.1;
	int a = (int)(epsilon) + N * K / 2;
	// b = 1/2*sum(sum(U.^2)) + 1/2*sum(sum(V.^2));
	int b = 0.5 * dble_sum(U, N * K) + epsilon;	// U(D,N) V(D,M)

	// update alpha_U
	*alpha_U = rand_gamma(a, 1.0 / b);}
