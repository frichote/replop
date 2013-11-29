/*
    sNMF, file: print_snmf.c
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


#include "print_snmf.h"
#include <stdio.h>
#include <stdlib.h>

// print_licence_snmf

void print_licence_snmf() 
{
        printf("sNMF Copyright (C) 2013 François Mathieu, Eric Frichot\n"
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

// print_head_licence_snmf

void print_head_licence_snmf() 
{
    printf("sNMF  Copyright (C) 2013 François Mathieu, Eric Frichot\n"
    "This program comes with ABSOLUTELY NO WARRANTY; for details type './sNMF -l'.\n"
    "This is free software, and you are welcome to redistribute it\n"
    "under certain conditions; type './sNMF -l' for details.\n\n");

}

// print_head_snmf

void print_head_snmf() 
{
        print_head_licence_snmf();
        printf("****                      sNMF Version 0.1                                     *****\n"
               "****   E. Frichot , F. Mathieu, T. Trouillon, G. Bouchard, O. Francois         *****\n"
               "****                    Please cite our paper !                                *****\n"
               "****   Information at http://membres-timc.imag.fr/Olivier.Francois/snmf.html   *****\n\n");
}

// print_help_snmf

void print_help_snmf()
{
   printf("\nHELP: ./sNMF options \n\n"
         "mandatory:\n"
         "        -g genotype_file	-- genotype file (in .geno format)\n"
         "        -K K                  -- number K of ancestral populations\n\n"

         "optional:\n"
         "        -h                    -- help\n"
         "        -a alpha              -- regularization parameter       (default: 0)\n"
         "        -q output_Q           -- individual admixture file      (default: genotype_file.K.Q)\n"
         "        -f output_F           -- ancestral frequencies file     (default: genotype_file.K.F)\n"
         "        -c perc               -- cross-entropy with 'perc' 			\n"
	 "                              of masked genotypes               (default: 0.05)\n"
         "        -e tol                -- tolerance error                (default: 0.0001)\n"
         "        -i iterations         -- number max of iterations       (default: 200)\n"
         "        -I SNPs               -- number of SNPs used to init Q  (default: min(L/10,1000))\n"
         "        -s seed               -- seed random init               (default: random)\n"
         "        -m ploidy             -- 1 if haploid, 2 if diploid     (default: 2)\n"
         "        -p num_proc           -- number of processes (CPU)      (default: 1)\n\n"
        );
}

// print_summary_snmf

void print_summary_snmf (     int N, int M, int m, long long seed, int K, double alpha,
                        double tol, int maxiter, char *input, int num_thread, double e, 
			char *output_Q, char *output_F, int I)
{

   printf("summary of the options:\n\n"
         "        -n (number of individuals)             %d\n"
         "        -L (number of loci)                    %d\n"
         "        -K (number of ancestral pops)          %d\n"
         "        -g (input file)                        %s\n"
         "        -q (individual admixture file)         %s\n"
         "        -f (ancestral frequencies file)        %s\n"
         "        -i (number max of iterations)          %d\n"
         "        -I (number of SNPs to init Q)          %d\n"
         "        -a (regularization parameter)          %G\n"
         "        -s (seed random init)                  %lu\n"
         "        -e (tolerance error)                   %G\n"
         "        -p (number of processes)               %d\n", N, M, K, input, output_Q, output_F,
								maxiter, I, alpha, (unsigned long)seed, 
								tol, num_thread);
	
        if (e != 0)
                printf("        -c (cross-Entropy criterion)           %G\n", e);
        if (m == 1)
                printf("        - haploid\n\n");
        else if (m == 2)
                printf("        - diploid\n\n");
        else
                printf("        - %d-ploid\n\n",m);


}

