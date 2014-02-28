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
#include "sNMF/sNMF.h"

#include "R_sNMF.h" 

void R_sNMF (char** R_genotype_file, int* R_K, double* R_alpha, double* R_tol, double* R_percentage,
	int* R_iteration, int* R_seed, int* R_ploidy, int* R_num_proc, 
	char** R_input_file_Q, char** R_output_file_Q, char** R_output_file_G, int* I,
	double *all_ce, double *masked_ce) 
{
	sNMF(	*R_genotype_file,
		*R_K,
		*R_alpha,
		*R_tol,
		*R_percentage,
		*R_iteration,
		(long long) (*R_seed),
		*R_ploidy,
		*R_num_proc,
		*R_input_file_Q,
		*R_output_file_Q,
		*R_output_file_G,
		*I,
		all_ce,
		masked_ce);
}	
/*
	//parameters initialization

	int K = 0;			// number of ancestral populations
	int maxiter = 200;		// max number of iterations
	int num_thrd = 1;		// number of processes	
	double alpha = 100;		// regularization parameter
	double tol = 0.0001;		// tolerance criterion
	char output_file_F[512];	// output file for ancestral allele frequencies
	char output_file_Q[512];	// output file for ancestral admixture coefficents
	char input_file[512];		// input file
	long long seed = -1;			// random seed
	int m = 2; 
	char* tmp_file;	

	print_head_snmf();

	// analyse of the command line
	if (R_genotype_file)
                strcpy(input_file, *R_genotype_file);
        else
                print_error_nmf("option","-g genotype_file",0);

	if (R_K)
		K = *R_K;
	else 
                print_error_nmf("missing",NULL,0);

	if (R_alpha)
		alpha = *R_alpha;
	if (R_tol)
		tol = *R_tol;
	if (R_iteration)
		maxiter = *R_iteration;
	if (R_seed)
		seed = *R_seed;
	if (R_ploidy)
		m = *R_ploidy;
	if (R_num_proc)
		num_thrd = *R_num_proc;

        strcpy(output_file_Q, *R_output_file_Q);
        strcpy(output_file_F, *R_output_file_F);

        sNMF(input_file, K, alpha, tol, maxiter, seed, m, num_thrd, output_file_Q, output_file_F);
}
*/
