/*
    LFMM, file: print_lfmm.c
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
#include <stdio.h>
#include <stdlib.h>

// print_licence

void print_licence_lfmm()
{
	printf("LFMM Copyright (C) 2012 Eric Frichot\n"
	       "This program is free software: you can redistribute it and/or modify\n"
	       "it under the terms of the GNU General Public License as published by\n"
	       "the Free Software Foundation, either version 3 of the License, or\n"
	       "(at your option) any later version.\n"
	       "This program is distributed in the hope that it will be useful,\n"
	       "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	       "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	       "GNU General Public License for more details.\n"
	       "You should have received a copy of the GNU General Public License\n"
	       "along with this program.  If not, see <http://www.gnu.org/licenses/>.\n");

}

// print_head_licence

void print_head_licence_lfmm()
{
	printf("LFMM  Copyright (C) 2012 Eric Frichot\n"
	       "This program comes with ABSOLUTELY NO WARRANTY; for details type './LFMM -l'.\n"
	       "This is free software, and you are welcome to redistribute it\n"
	       "under certain conditions; type './LFMM -l' for details.\n\n");

}

// print_head

void print_head_lfmm()
{
	print_head_licence_lfmm();
	printf
	    ("****                      LFMM Version 1.1                     			*****\n"
	     "****   E. Frichot, S. Schoville, G. Bouchard, O. Francois       		*****\n"
	     "****         	        Please cite our paper !                 	     	*****\n"
	     "****   Information at http://membres-timc.imag.fr/Olivier.Francois/lfmm/	*****\n\n");
}

// print_help

void print_help_lfmm()
{

	printf("\nHELP: ./LFMM options \n\n"
	       "mandatory:\n"
	       "	-g genotype_file   		-- genotype file (in .lfmm format)\n"
	       "        -v variable_file     		-- variable file (in .env format)\n"
	     /*  "        -n n 						-- number n of individus\n"
	       "        -L L 						-- number L of SNPS\n" */
	       "        -K K 				-- K number of latent factors\n"
//	       "        -D D 						-- D number of covariables\n"
	       "optional:\n"
	       "        -d d 				-- d, the dth covariables 	(default: all)\n"
	       "        -o output_file 			-- output file with z-scores 	(default: zscore.txt)\n"
	       "        -m				-- missing data			(default: no)\n"
	       "        -p p				-- number of process used	(default: 1)\n"
	       "        -i Niter             		-- number of iterations in the GS\n"
	       "        -b burn         		-- burnin parameter in the GS\n\n"
	       "        -h              		-- help\n\n");
}

// print_summary

void print_summary_lfmm(int N, int M, int K, int D, int d, int Niter, int burn,
		   int m, char *output, char *input, char *cov_file, char *dev_file,
		   int num_thrd)
{

	printf("Summary of the options:\n\n"
	       "        -n 	%d\n"
	       "        -L  	%d\n"
	       "        -K	%d\n"
	       "        -D	%d\n"
	       "        -o	%s\n"
	       "        -i	%d\n"
	       "        -b	%d\n"
	       "        -p	%d\n"
	       "	-g    	%s\n"
	       "	-v	%s\n",
	       N, M, K, D, output, Niter, burn, num_thrd, input, cov_file);

	if (m)
		printf("	-m 	\n");

	if (d)
		printf("	-d	%d\n",d);

		printf("	-C	%s\n",dev_file);

	printf("\n");
}

// print_options

void print_options_lfmm(int argc, char *argv[]) {

        int i;

        for (i=0;i<argc;i++)
                printf("%s ",argv[i]);

        printf("\n");
}


