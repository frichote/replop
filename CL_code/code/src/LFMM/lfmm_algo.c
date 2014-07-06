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

void lfmm_emcmc(LFMM_param param)
{
	// GS structure allocation
	LFMM_GS_param GS_param = (LFMM_GS_param) calloc(1, sizeof(lfmm_GS_param));
	
	// temporary parameters
	int i, j, n;
	double deviance = 0;
	double dp = 0;
	GS_param->thrd_m2 = 0;
	int N = param->n;
	int M = param->L;
	int D = param->mD;
	int K = param->K;

	// allocate memory
	allocate_all(GS_param, N, M, K, D);

	printf("\t\tStart of the Gibbs Sampler algorithm.\n\n");

	// init U, V and beta
	if (param->init) {
		rand_matrix_double(param->beta, D, M);
		rand_matrix_double(param->U, K, N);
		rand_matrix_double(param->V, K, M);
	} else {
		zeros(param->beta, D*M);
		zeros(param->U, K*N);
		zeros(param->V, K*M);
	}

	// update alpha_R
	param->alpha_R = update_alpha_R (param, GS_param);

	// shell print
	init_bar(&i, &j);

	n = 0;
	while (n < param->Niter) {
		// print shell
		print_bar(&i, &j, param->Niter);

		// update_alpha_U
		update_alpha_U(param);

		// update_alpha_beta
		update_alpha_beta(param);

		// update_beta
		update_beta(param, GS_param); 

		// update U
		update_U(param, GS_param);

		// update V
		update_V(param, GS_param);

		// update alpha_R
		param->alpha_R = update_alpha_R (param, GS_param);

		// update sums
		if (n >= param->burn) 
			update_sums(param, GS_param);
		n++;
	}
	final_bar();
	printf("\n");
	printf("\t\tEnd of the Gibbs Sampler algorithm.\n\n");

	// calculate zscore
	zscore_calc(param->zscore, GS_param->sum, GS_param->sum2, param->L, 
		param->Niter - param->burn, param->mD);

	// check zscore
	if (check_mat(param->zscore, param->L, 0, 1))
		print_error_global("nan", NULL, 0);

	// calculate dp and deviance
	calc_dp_deviance(param, GS_param, &deviance, &dp);

	// save ED and DIC
	param->dev = deviance;
	param->DIC = 2 * deviance - dp;
	printf("\tED:%10.10G\t DIC: %10.10G \n\n", deviance, 2 * deviance - dp);

	// free memory
	free_all(GS_param);
	free(GS_param);
}

// update_sums

void update_sums(LFMM_param param, LFMM_GS_param GS_param)
{
	double dv;
	int D = param->mD;
	int M = param->L;
	int N = param->n;
	int K = param->K;

	// sum beta
	update_sum(param->beta, GS_param->sum, D * M);
	// sum squares beta
	update_sum2(param->beta, GS_param->sum2, D * M);
	// sum U
	update_sum(param->U, GS_param->mean_U, K * N);
	// sum V
	update_sum(param->V, GS_param->mean_V, K * M);
	dv = GS_param->thrd_m2 * param->alpha_R;
	// sum devince
	update_sum(&dv, &(param->dev), 1);
}

// calc_dp_deviance

void calc_dp_deviance(LFMM_param param, LFMM_GS_param GS_param, 
		      double *deviance, double *dp) 
{
	double tmp;
	double size = param->Niter - param->burn;
	int D = param->mD;
	int M = param->L;
	int N = param->n;
	int K = param->K;

	update_m(GS_param->sum, D * M, size);
	update_m(GS_param->mean_U, K * N, size);
	update_m(GS_param->mean_V, K * M, size);
	update_m(&(param->dev), 1, size);
	tmp = var_data(param, GS_param);

	*dp = GS_param->thrd_m2 / tmp;
	*deviance = param->dev;
}

// allocate_all

void allocate_all(LFMM_GS_param GS_param, int N, int M, int K, int D) 
{
	GS_param->m_beta = (double *) malloc(D * M * sizeof(double));
	GS_param->inv_cov_beta = (double *) malloc(D * D * sizeof(double));
	GS_param->m_U = (double *) malloc(K * N * sizeof(double));
	GS_param->inv_cov_U = (double *) malloc(K * K * sizeof(double));
	GS_param->m_V = (double *) malloc(K * M * sizeof(double));
	GS_param->inv_cov_V = (double *) malloc(K * K * sizeof(double));

	GS_param->mean_U = (double *)calloc(K * N, sizeof(double));
	GS_param->mean_V = (double *)calloc(K * M, sizeof(double));
	GS_param->sum = (double *)calloc(D * M, sizeof(double));
	GS_param->sum2 = (double *)calloc(D * M, sizeof(double));
}

// free_all

void free_all(LFMM_GS_param GS_param)
{
	free(GS_param->m_beta);
	free(GS_param->inv_cov_beta);
	free(GS_param->m_U);
	free(GS_param->inv_cov_U);
	free(GS_param->m_V);
	free(GS_param->inv_cov_V);
	free(GS_param->mean_U);
	free(GS_param->mean_V);
	free(GS_param->sum2);
	free(GS_param->sum);
}

// update_alpha_R

double update_alpha_R(LFMM_param param, LFMM_GS_param GS_param)
{
	/*
	if(param->missing_data)
		return 1.0 / var_data_inputation(param, GS_param);
	else 
	*/
	return 1.0 / var_data(param, GS_param);
}
