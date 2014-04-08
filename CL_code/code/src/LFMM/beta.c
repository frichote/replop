/*
   LFMM, file: beta.c
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
#include "../matrix/matrix.h"
#include "../matrix/cholesky.h"
#include "../matrix/inverse.h"
#include "../matrix/rand.h"
#include "beta.h"
#include "data_lfmm.h"
#include "error_lfmm.h"

# ifndef WIN32
#include "thread_lfmm.h"
#include "thread_beta.h"
# endif

// create_m_beta

void create_m_beta(double *C, float *R, double *U, double *V, double *m_beta,
		int M, int N, int D, int K, int num_thrd)
{
	int i, j, k, d;
	double *tmp_i;

# ifndef WIN32
	// multi-threaded non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(R, NULL, U, V, C, NULL, m_beta, NULL, NULL,
				K, D, M, N, num_thrd, slice_mbeta_beta, 0, 0);
	} else {
# endif
		// uni-threaded or windows version
		// TODO: check time
		// allocate memory 
		tmp_i = (double *) malloc(M * sizeof(double));

		// init m_beta
		for (d = 0; d < D; d++) {
			for (j = 0; j < M; j++) {
				m_beta[d * M + j] = 0;
			}
		}

		for (i = 0; i < N; i++) {
			// calculate tmp_i = R - U * V
			for (j = 0; j < M; j++)
				tmp_i[j] = (double)(R[i * M + j]);      // R(N,M)
			for (k = 0; k < K; k++) {
				for (j = 0; j < M; j++)
					tmp_i[j] -= U[k * N + i] * V[k * M + j];        // U(K,N) V(K,M)
			}
			// calculate C * tmp_i	
			for (d = 0; d < D; d++) {
				for (j = 0; j < M; j++)
					m_beta[d * M + j] += C[i * D + d] * tmp_i[j];   // C(N,D)
			}
		}
		// free memory
		free(tmp_i);
# ifndef WIN32
	}
# endif
}

// create_CCt

void create_CCt(double *cov, double *C, int D, int N)
{
	int d1, d2, i;

	// calculate t(C) %*% C
	for (d1 = 0; d1 < D; d1++) {
		for (d2 = 0; d2 < d1; d2++) {
			for (i = 0; i < N; i++)
				cov[d1 * D + d2] += C[i * D + d1] * C[i * D + d2];	// C(N,D)
			cov[d2 * D + d1] = cov[d1 * D + d2];			
		}
		for (i = 0; i < N; i++)
			cov[d1 * (D + 1)] += C[i * D + d1] * C[i * D + d1];	// C(N,D)
		
	}
}

// create_inv_cov_beta

void create_inv_cov_beta(double *inv_cov_beta, double *alpha_beta,
		double alpha_R, int D, double *cov)
{
	int d1, d2;
	// allocate memory
	double *tmp = (double *)calloc(D * D, sizeof(double));

	// alpha_R .* C'*C
	for (d1 = 0; d1 < D; d1++) {
		for (d2 = 0; d2 < D; d2++) {
			tmp[d1 * D + d2] = alpha_R * cov[d1 * D + d2];
			if (d1 == d2)
				// alpha_beta .* eye(K)
				tmp[d1 * (D + 1)] += alpha_beta[d1];
		}
	}

	// inverse
	if (D == 1) {
		inv_cov_beta[0] = 1.0 / tmp[0];
	} else {
		fast_inverse(tmp, D, inv_cov_beta);
	}

	// free memory
	free(tmp);
}

// rand_beta

void rand_beta(double *beta, double *m_beta, double *inv_cov_beta,
		double alpha_R, int D, int M, int num_thrd)
{
	int j, d, dp;
        double *mu;
        double *y;
	// allocate memory
	double *L = (double *)calloc(D * D, sizeof(double));

	// cholesky of inv_cov_beta
	cholesky(inv_cov_beta, D, L);

# ifndef WIN32
	// multithread non windows version
	if (num_thrd > 1) {
		thread_fct_lfmm(NULL, NULL, NULL, NULL, NULL, beta, m_beta, inv_cov_beta, L,
				0, D, M, 0, num_thrd, slice_rand_beta, 0, alpha_R);
	// uni-threaded or windows version
	} else {
# endif
		// allocate memory
        	mu = (double *)calloc(D, sizeof(double));
        	y = (double *)calloc(D, sizeof(double));

		for (j = 0; j < M; j++) {
			for (d = 0; d < D; d++) {
				// inv_cov_beta %*% m_beta
				mu[d] = 0;
				for (dp = 0; dp < D; dp++) {
					mu[d] += inv_cov_beta[d * D + dp] * m_beta[dp * M + j]; // inv(D,D) 
				}
				// times alpha_R
				mu[d] *= alpha_R;
			}
			// rand beta
			mvn_rand(mu, L, D, y);
			for (d = 0; d < D; d++)
				beta[d * M + j] = y[d]; // beta(D,M)
		}

		// free memory
		free(mu);
		free(y);
# ifndef WIN32
	}
# endif
	// free memory
	free(L);
}

// update_beta

void update_beta(double *C, float *dat, double *U, double *V, double *beta,
		double *CCt, double *m_beta, double *inv_cov_beta,
		double *alpha_beta, double alpha_R, int M, int N,
		int K, int D, int num_thrd)
{
	// m_beta = C' * (I.*(R - U'*V));                       (D,M)
	create_m_beta(C, dat, U, V, m_beta, M, N, D, K, num_thrd);

	// cov_beta = alpha_beta .* eye(D) + alpha_R .* C'*C;   (D,D)
	create_inv_cov_beta(inv_cov_beta, alpha_beta, alpha_R, D, CCt);

	/*      mu_beta = alpha_R .* inv(cov_beta) * m_beta;            (D,M)
		for j=1:M
		beta(:,j) = mvnrnd(mu_beta(:,j),inv(cov_beta));
		end                                                             */
	rand_beta(beta, m_beta, inv_cov_beta, alpha_R, D, M, num_thrd);

	/*
	for (j = 0; j < M; j++) {  
		mean = 0.0;
		for (i = 0; i < N; i++) {
			mean += dat[i * M + j];
		}
		beta[j] = mean/N;
	}
	*/

	if (isnan(beta[0]))
		print_error_global("nan", NULL, 0);
}

// update_alpha_beta

void update_alpha_beta(double *beta, double *alpha_beta, double epsilon,
		int D, int M)
{
	//a = 1 + M/2;
	int d;
	//int a = (int)(epsilon) + M/2;
	int a = (int)0 + M / 2;
	// allocate memory
	double *bb = (double *)calloc(D, sizeof(double));

	// b = 1/2 * sum(sum(beta.^2));
	dble_sum2(beta, D, M, bb, 0.0);	// beta(K,M)
	//dble_sum2(beta,D,M,bb,1); // beta(K,M)

	// update alpha_beta
	alpha_beta[0] = rand_gamma(a+.0001, 1.0/(double)(bb[0]+.0001));
	for (d = 1; d < D; d++)
		alpha_beta[d] = rand_gamma(a + epsilon, 1.0 / (double)(bb[d] + epsilon));

	// free memory
	free(bb);
}
