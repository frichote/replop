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
#include "thread_lfmm.h"
#include "thread_V.h"

extern void slice_mV_V(void *G);
extern void slice_rand_V(void *G);
extern void slice_inv_cov_V(void *G);

// create_m_V

void create_m_V(double *U, float *R, double *C, double *beta, double *m_V,
		int M, int N, int D, int K, float *datb, int num_thrd)
{
	thread_fct_lfmm(R, datb, U, NULL, C, beta, m_V, NULL, NULL,
		   K, D, M, N, num_thrd, slice_mV_V, 0, 0);
}

// create_inv_cov_V

void create_inv_cov_V(double *inv_cov_V, double alpha, double alpha_R,
		      double *U, int K, int N, int num_thrd)
{
	double *tmp = (double *)calloc(K * K, sizeof(double));

	//if (num_thrd > 1) {
	thread_fct_lfmm(NULL, NULL, U, NULL, NULL, NULL, NULL, tmp, NULL,
		   K, 0, 0, N, num_thrd, slice_inv_cov_V, alpha, alpha_R);
	/*
	   } else {
	   for(d1=0; d1<D; d1++) {
	   for(d2=0; d2<D; d2++) {
	   tmp[d1*D+d2] = 0;
	   for(i=0; i<N; i++)
	   tmp[d1*D+d2] += U[d1*N+i]* U[d2*N+i];
	   tmp[d1*D+d2] *= alpha_R;
	   }
	   tmp[d1*D+d1] += alpha;
	   }    
	   }
	 */

	// inverse
	if (K == 1) {
		inv_cov_V[0] = 1 / tmp[0];
	} else {
		fast_inverse(tmp, K, inv_cov_V);
	}

	free(tmp);
}

// rand_V

void rand_V(double *V, double *m_V, double *inv_cov_V, double alpha_R, int K,
	    int M, int num_thrd)
{
	double *L = (double *)calloc(K * K, sizeof(double));
	double *mu = (double *)calloc(K, sizeof(double));
	double *y = (double *)calloc(K, sizeof(double));

	cholesky(inv_cov_V, K, L);

	//if(num_thrd > 1) {
	thread_fct_lfmm(NULL, NULL, NULL, V, NULL, NULL, m_V, inv_cov_V, L,
		   K, 0, M, 0, num_thrd, slice_rand_V, 0, alpha_R);
	/*
	   } else {
	   for(j=0;j<M;j++) {
	   for(d=0;d<D;d++) {
	   mu[d] = 0;
	   for(dp=0;dp<D;dp++) {
	   mu[d] += inv_cov_V[d*D+dp] * m_V[dp*M+j];
	   }
	   mu[d] *= alpha_R;
	   }
	   mvn_rand(mu,L,D,y);
	   for(d=0;d<D;d++)
	   V[d*M+j] = y[d];
	   }
	   }
	 */
	free(L);
	free(mu);
	free(y);
}

// update_V

void update_V(double *C, float *dat, double *U, double *V, double *beta,
	      double *m_V, double *inv_cov_V, double alpha_V, double alpha_R,
	      int M, int N, int K, int D, int num_thrd)
{
	// m_V = U * (I.*(R - C*beta));                         (K,M)
	create_m_V(U, dat, C, beta, m_V, M, N, D, K, dat, num_thrd);

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
