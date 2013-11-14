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
	       "	-g genotype_file   	-- genotype file (in .lfmm format)\n"
	       "        -v variable_file     	-- variable file (in .env format)\n"
	       "        -K K 			-- K number of latent factors\n"
	       "optional:\n"
	       "        -d d 			-- d, the dth covariables 	(default: all separately)\n"
	       "        -a 			-- all covariables at the same time\n"
	       "        -o output_file 		-- output file with z-scores 	(default: genotype_file.zscore)\n"
	       "        -m			-- missing data			(default: no)\n"
	       "        -p p			-- number of processes (CPU)	(default: 1)\n"
	       "        -i Niter             	-- number of iterations in the GS (default: 1000)\n"
	       "        -b burn         	-- burnin parameter in the GS   (default: 3000)\n"
	       "        -s seed         	-- seed random init		(default: random)\n"
	       "        -C dic_file         	-- DIC file			(default: genotype_file.dic\n"
	       "        -h              	-- help\n\n");
}

// print_summary

void print_summary_lfmm(int N, int M, int K, int D, int d, int Niter, int burn,
		   int m, char *output, char *input, char *cov_file, char *dev_file,
		   int num_thrd, long long s, int all)
{

	printf("Summary of the options:\n\n"
	       "        -n (number of individuals) 	%d\n"
	       "        -L (number of loci)     	%d\n"
	       "        -K (number of latent factors)	%d\n"
	       "        -o (output file)		%s\n"
	       "        -i (number of iterations)	%d\n"
	       "        -b (burnin)			%d\n"
	       "	-s (seed random init)		%llu\n"
	       "        -p (number of processes (CPU))	%d\n"
	       "	-g (genotype file)	   	%s\n"
	       "	-v (variable file)		%s\n"
	       "        -D (number of covariables)	%d\n",
	       N, M, K, output, Niter, burn, s, num_thrd, input, cov_file, D);

	// if missing data
	if (d)
		printf("	-d (the dth covariable)		%d\n",d);
	if (all)
		printf("	-a (all variable at the same time)\n");
	if (m)
		printf("	-m (missing data)	 	\n");

		printf("	-C (DIC file)			%s\n",dev_file);

	printf("\n");
}



