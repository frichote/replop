/*
   LFMM, file: lfmm_k0.c
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

#include "print_lfmm.h"
#include "lfmm_k0.h"
#include "data_lfmm.h"
#include "print_lfmm.h"
#include "error_lfmm.h"
#include "beta_k0.h"
#include "../matrix/matrix.h"
#include "../matrix/normalize.h"
#include "beta.h"
#include <stdio.h>
#include <stdlib.h>

// lfmm_emcmc

void lfmm_k0(float *dat, int *I, double *C, double *zscore, double *beta,
		int N, int M, int D, int missing_data, double *perc_var)
{
	double *var_beta;
	double *CCt;
	int d;

	// allocate memory
	var_beta = (double *) malloc(D * M * sizeof(double));
	CCt = (double *)calloc(D * D, sizeof(double));

	// input missing dat
	if (missing_data)
		inputation_freq(dat, I, N, M);

	// calculate C C^t
	create_CCt(CCt, C, D, N);

	// calculate E[beta] and var[beta] 
	calc_beta_k0(C, dat, beta, CCt, var_beta, M, N, D, &(perc_var[0]));

	// calculate zscore
	zscore_calc_k0(zscore, beta, var_beta, D, M);

	// check zscore
	if (check_mat(zscore, M, 0, 1))
		print_error_global("nan", NULL, 0);

	// percentage of variance 
	for (d = 0; d < D; d++)
		perc_var[d + 1] = variance(&(beta[d * M]), M); 
	normalize_lines(perc_var, 1, D + 1);
	//print_perc(perc_var, 0, D);


	// save ED and DIC
	printf("\tED: NA\t DIC: NA \n\n");

	// free memory
	free(var_beta);
	free(CCt);
}
