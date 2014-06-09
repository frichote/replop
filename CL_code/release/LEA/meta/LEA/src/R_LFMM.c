/*
    LFMM, file: main.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "LFMM/LFMM.h"

#include "R_LFMM.h" 

void R_LFMM(char** R_input_file, char** R_output_file, char** R_cov_file,
        int *R_n, int *R_L, int *R_D, int* R_nd, 
	int *R_K, int* R_Niter, int* R_burn,
        int* R_num_CPU, long long* R_seed, int* R_missing_data, int* R_all,
	double *R_dic, double *R_dev, double *noise_epsilon, double *b_epsilon,
	int *init)
{
	LFMM(	*R_input_file, 
		*R_output_file, 
		*R_cov_file,
		R_n,
		R_L,
		R_D,
		*R_nd, 
		*R_K, 
		*R_Niter, 
		*R_burn,
		*R_num_CPU, 
		R_seed, 
		*R_missing_data, 
		*R_all,
		R_dic,
		R_dev,
		*noise_epsilon,
		*b_epsilon,
		*init);
}
