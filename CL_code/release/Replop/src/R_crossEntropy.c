/*
   crossEntropy, file: R_crossEntropy.c
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

#define SEP " "

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "io/io_data_double.h"
#include "io/io_tools.h"
#include "io/io_error.h"
#include "sNMF/print.h"
#include "crossEntropy/register_ce.h"
#include "crossEntropy/print_ce.h"
#include "matrix/error.h"
#include "R_crossEntropy.h"

int main_crossEntropy (int argc, char *argv[]) {

        //parameters initialization

	int N = 0;			// number of individuals
	int M = 0;			// number of SNPs	
	int K = 0;			// number of ancestral populations
	char input_file_F[512];	 	// input file for ancestral allele frequencies
	char input_file_Q[512];		// input file for ancestral admixture coefficients
	char input_file_I[512];		// input file with missing data	
	char input_file[512];		// input file "without" missing data 
	double *Q;			// matrix for ancestral admixture coefficients (of size NxK)
	double *F;			// matrix for ancestral allele frequencies (of size M x nc xK)
	int* X;				// data matrix "without" missing data 
	int* I;				// data matrix with missing data
	int nc = 3;			// ploidy, 3 if 0,1,2 , 2 if 0,1 (number of factors)

	// local parameters 
	long double iE, aE;
	long double *qfc;
	int i, j, k, n;
	long int naE, niE;

	// local parameters to read files
        FILE *m_File = NULL;
        FILE *m_FileI = NULL;
        char token;
	char *tmp_file;

	int m = 0;

	print_head();

	// analyse of the command line
	analyse_param_ce(argc,argv, &m, &K, input_file);

        // fix the number of possible factors 
        if (m)
                nc = nc + 1;
	else 
		m = 2;

        // count the number of lines and columns
        N = nb_cols(input_file);
        M = nb_lines(input_file, N);

        // write output file names
        tmp_file = remove_ext(input_file,'.','/');

	strcpy(input_file_F,tmp_file);
	strcpy(input_file_Q,tmp_file);
	strcpy(input_file_I,tmp_file);
	strcat(input_file_F,"_I.F");
	strcat(input_file_Q,"_I.Q");
	strcat(input_file_I,"_I.geno");

	free(tmp_file);

        // write command line summary
	print_summary_ce(N, M, K, m, input_file);

	// memory allocation
	qfc = (long double *) calloc(nc,sizeof(long double));
	X = (int *) calloc(N,sizeof(int));
	I = (int *)calloc(N,sizeof(int));

	// read of Q and F
	Q = (double *) calloc(N*K,sizeof(double));    
	read_data_double(input_file_Q,N,K,Q); 
	F = (double *) calloc(K*nc*M,sizeof(double));  
	read_data_double(input_file_F,nc*M,K,F);

	// open files 
        m_File = fopen(input_file, "r");
        m_FileI = fopen(input_file_I, "r");

        if (!m_File)
        	print_error_global("open", input_file, 0);
        if (!m_FileI)
        	print_error_global("open", input_file_I, 0);

	// read line by line and compute criterions
        j = 0;
	iE = 0.0;
	aE = 0.0; 
	naE = 0;
	niE = 0;
	while (!feof(m_File) & (j < M)) {

		// read of the X line
                i = 0;
                token = (char)fgetc(m_File);
               	while(token != EOF && token != '\n' && i<N) {
		         X[i] = (int)(token - '0');
                         token = (char)fgetc(m_File);
                         i++;
                }
		// test the number of columns
		test_column(input_file, m_File, i, j, N, &token);
		
		// read of I line
                i = 0;
                token = (char)fgetc(m_FileI);
               	while(token != EOF && token != '\n' && i<N) {
		         I[i] = (int)(token - '0');
                         token = (char)fgetc(m_FileI);
                         i++;
                }
		// test the number of columns
		test_column(input_file_I, m_FileI, i, j, N, &token);

		// for this line criterion
		for (i = 0; i < N; i++) {
			for (n = 0; n < nc; n++) 
                               	qfc[n] = 0.0;
			// if not real missing data
			if (X[i] != 9) {
				// calculate prediction
				for (k = 0; k < K; k++) {
					for (n = 0; n < nc; n++) 
                                        	qfc[n] += Q[i*K+k]*F[(nc*j+n)*K+k];
				}
				// calculate CE
				if (I[i] != 9) {
					for (n = 0; n < nc; n++) {
						if (X[i] == n)
							aE += -log(qfc[n]);
					}
					naE ++;
				} else if (I[i] == 9) {
					for (n = 0; n < nc; n++) {
						if (X[i] == n)
							iE += -log(qfc[n]);
					}
					niE ++;
				}
			}
		}
                j++;
	} 
	// check the number of lines
	test_line(input_file, m_File, j, M);
	test_line(input_file_I, m_FileI, j, M);

	// print output
	printf("Cross-Entropy (all data):\t %G\n",(double)(aE/naE));
	if (niE)
		printf("Cross-Entropy (missing data):\t %G\n",(double)(iE/niE));

	// close file
        fclose(m_File);
        fclose(m_FileI);

	//free memory
	free(Q);
	free(F);
	free(I);
	free(qfc);
	free(X);

	return 0;
}

