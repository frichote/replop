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
#include "../io/print_bar.h"
#include <stdio.h>
#include <stdlib.h>

// lfmm_emcmc

void lfmm_emcmc(float *dat, int *I, double *zscore, 
		double *U, double *V, double *alpha_U, double *alpha_R,
		double *alpha_V, int N, int M, int K, int D,
		double epsilon, int Niter, int burn, int missing_data,
		int num_thrd, char *dev_file)
{
	double *m_beta_V, *inv_cov_beta_V, *m_X_U, *inv_cov_X_U; 
	double *mean_U, *mean_beta_V, *sum2_beta_V, *bb; 
	double *cov_X_U,*mean_cov_X_U;
	int i, j, n, d;
	double deviance = 0;
	double dp = 0;
	double thrd_m2;
	int Kp = K + D;
	double b;

	// allocate memory
	allocate_all(&m_beta_V, &inv_cov_beta_V, &m_X_U, &inv_cov_X_U, 
		     &mean_U, &mean_beta_V, &sum2_beta_V, &bb, 
		     &cov_X_U, &mean_cov_X_U, N, M, K, D);

	printf("\t\tStart of the Gibbs Sampler algorithm.\n\n");

	// init U (not X), V
	rand_matrix_double(&U[D*N], K, N);
	rand_matrix_double(V, Kp, M);

	// init alpha_R
	*alpha_R = update_alpha_R(dat, I, U, V, N, M, Kp, &thrd_m2, 
				  num_thrd, missing_data); 

	// shell print
	init_bar(&i, &j);

	n = 0;
	while (n < Niter) {
		// print shell
		print_bar(&i, &j, Niter);
                printf("%G ",*alpha_R);

		// update_alpha_U
		update_alpha_U(U, alpha_U, 1, K, D, N, M);
		for (d = D; d < K+D; d++) {
                	printf("%G ",alpha_U[d]);
                	alpha_U[d] /= *alpha_R;
		}

		// update_alpha_V
		update_alpha_V(V, alpha_V, 1, D, K, N, M);
		for (d = 0; d < D; d++) {
                	printf("%G ",alpha_V[d]);
                	alpha_V[d] /= *alpha_R;
		}
		printf("\n");

		// update U
		update_U(dat, U, V, m_X_U, inv_cov_X_U, cov_X_U, alpha_U, 
			*alpha_R, M, N, K, D, num_thrd);

		// update V
		update_V(dat, U, V, m_beta_V, inv_cov_beta_V, alpha_V,
			 *alpha_R, M, N, K, D, num_thrd);


		// update alpha_R
		*alpha_R = update_alpha_R(dat, I, U, V, N, M, Kp, &thrd_m2, 
				  	  num_thrd, missing_data); 

		// update sums
		if (n >= burn) {
			update_sums(U, V, cov_X_U, sum2_beta_V, mean_U, 
				    mean_beta_V, mean_cov_X_U, &deviance, 
				    thrd_m2, N, M, K, D, *alpha_R);
		}
		n++;
	}

	final_bar();
	printf("\n");
	printf("\t\tEnd of the Gibbs Sampler algorithm.\n\n");

	// calculate zscore
	zscore_calc(zscore, mean_beta_V, sum2_beta_V, M, Niter - burn, D);

	// check zscore
	if (check_mat(zscore, M, 0, 1))
		print_error_global("nan", NULL, 0);

	// calculate dp and deviance // TODO after zscore_calc
	calc_dp_deviance(dat, U, mean_U, mean_beta_V, mean_cov_X_U, &deviance, 
			I, missing_data, &dp, Niter - burn, N, M, K, D, num_thrd);

	// save ED and DIC
	printf("\tED:%10.10G\t DIC: %10.10G \n\n", deviance, 2 * deviance - dp);
        write_DIC(dev_file,deviance,2*deviance-dp);

	// free memory
	free_all(m_beta_V, inv_cov_beta_V, m_X_U, inv_cov_X_U, mean_U, 
		mean_beta_V, sum2_beta_V, bb, cov_X_U, mean_cov_X_U);
}

