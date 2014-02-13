/*
    pca, file: main.c
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

#include "../io/io_tools.h"
#include "../io/io_data_double.h"
#include "calc_cov.h"
#include "print_pca.h"
#include "../matrix/normalize.h"
#include "../matrix/diagonalize.h"

void pca(char* input_file, char *output_eva_file, char *output_eve_file, 
	int K, int c, int s)
{
        double *data;
	double *cov, *val, *vect;
	int N, M, tmp;

        // number of lines and columns
        M = nb_cols_lfmm(input_file);
        N = nb_lines(input_file, M);

	// correct K
	if (N < M)
		tmp = N;
	else 
		tmp = M;
	if (!K || K > tmp)
		K = tmp;

        // print command line summary
	print_summary_pca(N, M, K, c, s, input_file, output_eva_file, 
		output_eve_file);

	// allocate memory 
	data = (double *) malloc(N * M * sizeof(double));
	cov = (double *) malloc(N * N * sizeof(double));
	val = (double *) malloc(N * sizeof(double));
	vect = (double *) malloc(N * N * sizeof(double));
	
	// read input_file
	read_data_double(input_file, N, M, data);

	printf("%d %d\n",c,s);
	// scale
	if (s)
		normalize_cov_I(data, N, M);
	else if (c)
		normalize_mean_I(data, N, M);

	// calculate covariance matrix
	calc_cov(data, N, M, cov); 

	write_data_double("cov.txt",N, N, cov);

	// calculate eva and eve
	diagonalize(cov, N, K, val, vect);

	// write output
	write_data_double(output_eva_file, K, 1, val);
	write_data_double(output_eve_file, N, K, vect);

	// free memory
	free(data);
	free(cov);
	free(val);
	free(vect);
}
