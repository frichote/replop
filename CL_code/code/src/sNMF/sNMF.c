/*
    NMF, file: main.c
    Copyright (C) 2013 François Mathieu, Eric Frichot

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


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "als.h"
#include "als_k1.h"
#include "criteria.h"
#include "print_snmf.h"
#include "register_snmf.h"
#include "../matrix/matrix.h"
#include "../matrix/rand.h"
#include "../io/io_data_double.h"
#include "../io/io_tools.h"
#include "../bituint/io_geno_bituint.h"
#include "../bituint/bituint.h"
#include "../createDataSet/createDataSet.h"
#include "../crossEntropy/crossEntropy.h"

void sNMF(char* input_file, int K, double alpha, double tol, double e, int maxiter, 
	long long seed, int m, int num_thrd, char* output_file_Q, char* output_file_F, int I) {
	
	//parameters initialization

	int N = 0;			// number of individuals
	int M = 0;			// number of SNPs
	double *Q_res;			// matrix for ancestral admixture coefficients (of size NxK)
	double *F_res;			// matrix for ancestral allele frequencies (of size M x nc xK)
	double *F_I;			// matrix for ancestral allele frequencies (of size M x nc xK)
	int Mc, Mci;				// size of memory allocation for one individual
	bituint* X;			// data matrix
	bituint* Xi;			// data matrix
	int Mp, Mi, Mpi;				// ???
	int nc = 3;			// ploidy, 3 if 0,1,2 , 2 if 0,1 (number of factors)
	double like = 0.0;
	char *tmp_file; 
	char data_file[512];
	double all_ce, missing_ce;

	//  random init
	init_random(&seed);

	// fix the number of possible factors 
	if (m)
		nc = m + 1;
	else 
		m = 2;

	// count the number of lines and columns
	N = nb_cols_geno(input_file);
	M = nb_lines(input_file, N);

	// write command line summary
        print_summary_snmf(N, M, m, seed, K, alpha, tol, maxiter, 
		input_file, num_thrd, e, output_file_Q, output_file_F, I);

        // write input file name
	if (e) {
	        tmp_file = remove_ext(input_file,'.','/');
                strcpy(data_file, tmp_file);
	        strcat(data_file, "_I.geno");
	        free(tmp_file);
		// create file with masked genotypes
		printf("\n <<<<<< createDataSet program\n\n");
		createDataSet(input_file, m, -1, e, data_file);
		printf("\n >>>>>>\n\n");
	} else 
                strcpy(data_file,input_file);
	
	// memory allocation
	Mc = nc*M;
	init_mat_bituint(&X,N,Mc,&Mp);
        Q_res = (double *) calloc(N*K,sizeof(double));      // of size NxK
        F_res = (double *) calloc(K*Mc,sizeof(double));     // of size McxK

	// read of genotypic data
	read_geno_bituint(data_file, N, M, Mp, nc, X);
        printf("Read genotype file %s:\t\tOK.\n\n",input_file);

	
	// init of Q with a smaller data set
	rand_matrix_double(Q_res, N, K);
	if (I && K > 1 && M >= 1000) {
		// init subset matrices
		if (I == -1)
			Mi = imin(1000, M/10);
		printf("Initialization of Q with a random subset of SNPs:\n",Mi);
		Mci = nc * Mi;
		init_mat_bituint(&Xi, N, Mci, &Mpi);
        	F_I = (double *) calloc(K * Mci, sizeof(double));     // of size McxK
		// select a subset of SNPs
		select_geno_bituint(X, Xi, N, M, Mi, nc, Mpi, Mp);
		// calc init of Q_res
		ALS(Xi, Q_res, F_I, N, Mi, nc, Mpi, K, maxiter, tol, num_thrd, alpha);
		// free memory
		free(F_I);
		free(Xi);
	} 

	// parameter estimation
	printf("\nMain algorithm:\n",Mi);
	if (K == 1) 
		ALS_k1(X, Q_res, F_res, N, M, nc, Mp);
	else
		ALS(X, Q_res, F_res, N, M, nc, Mp, K, maxiter, tol, num_thrd, alpha);

	// least square estimates
	like = least_square(X, Q_res, F_res, N, M, nc, Mp, K, alpha); 
	printf("\nLeast-square error: %f\n", like);

	write_data_double(output_file_Q, N, K, Q_res);
       	printf("Write individual ancestry coefficient file %s:"
		"\t\tOK.\n",output_file_Q);

	write_data_double(output_file_F, Mc, K ,F_res);
        printf("Write ancestral allele frequency coefficient file %s:"
		"\tOK.\n",output_file_F);

	if (e) {
		printf("\n <<<<<< crossEntropy program\n\n");
		crossEntropy(input_file, data_file, output_file_Q, 
			output_file_F, K, m, &all_ce, &missing_ce);	
		printf("\n >>>>>>\n\n");
	}

	//free memory
	free(X);
	free(Q_res);
	free(F_res);
}
