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

void sNMF(sNMF_param param) 
{	
	//parameters initialization
	
/*
	int N = 0;			// number of individuals
	int M = 0;			// number of SNPs
	double *Q_res;			// matrix for ancestral admixture coefficients (of size NxK)
	double *F_res;			// matrix for ancestral allele frequencies (of size M x nc xK)
	double *F_I;			// matrix for ancestral allele frequencies (of size M x nc xK)
	int Mc, Mci;				// size of memory allocation for one individual
	int Mp, Mi, Mpi;				// ???
*/

	// temporary variables
	double like = 0.0;
        int K = param->K;
        int n = param->n;
        int L = param->L;
	char *tmp_file; 
	int Mc, Mci, Mp, Mi;
	bituint* X;

	//  random init
	init_random(&(param->seed));

	// fix the number of possible factors 
	if (param->m)
		param->nc = param->m + 1;
	else 
		param->m = 2;

	// count the number of lines and columns
	param->n = nb_cols_geno(param->input_file);
	param->L = nb_lines(param->input_file, param->n);

	n = param->n;
	L = param->L;
	param->Mc = param->L * param->nc;
	// memory allocation
	param->temp1 = calloc(K * K, sizeof(double));
	param->tempQ = calloc(n * K, sizeof(double));
	param->temp3 = calloc(n * K, sizeof(double));
	param->Y = calloc(K * n, sizeof(double));

	if (param->I == -1) 
		param->I = imin(10000, L/10);
	// write command line summary
        print_summary_snmf(param); 

        // write input file name
	if (param->pourcentage) {
	        tmp_file = remove_ext(param->input_file,'.','/');
                strcpy(param->data_file, tmp_file);
	        strcat(param->data_file, "_I.geno");
	        free(tmp_file);
		// create file with masked genotypes
		printf("\n <<<<<< createDataSet program\n\n");
		createDataSet(param->input_file, param->m, param->pourcentage, 
			param->data_file);
		printf("\n >>>>>>\n\n");
	} else 
                strcpy(param->data_file, param->input_file);
	
	// memory allocation
	Mc = param->nc*L;
	init_mat_bituint(&(param->X), n, Mc, &(param->Mp));
        param->Q = (double *) calloc(n * K, sizeof(double));      // of size NxK

	// read of genotypic data
	read_geno_bituint(param->data_file, n, L, param->Mp, param->nc, param->X);
        printf("Read genotype file %s:\t\tOK.\n\n",param->input_file);

	
	// init with a given matrix Q
	if (strcmp(param->input_file_Q,"")) {
		read_data_double(param->input_file_Q, n, K, param->Q);	
	// init of Q with a smaller data set
	} else {
		rand_matrix_double(param->Q, n, K);
		if (param->I && K > 1) {
			// save X
			Mp = param->Mp;
			X = param->X;
			// init subset matrices
			printf("Initialization of Q with a random subset of SNPs:\n");
			Mci = param->nc * Mi;
			init_mat_bituint(&(param->X), n, Mci, &(param->Mp));
        		//F = (double *) calloc(K * Mci, sizeof(double));     // of size McxK
			// select a subset of SNPs
			select_geno_bituint(X, param->X, n, L, Mi, param->nc, param->Mp, Mp);
			// calc init of Q_res
			ALS(param);
			// free memory
			free(param->F);
			free(param->X);
			// put back X
			param->X = X;
			param->Mp = Mp;
		}
	} 

	// memory allocation
        param->F = (double *) calloc(K * Mc, sizeof(double));     // of size McxK

	// parameter estimation
	printf("\nMain algorithm:\n");
	if (K == 1) 
		ALS_k1(param);
	else
		ALS(param);

	// least square estimates
	like = least_square(param); 
	printf("\nLeast-square error: %f\n", like);

	// write Q
	write_data_double(param->output_file_Q, n, K, param->Q);
       	printf("Write individual ancestry coefficient file %s:"
		"\t\tOK.\n",param->output_file_Q);

	// write F
	write_data_double(param->output_file_F, Mc, K ,param->F);
        printf("Write ancestral allele frequency coefficient file %s:"
		"\tOK.\n",param->output_file_F);

	// cross-entropy
	if (param->pourcentage) {
		printf("\n <<<<<< crossEntropy program\n\n");
		crossEntropy(param->input_file, param->data_file, param->output_file_Q, 
		param->output_file_F, K, param->m, &(param->all_ce), &(param->masked_ce));	
		printf("\n >>>>>>\n\n");
	}
}