// update_sums

void update_sums(double *U, double *V, double *cov_X_U, double *sum2_beta_V,
                 double *mean_U, double *mean_beta_V, double *mean_cov_X_U, double *deviance,
                 double thrd_m2, int N, int M, int K, int D, double alpha_R)
{
	double dv;
	int Kp = K + D;

	update_sum2(V, sum2_beta_V, Kp * M);
	update_sum(&(U[D*N]), mean_U, K * N);
	update_sum(V, mean_beta_V, Kp * M);
	update_sum(cov_X_U, mean_cov_X_U, Kp * Kp);
	dv = thrd_m2 * alpha_R;
	update_sum(&dv, deviance, 1);
}

// update_alpha_R

double update_alpha_R(float* dat, int *I, double *U, double *V, int N, int M,
		      int Kp, double *thrd_m2, int num_thrd, int missing_data) 
{
	double v ;
	if(missing_data)
		 v = var_data_inputation(dat, I, U, V, N, M, Kp, 
			thrd_m2, num_thrd);
	else 
		 v = var_data(dat, U, V, N, M, Kp, thrd_m2, num_thrd);

	return 1.0/v;//rand_gamma(N*M/2, 1.0/ (N*M*v));
	
}

// calc_dp_deviance

void calc_dp_deviance(float *dat, double *U, double *mean_U, double *mean_beta_V,
		      double *mean_cov_X_U, double *deviance, int *I, int missing_data, 
		      double *dp, int size, int N, int M, int K, int D, int num_thrd)
{
	double thrd_m2, tmp;
	int Kp = K + D;
	int i, k;

	update_m(mean_U, K * N, size);
	update_m(mean_beta_V, Kp * M, size);
	update_m(deviance, 1, size);
	update_m(mean_cov_X_U, Kp * Kp, size);

	for (k = 0; k < K; k++) 
		for (i = 0; i < N; i++) 
			U[(k + D) * N + i] = mean_U[k * N + i];

        tmp = 1.0 / update_alpha_R(dat, I, U, mean_beta_V, N, M, Kp, &thrd_m2, 
		num_thrd, missing_data); 
	//tmp = var_data(dat, U, mean_beta_V, N, M, Kp, &thrd_m2, num_thrd);
	*dp = thrd_m2 / tmp;
}

// allocate_all

void allocate_all(double **m_beta_V, double **inv_cov_beta_V, double **m_X_U,
		  double **inv_cov_X_U, double **mean_U, double **mean_beta_V, 
		  double **sum2_beta_V, double **bb, 
		  double **cov_X_U, double **mean_cov_X_U, int N, int M, int K, int D)
{
	int Dp = D + K;
	*m_beta_V = (double *) malloc(Dp * M * sizeof(double));
	*inv_cov_beta_V = (double *) malloc(Dp * Dp * sizeof(double));
	*m_X_U = (double *) malloc(Dp * N * sizeof(double));
	*inv_cov_X_U = (double *) malloc(Dp * Dp * sizeof(double));

	*mean_U = (double *)calloc(K * N, sizeof(double));
	*mean_beta_V = (double *)calloc(Dp * M, sizeof(double));
	*sum2_beta_V = (double *)calloc(Dp * M, sizeof(double));
	*bb = (double *)calloc(D, sizeof(double));
	*cov_X_U = (double *)calloc(Dp * Dp, sizeof(double));
	*mean_cov_X_U = (double *)calloc(Dp * Dp, sizeof(double));
}

// free_all

void free_all(double *m_beta_V, double *inv_cov_beta_V, double *m_X_U,
		  double *inv_cov_X_U, double *mean_U, double *mean_beta_V, 
		  double *sum2_beta_V, double *bb, double *cov_X_U, double *mean_cov_X_U)
{
	free(m_beta_V);
	free(inv_cov_beta_V);
	free(m_X_U);
	free(inv_cov_X_U);
	free(mean_U);
	free(mean_beta_V);
	free(sum2_beta_V);
	free(bb);
	free(cov_X_U);
	free(mean_cov_X_U);
}
