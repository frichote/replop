/*
   createDataSet, file: main.c
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
#include <R.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "createDataSet/createDataSet.h"

#include "R_createDataSet.h" 

void R_createDataSet (char** R_input_file, int* R_seed, double* R_percentage, 
	char **R_output_file) 
{
	// for random in R
	GetRNGstate();

	createDataSet(*R_input_file, (long long)(*R_seed), *R_percentage, *R_output_file); 

	// for random in R
	PutRNGstate(); 
}
	/*
	// parameter initialization
	char input_file[512];		// input file "without" missing data
	char output_file[512] = "";	// output file with missing data
	double e = 0.05;		// output percentage of missing data
	long long seed = -1;
	int m = 2;

        print_head_snmf();

	m = *R_ploidy;
	seed = *R_seed;
	if (R_ploidy)
		m = *R_ploidy;
	if (R_seed)
		seed = *R_seed;
	if (R_percentage)
		e = *R_percentage;

	if (R_input_file)
		strcpy(input_file, *R_input_file);
	else 
                print_error_cds("option","-g genotype_file");

	createDataSet(input_file, m, (long long) seed, percentage, output_file);
	*/

