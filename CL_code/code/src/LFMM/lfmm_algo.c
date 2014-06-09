/*
   LFMM, file: lfmm_algo.c
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

#include "print_lfmm.h"
#include "lfmm_algo.h"
#include "data_lfmm.h"
#include "error_lfmm.h"
#include "beta.h"
#include "U.h"
#include "V.h"
#include "../matrix/rand.h"
#include "../matrix/matrix.h"
#include "../matrix/normalize.h"
#include "../io/print_bar.h"
#include "../io/io_data_float.h"
#include "../io/io_data_double.h"
#include <stdio.h>
#include <stdlib.h>

// lfmm_emcmc

void lfmm_emcmc(float *dat, int *I, double *C, double *zscore, double *beta,
		double *U, double *V, double *alpha_beta, double *alpha_R,
		double *alpha_U, int N, int M, int K, int D,
		double noise_epsilon, double b_epsilon, int init, 
		int Niter, int burn, int missing_data,
		int num_thrd, double *dev, double *DIC, double *perc_var)
{
	double *m_beta, *inv_cov_beta, *m_U, *inv_cov_U, *m_V, *inv_cov_V, *m_var;
	double *mean, *mean_U, *mean_V, *sum, *sum2, *bb, *CCt;
	int i, j, n, d;
	double deviance = 0;
	double dp = 0;
	double thrd_m2 = 0;

	// allocate memory
	allocate_all(&m_beta, &inv_cov_beta, &m_U, &inv_cov_U, &m_V, &inv_cov_V,
		     &m_var, &mean, &mean_U, &mean_V, &sum2, &sum, &bb, &CCt, N, M, K,
		     D);

	printf("\t\tStart of the Gibbs Sampler algorithm.\n\n");

	create_CCt(CCt, C, D, N);
	// init U, V and beta
	if (init) {
		rand_matrix_double(beta, D, M);
		rand_matrix_double(U, K, N);
		rand_matrix_double(V, K, M);
	} else {
		zeros(beta, D*M);
		zeros(U, K*N);
		zeros(V, K*M);
	}

	if(missing_data)
		*alpha_R = 1.0 / 
			var_data_inputation(dat, I, U, V, C, beta, N, M, K, D, 
				&thrd_m2, num_thrd);
	else 
		*alpha_R = 1.0 / 
			var_data(dat, U, V, C, beta, N, M, K, D, &thrd_m2, num_thrd);

	// shell print
	init_bar(&i, &j);

	n = 0;
	while (n < Niter) {
		// print shell
		print_bar(&i, &j, Niter);

		// update_alpha_U
		update_alpha_U(U, alpha_U, noise_epsilon, K, N);

		// update_alpha_beta
		update_alpha_beta(beta, alpha_beta, noise_epsilon, b_epsilon, D, M);

		// update_beta
		update_beta(C, dat, U, V, beta, CCt, m_beta, inv_cov_beta,
			    alpha_beta, *alpha_R, M, N, K, D, num_thrd);

		// update U
		update_U(C, dat, U, V, beta, m_U, inv_cov_U, *alpha_U, *alpha_R,
			 M, N, K, D, num_thrd);

		// update V
		update_V(C, dat, U, V, beta, m_V, inv_cov_V, (double)(1),
			 *alpha_R, M, N, K, D, num_thrd);

		// update_var
		udpate_var(m_var, U, V, beta, 1/(*alpha_R), N, M, K, D); 

		// update alpha_R
		if(missing_data)
			*alpha_R = 1.0 / 
				var_data_inputation(dat, I, U, V, C, beta, N, M, K, D, 
					&thrd_m2, num_thrd);
		else 
			*alpha_R = 1.0 / 
				var_data(dat, U, V, C, beta, N, M, K, D, 
					&thrd_m2, num_thrd);

		// update sums
		if (n >= burn) 
			update_sums(beta, U, V, m_var, perc_var, sum, sum2, mean_U, 
				    mean_V, &deviance, thrd_m2, N, M, K, D, *alpha_R);
		n++;
	}
	final_bar();
	printf("\n");
	printf("\t\tEnd of the Gibbs Sampler algorithm.\n\n");
	// calculate zscore
	
	zscore_calc(zscore, sum, sum2, M, Niter - burn, D);

	// check zscore
	if (check_mat(zscore, M, 0, 1))
		print_error_global("nan", NULL, 0);

	// calculate dp and deviance
	calc_dp_deviance(dat, sum, mean_U, mean_V, C, &deviance, &dp,
			 Niter - burn, N, M, K, D, num_thrd, perc_var);

	// percentage of variance
	normalize_lines(perc_var, 1, K + D + 1);
	//print_perc(perc_var, K, D);

	// save ED and DIC
	*dev = deviance;
	*DIC = 2 * deviance - dp;
	printf("\tED:%10.10G\t DIC: %10.10G \n\n", deviance, 2 * deviance - dp);
        // write_DIC(dev_file,deviance,2*deviance-dp);

	// free memory
	free_all(m_beta, inv_cov_beta, m_U, inv_cov_U, m_V, inv_cov_V, 
		 m_var, mean, mean_U, mean_V, sum2, sum, bb, CCt);
}

// update_var

void udpate_var(double *m_var, double *U, double *V, double *beta, double var_R,
	int N, int M, int K, int D)
{
	int k, d;

	m_var[0] = var_R;

	for(d = 0; d < D; d++)
		m_var[d + 1] = variance(&(beta[d * M]), M); 
	m_var[1] /= N;

	for(k = 0; k < K; k++)
		m_var[k + 1 + D] = variance(&(U[k * N]), N) * variance(&(V[k * M]), M);  

} 

// update_sums

void update_sums(double *beta, double *U, double *V, double *m_var, 
		 double *mean_var, double *sum, double *sum2,
		 double *mean_U, double *mean_V, double *deviance,
		 double thrd_m2, int N, int M, int K, int D, double alpha_R)
{
	double dv;

	update_sum(beta, sum, D * M);
	update_sum(m_var, mean_var, D + K + 1);
	update_sum2(beta, sum2, D * M);
	update_sum(U, mean_U, K * N);
	update_sum(V, mean_V, K * M);
	dv = thrd_m2 * alpha_R;
	update_sum(&dv, deviance, 1);
}

// calc_dp_deviance

void calc_dp_deviance(float *dat, double *sum, double *mean_U, double *mean_V,
		      double *C, double *deviance, double *dp, int size, int N,
		      int M, int K, int D, int num_thrd, double *mean_var)
{
	double thrd_m2, tmp;

	update_m(sum, D * M, size);
	update_m(mean_U, K * N, size);
	update_m(mean_V, K * M, size);
	update_m(deviance, 1, size);
	tmp =
	    var_data(dat, mean_U, mean_V, C, sum, N, M, K, D, &thrd_m2,
		     num_thrd);
	*dp = thrd_m2 / tmp;

	update_m(mean_var, K + D + 1, size);
}

// allocate_all

void allocate_all(double **m_beta, double **inv_cov_beta, double **m_U,
		  double **inv_cov_U, double **m_V, double **inv_cov_V,
		  double **m_var, double **mean, double **mean_U, double **mean_V,
		  double **sum2, double **sum, double **bb, double **CCt, int N,
		  int M, int K, int D)
{
	*m_beta = (double *) malloc(D * M * sizeof(double));
	*inv_cov_beta = (double *) malloc(D * D * sizeof(double));
	*m_U = (double *) malloc(K * N * sizeof(double));
	*inv_cov_U = (double *) malloc(K * K * sizeof(double));
	*m_V = (double *) malloc(K * M * sizeof(double));
	*inv_cov_V = (double *) malloc(K * K * sizeof(double));
	*m_var = (double *) malloc((K + D + 1) * sizeof(double));

	*mean = (double *)calloc(D * M, sizeof(double));
	*mean_U = (double *)calloc(K * N, sizeof(double));
	*mean_V = (double *)calloc(K * M, sizeof(double));
	*sum = (double *)calloc(D * M, sizeof(double));
	*sum2 = (double *)calloc(D * M, sizeof(double));
	*bb = (double *)calloc(D, sizeof(double));
	*CCt = (double *)calloc(D * D, sizeof(double));
}

// free_all

void free_all(double *m_beta, double *inv_cov_beta, double *m_U,
	      double *inv_cov_U, double *m_V, double *inv_cov_V, 
	      double *m_var, double *mean,
	      double *mean_U, double *mean_V, double *sum2, double *sum,
	      double *bb, double *CCt)
{
	free(m_beta);
	free(inv_cov_beta);
	free(m_U);
	free(inv_cov_U);
	free(m_V);
	free(inv_cov_V);
	free(m_var);
	free(mean);
	free(mean_U);
	free(mean_V);
	free(sum2);
	free(sum);
	free(bb);
	free(CCt);
}

