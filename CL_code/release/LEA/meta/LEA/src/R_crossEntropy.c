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
#include "crossEntropy/crossEntropy.h"

#include "R_crossEntropy.h" 

void R_crossEntropy (char** R_genotype_file, char** R_missing_data_file, char** R_Q_file, 
	char** R_F_file, int* R_K, int* R_ploidy, double* all_ce, double *masked_ce) 
{
        crossEntropy(	*R_genotype_file, 
			*R_missing_data_file, 
			*R_Q_file, 
			*R_F_file,
			*R_K,
			*R_ploidy,
			all_ce,
			masked_ce);
}
/*
        //parameters initialization

	int K = 0;				// number of ancestral populations
	char input_file_F[512] = "";	 	// input file for ancestral allele frequencies
	char input_file_Q[512] = "";		// input file for ancestral admixture coefficients
	char input_file_I[512] = "";		// input file with missing data	
	char input_file[512] = "";		// input file "without" missing data 
	double all_ce, missing_ce;
	int m = 2;

	print_head_snmf();

	// analyse of the command line
        if (R_K)
                K = *R_K;
        if (R_ploidy)
                m = *R_ploidy;

        if (R_genotype_file)
                strcpy(input_file, *R_genotype_file);
        else
                print_error_cds("option","-g genotype_file");

        strcpy(input_file_I, *R_missing_data_file);
        strcpy(input_file_F, *R_F_file);
        strcpy(input_file_Q, *R_Q_file);

        crossEntropy(input_file, input_file_I, input_file_Q, input_file_F, K, m, &all_ce, &missing_ce);
}
*/
