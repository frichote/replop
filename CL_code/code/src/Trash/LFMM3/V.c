/*
   LFMM, file: V.c
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
#include "V.h"
#include "data_lfmm.h"
#include "error_lfmm.h"
#include "../matrix/matrix.h"
#include "../matrix/cholesky.h"
#include "../matrix/inverse.h"
#include "../io/read.h"
#include "../matrix/rand.h"

#ifndef WIN32
#include "thread_lfmm.h"
#include "thread_V.h"
#endif

// create_m_V

void create_m_V(double *U, float *R, double *m_V,
		int M, int N, int Kp, int num_thrd)
{
	int i, j, k;

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(R, NULL, U, NULL, NULL, NULL, m_V, NULL, NULL,
				Kp, 0, M, N, num_thrd, slice_mV_V, 0, 0);
        // uni-threaded or windows version
	} else {
#endif
		
		// init m_V
		for (k = 0; k < Kp; k++)
			for (j = 0; j < M; j++) 
				m_V[k * M + j] = 0;
		// m_V = U * R
		for (i = 0; i < N; i++)
			for (k = 0; k < Kp; k++)
				for (j = 0; j < M; j++)
					m_V[k * M + j] += U[k * N + i] * (double)R[i * M + j];
#ifndef WIN32
	}
#endif
}

// create_inv_cov_V

void create_inv_cov_V(double *inv_cov_V, double *alpha_V, double alpha_R,
		double *U, int Kp, int N, int num_thrd)
{
	int i, k1, k2;
	// allocate memory
	double *tmp = (double *)calloc(Kp * Kp, sizeof(double));

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, U, NULL, NULL, NULL, NULL, tmp, NULL,
				Kp, 0, 0, N, num_thrd, slice_inv_cov_V, alpha_V, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		for (k1 = 0; k1 < Kp; k1++) {
			for (k2 = 0; k2 < k1; k2++) {
				// alpha_R * U %*% t(U) + diag(alpha_V)
				tmp[k1 * Kp + k2] = 0;
				for (i = 0; i < N; i++)
					tmp[k1 * Kp + k2] +=
						U[k1 * N + i] * U[k2 * N + i];
				tmp[k1 * Kp + k2] *= alpha_R;
				tmp[k2 * Kp + k1] = tmp[k1 * Kp + k2];
			}
			tmp[k1 * (Kp + 1)] = 0;
			for (i = 0; i < N; i++)
				tmp[k1 * (Kp + 1)] +=
					U[k1 * N + i] * U[k1 * N + i];
			tmp[k1 * (Kp + 1)] *= alpha_R;
			tmp[k1 * (Kp + 1)] += alpha_V[k1];
		}
#ifndef WIN32
	}
#endif
	// inverse
	if (Kp == 1) {
		inv_cov_V[0] = 1.0 / tmp[0];
	} else {
		fast_inverse(tmp, Kp, inv_cov_V);
	}
	// free memory
	free(tmp);
}

// rand_V

void rand_V(double *V, double *m_V, double *inv_cov_V, double alpha_R, int Kp,
		int M, int num_thrd)
{
	double *mu;
	double *y;
	int j, k, kp;
	// allocate memory
	double *L = (double *)calloc(Kp * Kp, sizeof(double));

	// cholesky of inv_cov_V
	cholesky(inv_cov_V, Kp, L);

#ifndef WIN32
        // multithread non windows version
	if(num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, NULL, V, NULL, NULL, m_V, inv_cov_V, L,
				Kp, 0, M, 0, num_thrd, slice_rand_V, 0, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		// allocate memory
		mu = (double *)calloc(Kp, sizeof(double));
		y = (double *)calloc(Kp, sizeof(double));

		// inv_cov_V %*% m_V
		for (j = 0; j < M; j++) {
			for (k = 0; k < Kp; k++) {
				mu[k] = 0;
				for (kp = 0; kp < Kp; kp++) {
					mu[k] +=
						inv_cov_V[k * Kp + kp] * m_V[kp * M + j];
				}
				// times alpha_R
				mu[k] *= alpha_R;
			}
			// rand V
			mvn_rand(mu, L, Kp, y);
			for (k = 0; k < Kp; k++)
				V[k * M + j] = y[k];
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

// update_V

void update_V(float *dat, double *U, double *V, 
		double *m_V, double *inv_cov_V, double *alpha_V, double alpha_R,
		int M, int N, int K, int D, int num_thrd)
{
	// m_V = U * (I.*(R - C*beta));                         (K,M)
	create_m_V(U, dat, m_V, M, N, K+D, num_thrd);

	// cov_V = alpha .* eye(K) + alpha_R .* U*U';           (K,K)
	create_inv_cov_V(inv_cov_V, alpha_V, alpha_R, U, K+D, N, num_thrd);

	/*      mu_V = alpha_R .* inv(cov_V) * m_V;                     (K,M)
		for j=1:M
		V(:,j) = mvnrnd(mu_V(:,j),inv(cov_V));
		end                                                             */
	rand_V(V, m_V, inv_cov_V, alpha_R, K+D, M, num_thrd);

	if (isnan(V[0]))
		print_error_global("nan", NULL, 0);

}

// update_alpha_V

void update_alpha_V(double *V, double *alpha_V, double epsilon,
                int D, int K, int N, int M)
{
        //a = 1 + M/2;
        int d;
        //int a = (int)(epsilon) + M/2;
        int a = (int)0 + M / 2;
        // allocate memory
        double *bb = (double *)calloc(D, sizeof(double));

        // b = 1/2 * sum(sum(V[1:D,].^2));
        dble_sum2(V, D, M, bb, epsilon);     // beta(K,M)

        // update alpha_V
//        alpha_V[0] = 1.0; //rand_gamma(a+999,1.0/(double)(bb[0]+999));

        //alpha_V[0] = rand_gamma(a,1.0/(double)(bb[0]));
        // alpha_V[0] = 1;
        for (d = 0; d < D; d++)
                alpha_V[d] = rand_gamma(a, 1.0 / (double)(bb[d]));

        // free memory
        free(bb);
}

