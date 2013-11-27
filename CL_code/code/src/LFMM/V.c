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

void create_m_V(double *U, float *R, double *C, double *beta, double *m_V,
		int M, int N, int D, int K, int num_thrd)
{
	int i, j, k, d;
	double *tmp_i;

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(R, NULL, U, NULL, C, beta, m_V, NULL, NULL,
				K, D, M, N, num_thrd, slice_mV_V, 0, 0);
        // uni-threaded or windows version
	} else {
#endif
                // TODO: check time
                // allocate memory 
		tmp_i = (double *) malloc(M * sizeof(double));

		// init m_V
		for (k = 0; k < K; k++) {
			for (j = 0; j < M; j++) {
				m_V[k * M + j] = 0;
			}
		}
		for (i = 0; i < N; i++) {
			// calculate tmp_i = R - C * B
			for (j = 0; j < M; j++)
				tmp_i[j] = (double)(R[i * M + j]);
			for (d = 0; d < D; d++) {
				for (j = 0; j < M; j++)
					tmp_i[j] -= C[i * D + d] * beta[d * M + j];
			}
			// calculate U * tmp_i
			for (k = 0; k < K; k++) {
				for (j = 0; j < M; j++)
					m_V[k * M + j] += U[k * N + i] * tmp_i[j];
			}
		}

		free(tmp_i);

#ifndef WIN32
	}
#endif
}

// create_inv_cov_V

void create_inv_cov_V(double *inv_cov_V, double alpha, double alpha_R,
		double *U, int K, int N, int num_thrd)
{
	int i, k1, k2;
	// allocate memory
	double *tmp = (double *)calloc(K * K, sizeof(double));

#ifndef WIN32
        // multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, U, NULL, NULL, NULL, NULL, tmp, NULL,
				K, 0, 0, N, num_thrd, slice_inv_cov_V, alpha, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
                // TODO: check time
		for (k1 = 0; k1 < K; k1++) {
			for (k2 = 0; k2 < k1; k2++) {
				// alpha_R * U %*% t(U) - diag(alpha)
				tmp[k1 * K + k2] = 0;
				for (i = 0; i < N; i++)
					tmp[k1 * K + k2] +=
						U[k1 * N + i] * U[k2 * N + i];
				tmp[k1 * K + k2] *= alpha_R;
				tmp[k2 * K + k1] = tmp[k1 * K + k2];
			}
			tmp[k1 * (K + 1)] = 0;
			for (i = 0; i < N; i++)
				tmp[k1 * (K + 1)] +=
					U[k1 * N + i] * U[k1 * N + i];
			tmp[k1 * (K + 1)] *= alpha_R;
			tmp[k1 * (K + 1)] += alpha;
		}
#ifndef WIN32
	}
#endif
	// inverse
	if (K == 1) {
		inv_cov_V[0] = 1.0 / tmp[0];
	} else {
		fast_inverse(tmp, K, inv_cov_V);
	}
	// free memory
	free(tmp);
}

// rand_V

void rand_V(double *V, double *m_V, double *inv_cov_V, double alpha_R, int K,
		int M, int num_thrd)
{
	double *mu;
	double *y;
	int j, k, kp;
	// allocate memory
	double *L = (double *)calloc(K * K, sizeof(double));

	// cholesky of inv_cov_V
	cholesky(inv_cov_V, K, L);

#ifndef WIN32
        // multithread non windows version
	if(num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, NULL, V, NULL, NULL, m_V, inv_cov_V, L,
				K, 0, M, 0, num_thrd, slice_rand_V, 0, alpha_R);
        // uni-threaded or windows version
	} else {
#endif
		// allocate memory
		mu = (double *)calloc(K, sizeof(double));
		y = (double *)calloc(K, sizeof(double));

		// inv_cov_V %*% m_V
		for (j = 0; j < M; j++) {
			for (k = 0; k < K; k++) {
				mu[k] = 0;
				for (kp = 0; kp < K; kp++) {
					mu[k] +=
						inv_cov_V[k * K + kp] * m_V[kp * M + j];
				}
				// times alpha_R
				mu[k] *= alpha_R;
			}
			// rand V
			mvn_rand(mu, L, K, y);
			for (k = 0; k < K; k++)
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

void update_V(double *C, float *dat, double *U, double *V, double *beta,
		double *m_V, double *inv_cov_V, double alpha_V, double alpha_R,
		int M, int N, int K, int D, int num_thrd)
{
	// m_V = U * (I.*(R - C*beta));                         (K,M)
	create_m_V(U, dat, C, beta, m_V, M, N, D, K, num_thrd);

	// cov_V = alpha .* eye(K) + alpha_R .* U*U';           (K,K)
	create_inv_cov_V(inv_cov_V, alpha_V, alpha_R, U, K, N, num_thrd);

	/*      mu_V = alpha_R .* inv(cov_V) * m_V;                     (K,M)
		for j=1:M
		V(:,j) = mvnrnd(mu_V(:,j),inv(cov_V));
		end                                                             */
	rand_V(V, m_V, inv_cov_V, alpha_R, K, M, num_thrd);

	if (isnan(V[0]))
		print_error_global("nan", NULL, 0);

}
