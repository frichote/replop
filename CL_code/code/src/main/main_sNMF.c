/*
    sNMF, file: main_sNMF.c
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
#include <string.h>
#include <time.h>
#include "../sNMF/sNMF.h"
#include "../sNMF/register_snmf.h"
#include "../sNMF/print_snmf.h"
#include "../io/io_tools.h"

int main (int argc, char *argv[]) {
	
	//parameters initialization
	int K = 0;			// number of ancestral populations
	int maxiter = 200;		// max number of iterations
	int num_thrd = 1;		// number of processes	
	double alpha = 10;		// regularization parameter
	double tol = 0.0001;		// tolerance criterion
	char output_file_F[512] = "";	// output file for ancestral allele frequencies
	char output_file_Q[512] = "";	// output file for ancestral admixture coefficents
	char input_file_Q[512] = "";	// input file for ancestral admixture coefficents
	char input_file[512];		// input file
	long long seed = -1;			// random seed
	int m = 2; 
	double e = 0.0;
	int I = 0;
	double all_ce = 0, masked_ce = 0;

	print_head_snmf();

	print_options(argc, argv);

	// analyse of the command line
	analyse_param_snmf(argc,argv, &m, &seed,
                       	&K, &alpha, &tol, &e, &maxiter,
                        input_file, &num_thrd, input_file_Q,
			output_file_Q, output_file_F, &I);

	// run function
	sNMF(input_file, K, alpha, tol, e, maxiter, seed, m, num_thrd, 
		input_file_Q, output_file_Q, output_file_F, I,
		&all_ce, &masked_ce);

	return 0;
}
