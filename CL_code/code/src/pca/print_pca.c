/*
    PCA, file: print_pca.c
    Copyright (C) 2013 Eric Frichot

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


#include "print_pca.h"
#include <stdio.h>
#include <stdlib.h>

// print_help

void print_help_pca() 
{
   printf("\nHELP: ./pca options \n\n"
         "mandatory:\n"
         "        -x genotype_file      -- genotype file (in .lfmm format)\n\n"

         "optional:\n"
         "        -h                    -- help\n"
         "        -K K                  -- number of principal components (default: n, the number of individuals)\n"
         "        -a eigenvalue_file    -- output eigenvalues file (default: genotype_file.eigenvalues)\n"
         "        -e eigenvector_file   -- output eigenvectors file (default: genotype_file.eigenvectors)\n"
         "        -c                    -- data centered (default: FALSE)\n"
         "        -s                    -- data centered and scaled (default: FALSE)\n\n"
        );
}

// print_summary

void print_summary_pca( int N, int M, int K, int c, int s, 
                        char *input, char *output_values, 
                        char *output_vectors) 
{

           printf("summary of the options:\n\n"
                "        -n (number of individuals)          %d\n"  
                "        -L (number of loci)                 %d\n"
                "        -K (number of principal components) %d\n"
                "        -x (genotype file)                  %s\n"
                "        -a (eigenvalues file)               %s\n"
                "        -e (eigenvectors file)              %s\n"
                , N, M, K, input, output_values, output_vectors);

        if (s)
                printf("        -s data centered and scaled \n\n");
        else if (c)
                printf("        -c data centered\n\n");
	else
               printf("\n");
}

