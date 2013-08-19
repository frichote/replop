/*
   createDataSet, file: R_createDataSet.c
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
#include <math.h>
#include "io/io_tools.h"
#include "io/io_error.h"
#include "matrix/error.h"
#include "createDataSet/register_cds.h"
#include "createDataSet/print_cds.h"
#include "sNMF/print.h"
#include "matrix/rand.h"
#include "matrix/data.h"
#include "matrix/matrix.h"
#include "R_createDataSet.h"

int main_createDataSet (int argc, char *argv[]) {

	int N = 0;			// number of individuals
	int M = 0;			// number of SNPs
	char input_file[512];		// input file "without" missing data
	char output_file[512];		// output file with missing data
	int X;				// data matrix "without" missing data
        int nc = 3;                     // ploidy, 3 if 0,1,2 , 2 if 0,1 (number of factors)
	double e = 0.05;		// output percentage of missing data
	long long seed = -1;
	
	// local parameters
	int i, j;
	int m = 0;

        // local parameters to read files
        FILE *in_File = NULL;
        FILE *out_File = NULL;
        char token;
	char *tmp_file;

        print_head();

	// analyse of the command line
	analyse_param_cds(argc,argv, &m, &seed, &e, input_file);

	init_random(&seed);

        // fix the number of possible factors 
        if (m)
                nc = nc + 1;
	else 
		m = 2;

        // count the number of lines and columns
        N = nb_cols(input_file);
        M = nb_lines(input_file, N);

	// write command line summary
	print_summary_cds(N, M, m, seed, e, input_file);

	// write output file name
        tmp_file = remove_ext(input_file,'.','/');

        strcpy(output_file,tmp_file);
        strcat(output_file,"_I.geno");

	free(tmp_file);

        // open files 
        in_File = fopen(input_file, "r");
        out_File = fopen(output_file, "w");

        if (!in_File)
                print_error_global("open", input_file, 0);
        if (!out_File)
                print_error_global("open", output_file, 0);

        j = 0;
      	while (!feof(in_File) & (j < M)) {

                // read of X line
                i = 0;
	        token = (char)fgetc(in_File);

		// for each column
	        while(token != EOF && token != '\n' && i<N) {

	                X = (int)(token - '0');
			// remove a part of the data and write it			
                	if (frand() < e) 
				fprintf(out_File,"9");
			else 
				fprintf(out_File,"%d",X);

                         i++;
	        	 token = (char)fgetc(in_File);
                }
		fprintf(out_File,"\n");

		// test the number of columns
		test_column(input_file, in_File, i, j, N, &token);
                j++;
	}

	// close file
	fclose(in_File);	
	fclose(out_File);

        printf("Write genotype file with missing data %s:\t\tOK.\n\n",output_file);

	return 0;
}

