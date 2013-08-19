/*
    R_LFMM, file: main_LFMM.c
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
#include <string.h>
#include <time.h>
#include <math.h>
#include "matrix/rand.h"
#include "matrix/matrix.h"
#include "matrix/normalize.h"
#include "matrix/analyse.h"
#include "matrix/inverse.h"
#include "io/io_data_double.h"
#include "io/io_data_float.h"
#include "io/io_tools.h"
#include "LFMM/print.h"
#include "LFMM/data_lfmm.h"
#include "LFMM/generative.h"
#include "LFMM/beta.h"
#include "LFMM/U.h"
#include "LFMM/V.h"
#include "LFMM/error_lfmm.h"
#include "LFMM/thread_var.h"
#include "LFMM/register.h"
#include "LFMM/lfmm.h"
#include "R_LFMM.h"

int main_LFMM(int argc, char *argv[])
{

	// Parameters initialization

	int N = 0;
	int M = 0;
	int D = 2;
	int nD = 0;		// total number of covariable
	int nd = 0;
	int K = 0;
	int burn = 0;
	int Niter = 0;
	int num_thrd = 1;
	int missing_data = 0;
	int g_data = -1;	// TR
	int g_cov = -1;		// TR
	char output_file[512];
	char output_file2[512];
	char input_file[512];
	char cov_file[512];
        char dev_file[512] = "DIC.txt";
	long long seed = -1;

	// temporary variables

	double *beta, *U, *V, *alpha_beta, *zscore;	// beta, U, V
	double *C, *nC;		// covariable
	double alpha_R, alpha_U;

	float *dat;		// data matrix
	int *I = NULL;		// missing value matrix
	double epsilon = 1000;	// hyperprior epsilon

	// print header
	print_head();

	print_options(argc, argv);

	// random initialization
	init_random(&seed);

	// analyse of the command line
	// TODO add seed
	analyse_param(argc, argv, &nD, &nd,
		      &N, &M, &K, &Niter, &burn,
		      &missing_data, output_file, input_file, cov_file, dev_file,
		      &g_data, &g_cov, &num_thrd);

	// print summary of command line
	print_summary(N, M, K, nD, nd, Niter, burn,
		      missing_data, output_file, input_file, cov_file, dev_file,
		      num_thrd);

	// allocate data memory

	//C = (double*)calloc(N*(D-1),sizeof(double));  // (N,(D-1))
	U = (double *)calloc(K * N, sizeof(double));	// (N,K)
	V = (double *)calloc(K * M, sizeof(double));	// (N,K)
	beta = (double *)calloc(D * M, sizeof(double));
	zscore = (double *)calloc(M, sizeof(double));
	alpha_beta = (double *)calloc(D, sizeof(double));
	C = (double *)calloc(N * D, sizeof(double));	// (N,K)

	// read of covariable file
	nC = (double *)calloc(N * nD, sizeof(double));	
	read_data_double(cov_file, N, nD, nC);
	normalize_cov(nC, N, nD);
	printf("Read variable file:\n \t%s\t\tOK.\n\n", cov_file);

	// read of data file
	dat = (float *)calloc(N * M, sizeof(float));
	read_data_float(input_file, N, M, dat);

	// creation on the missing data matrix
	if (missing_data && !g_data) {
		I = (int *)calloc(N * M, sizeof(int));
		create_I(dat, I, N, M);
	}

	if (!nd && nD > 1) {
		printf("WARNING: You launched LFMM command line with several"
		       " covariables. The model will be\n\tlaunched sequentially"
		       " (independently) for each covariable.\n\n");
	}

	printf("Read genotype file:\n \t%s\t\tOK.\n", input_file);

	if (nd) {
		nd = nd - 1;
		printf("\n<<<<\n\t Analyse for covariable %d\n\n", nd + 1);

		modify_C(nC, N, nD, C, nd);

		snprintf(output_file2, sizeof output_file, "%s_%d", output_file,
			 nd + 1);

		lfmm_emcmc(dat, I, C, zscore, beta, U, V, alpha_beta, &alpha_R,
			   &alpha_U, N, M, K, D, epsilon, Niter, burn,
			   missing_data, num_thrd, output_file2, dev_file);
		printf
		    ("\tThe execution for covariable %d worked without error.\n>>>>\n\n",
		     nd + 1);
	} else {
		for (nd = 0; nd < nD; nd++) {
			printf("\n<<<<\n\t Analyse for covariable %d\n\n", nd + 1);
	
			modify_C(nC, N, nD, C, nd);

			snprintf(output_file2, sizeof output_file, "%s_%d", output_file,
				 nd + 1);

			lfmm_emcmc(dat, I, C, zscore, beta, U, V, alpha_beta, &alpha_R,
				   &alpha_U, N, M, K, D, epsilon, Niter, burn,
				   missing_data, num_thrd, output_file2, dev_file);
	
			printf
			    ("\tThe execution for covariable %d worked without error.\n>>>>\n\n",
		     	nd + 1);
		}
	}

	// free memory
	if (missing_data) {
		free(I);
	}
	free(C);
	free(nC);
	free(U);
	free(V);
	free(dat);
	free(alpha_beta);
	free(beta);
	free(zscore);

	return 0;
}
