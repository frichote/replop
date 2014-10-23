/*
    sNMF_pop, file: main.c
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
#include "../sNMF/register_snmf.h"
#include "../matrix/matrix.h"
#include "../matrix/rand.h"
#include "../matrix/random_projection.h"
#include "../io/io_data_double.h"
#include "../io/io_tools.h"
#include "../createDataSet/createDataSet.h"
#include "../crossEntropy/crossEntropy.h"

void sNMF(char* input_file, int K, double alpha, double tol, double e, int maxiter, 
	long long seed, int m, int num_thrd, char* input_file_Q, char* output_file_Q, 
	char* output_file_F, int I, double *all_ce, double *masked_ce) {
	
	//parameters initialization

	int N = 0;			// number of individuals
	int M = 0;			// number of SNPs
	int Mp = 1000;
	double *Q_res;			// matrix for ancestral admixture coefficients (of size NxK)
	double *F_res;			// matrix for ancestral allele frequencies (of size M x nc xK)
	double *F_I;			// matrix for ancestral allele frequencies (of size M x nc xK)
	double *X;
	double *Xp;
	double *P;
	double like = 0.0;
	char *tmp_file; 
	char data_file[512];

	//  random init
	init_random(&seed);

	// count the number of lines and columns
        M = nb_cols_lfmm(input_file);
        N = nb_lines(input_file, M);

	if (I == -1) 
		I = imin(10000, M/10);
	// write command line summary
        print_summary_snmf(N, M, m, seed, K, alpha, tol, maxiter,	// TODO 
		input_file, num_thrd, e, input_file_Q, output_file_Q, 
		output_file_F, I);

        // write input file name
	if (e) {
	        tmp_file = remove_ext(input_file,'.','/');
                strcpy(data_file, tmp_file);
	        strcat(data_file, "_I.geno");
	        free(tmp_file);
		// create file with masked genotypes
		printf("\n <<<<<< createDataSet program\n\n");
		// createDataSet(input_file, m, -1, e, data_file); TODO
		printf("\n >>>>>>\n\n");
	} else 
                strcpy(data_file,input_file);
	
	// memory allocation
	X = (double *) calloc(N * M, sizeof(double));
        Q_res = (double *) calloc(N * K, sizeof(double));      // of size NxK
        F_res = (double *) calloc(K * Mp, sizeof(double));     // of size McxK

	// read of genotypic data
	read_data_double(data_file, N, M, X);
        printf("Read genotype file %s:\t\tOK.\n\n",input_file);

	// create projected matrix P
	/*
	P = (double *) calloc(M * Mp, sizeof(double));
	Xp = (double *) calloc(N * Mp, sizeof(double));
	create_srp(P, M, Mp);
	// project
	project(X, P, Xp, N, M, Mp);
	*/

	
//	write_data_double("/home/frichote/Xp.txt", N, Mp, Xp); 
	// init with a given matrix Q
	
	if (strcmp(input_file_Q,"")) {
		read_data_double(input_file_Q, N, K, Q_res);	
	// init of Q with a smaller data set
	} else {
		rand_matrix_double(Q_res, N, K);
		/*
		if (I && K > 1) {
			// init subset matrices
			printf("Initialization of Q with a random subset of SNPs:\n");
			Xi = (double *) calloc(N * Mi, sizeof(double));
        		F_I = (double *) calloc(K * Mi, sizeof(double));     // of size McxK
			// select a subset of SNPs
			select_pop_double(X, Xi, N, M);
			// calc init of Q_res
			ALS(Xi, Q_res, F_I, N, Mi, K, maxiter, tol, num_thrd, alpha);
			// free memory
			free(F_I);
			free(Xi);
		} */
	} 

	// parameter estimation
	printf("\nMain algorithm:\n");
	/*
	if (K == 1) 
		ALS_k1(X, Q_res, F_res, N, M, nc, Mp);
	else
	*/
		ALS(X, Q_res, F_res, N, Mp, K, maxiter, tol, num_thrd, alpha);

	// least square estimates
	like = least_square(X, Q_res, F_res, N, Mp, K, alpha); 
	printf("\nLeast-square error: %f\n", like);

	write_data_double(output_file_Q, N, K, Q_res);
       	printf("Write individual ancestry coefficient file %s:"
		"\t\tOK.\n",output_file_Q);

	write_data_double(output_file_F, Mp, K ,F_res);
        printf("Write ancestral allele frequency coefficient file %s:"
		"\tOK.\n",output_file_F);

	if (e) {
		printf("\n <<<<<< crossEntropy program\n\n");
		crossEntropy(input_file, data_file, output_file_Q, 
			output_file_F, K, m, all_ce, masked_ce);	
		printf("\n >>>>>>\n\n");
	}

	//free memory
	free(X);
	free(Xp);
	free(P);
	free(Q_res);
	free(F_res);
}
