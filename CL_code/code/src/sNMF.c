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
#include "sNMF/als.h"
#include "sNMF/criteria.h"
#include "sNMF/print_snmf.h"
#include "sNMF/data_snmf.h"
#include "sNMF/register_snmf.h"
#include "matrix/matrix.h"
#include "matrix/error.h"
#include "matrix/rand.h"
#include "io/io_data_double.h"
#include "io/io_tools.h"
#include "bituint/io_geno_bituint.h"
#include "bituint/bituint.h"

int main (int argc, char *argv[]) {
	
	//parameters initialization

	int N = 0;			// number of individuals
	int M = 0;			// number of SNPs
	int K = 0;			// number of ancestral populations
	int maxiter = 1000;		// max number of iterations
	int num_thrd = 1;		// number of processes	
	double alpha = 100;		// regularization parameter
	double tol = 0.0001;		// tolerance criterion
	char output_file_F[512];	// output file for ancestral allele frequencies
	char output_file_Q[512];	// output file for ancestral admixture coefficents
	char input_file[512];		// input file
	double *Q_res;			// matrix for ancestral admixture coefficients (of size NxK)
	double *F_res;			// matrix for ancestral allele frequencies (of size M x nc xK)
	int Mc;				// size of memory allocation for one individual
	bituint* X;			// data matrix
	int Mp;				// ???
	int nc = 3;			// ploidy, 3 if 0,1,2 , 2 if 0,1 (number of factors)
	long long seed = -1;			// random seed
	int m = 0; 
	double like = 0.0;
	char* tmp_file;	

	print_head_snmf();

	// analyse of the command line
	analyse_param_snmf(argc,argv, &m, &seed,
                       	&K, &alpha, &tol, &maxiter,
                        input_file, &num_thrd);
	
	// fix the number of possible factors 
	if (m)
		nc = nc + 1;
	else 
		m = 2;

	//  random init
	init_random(&seed);

	// count the number of lines and columns
	N = nb_cols(input_file);
	M = nb_lines(input_file, N);

	// write command line summary
        print_summary_snmf(N, M, m, seed, K, alpha, tol, maxiter, input_file, num_thrd);

	// memory allocation
	Mc = nc*M;
	init_mat_bituint(&X,N,Mc,&Mp);
        Q_res = (double *) calloc(N*K,sizeof(double));      // of size NxK
        F_res = (double *) calloc(K*Mc,sizeof(double));     // of size McxK

	// read of genotypic data
	read_geno_bituint(input_file, N, M, Mp, nc, X);
        printf("Read genotype file %s:\t\tOK.\n\n",input_file);

	// parameter estimation
	ALS(X, Q_res, F_res, N, M, nc, Mp, K, maxiter, tol, num_thrd, alpha);

	// least square estimates
	like = least_square(X, Q_res, F_res, N, M, nc, Mp, K, alpha); 
	printf("\n\nLeast-square error: %f\n\n", like);

	// write of the results 
	tmp_file = remove_ext(input_file,'.','/');

	strcpy(output_file_F,tmp_file);
	strcpy(output_file_Q,tmp_file);
	strcat(output_file_F,".F");
	strcat(output_file_Q,".Q");

	free(tmp_file);

	write_data_double(output_file_Q, N, K, Q_res);
       	printf("Write individual ancestry coefficient file %s:\t\tOK.\n\n",output_file_Q);

	write_data_double(output_file_F, Mc, K ,F_res);
        printf("Write ancestral allele frequency coefficient file %s:\tOK.\n\n",output_file_F);

	//free memory
	free(X);
	free(Q_res);
	free(F_res);

	return 0;
}
