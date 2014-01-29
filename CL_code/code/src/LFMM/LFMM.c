/*
    LFMM, file: LFMM.c
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
#include "../matrix/rand.h"
#include "../matrix/matrix.h"
#include "../matrix/normalize.h"
#include "../matrix/inverse.h"
#include "../io/io_data_double.h"
#include "../io/io_data_float.h"
#include "../io/io_tools.h"
#include "print_lfmm.h"
#include "data_lfmm.h"
#include "beta.h"
#include "U.h"
#include "V.h"
#include "error_lfmm.h"
#include "register_lfmm.h"
#include "lfmm_algo.h"

void LFMM(char* input_file, char* output_file, char* cov_file, char* dev_file,
	int nd, int K, int Niter, int burn, int num_thrd, long long seed, 
	int missing_data, int all)
{

	// Parameters initialization
	int N = 0, N2;
	int M = 0;
	int D = 2;
	int nD = 0;		// total number of covariable

	// temporary variables
	double *beta, *U, *V, *alpha_beta, *zscore;	// beta, U, V
	double *C, *nC;		// covariable
	double alpha_R, alpha_U;

	float *dat;		// data matrix
	int *I = NULL;		// missing value matrix
	double epsilon = 1000;	// hyperprior epsilon

	// random initialization
	init_random(&seed);

        // count the number of lines and columns
        M = nb_cols_lfmm(input_file);
        N = nb_lines(input_file, M);

        nD = nb_cols_lfmm(cov_file);
        N2 = nb_lines(cov_file, nD);

	// check the number of lines and columns
	if (N2 != N) {
		printf("The number of individuals of %s (%d) is different from the number"
			" of individuals of %s (%d)\n",input_file, N, cov_file, N2);
		exit(1);
	}

	if (nd && (nd < 1 || nd > nD))
                print_error_lfmm("specific",
                                 "(-d option). d should be between 1 and D",
                                 0);

	// print summary of command line
	print_summary_lfmm(N, M, K, nD, nd, Niter, burn,
		      missing_data, output_file, input_file, cov_file, dev_file,
		      num_thrd, seed, all);

	// allocate data memory
	U = (double *)calloc(K * N, sizeof(double));	// (N,K)
	V = (double *)calloc(K * M, sizeof(double));	// (N,K)
	beta = (double *)calloc(D * M, sizeof(double));
	alpha_beta = (double *)calloc(D, sizeof(double));

	// read of covariable file
	nC = (double *)calloc(N * nD, sizeof(double));	
	read_data_double(cov_file, N, nD, nC);
	normalize_cov(nC, N, nD);
	printf("Read variable file:\n \t%s\t\tOK.\n\n", cov_file);

	// read of data file
	dat = (float *)calloc(N * M, sizeof(float));
	read_data_float(input_file, N, M, dat);

	// creation on the missing data matrix
	if (missing_data) {
		I = (int *)calloc(N * M, sizeof(int));
		create_I(dat, I, N, M);
	}

	// warnings about the covariables
	if (all) {
		printf("WARNING: You launched LFMM command line with several"
		       " covariables with '-a' option."
		       " The model will be\n\tlaunched with all covariables at the same time.\n\n");
	} else if (!nd && nD > 1) {
		printf("WARNING: You launched LFMM command line with several"
		       " covariables. The model will be\n\tlaunched sequentially"
		       " (independently) for each covariable.\n\n");
	}

	printf("Read genotype file:\n \t%s\t\tOK.\n", input_file);

	// all covariables at the same time
	if (all) {
		// allocate memory
		D = nD + 1;
		zscore = (double *)calloc(M * nD, sizeof(double));
		C = (double *)calloc(N * D, sizeof(double));	// (N,K)

		printf("\n<<<<\n\t Analyse for all covariables.\n\n");
		// create C
		modify_C(nC, N, nD, C, nd, all);

		// run LFMM
		lfmm_emcmc(dat, I, C, zscore, beta, U, V, alpha_beta, &alpha_R,
			   &alpha_U, N, M, K, D, epsilon, Niter, burn,
			   missing_data, num_thrd, dev_file);

		// write zscore
	        write_zscore_double(output_file, M, zscore, D-1, 1, 0, K);
		printf("\tThe execution for all covariables worked without error.\n>>>>\n\n");

	// only with covariable nd
	} else if (nd) {
		// allocate memory
		zscore = (double *)calloc(M, sizeof(double));
		C = (double *)calloc(N * D, sizeof(double));	// (N,K)
		nd = nd - 1;

		printf("\n<<<<\n\t Analyse for covariable %d\n\n", nd + 1);
		// create C
		modify_C(nC, N, nD, C, nd, all);

		// run LFMM
		lfmm_emcmc(dat, I, C, zscore, beta, U, V, alpha_beta, &alpha_R,
			   &alpha_U, N, M, K, D, epsilon, Niter, burn,
			   missing_data, num_thrd, dev_file);

		// write zscore
	        write_zscore_double(output_file, M, zscore, 1, 0, 0, K);
		printf("\tThe execution for covariable %d worked without error."
			"\n>>>>\n\n", nd + 1);

	// each covariable sequentially
	} else {
		// allocate memory
		zscore = (double *)calloc(M, sizeof(double));
		C = (double *)calloc(N * D, sizeof(double));	// (N,K)
		// for each variable
		for (nd = 0; nd < nD; nd++) {
			printf("\n<<<<\n\t Analyse for covariable %d\n\n", nd + 1);
			// create C
			modify_C(nC, N, nD, C, nd, all);

			// run LFMM
			lfmm_emcmc(dat, I, C, zscore, beta, U, V, alpha_beta, &alpha_R,
				   &alpha_U, N, M, K, D, epsilon, Niter, burn,
				   missing_data, num_thrd, dev_file);
	
			// write zscore
	        	write_zscore_double(output_file, M, zscore, 1, 0, nd, K);
			printf("\tThe execution for covariable %d worked without error."
				"\n>>>>\n\n", nd + 1);
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
}
