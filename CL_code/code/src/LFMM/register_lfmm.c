/*
    LFMM, file: register_lfmm.c
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
#include <math.h>
#include "register_lfmm.h"
#include "print_lfmm.h"
#include "error_lfmm.h"

// analyse_param_lfmm

void analyse_param_lfmm(int argc, char *argv[], int *D, int *d,
		   int *N, int *M, int *K, int *Niter, int *burn,
		   int *m, char *output, char *input, char *cov_file, char *dev_file,
		   int *g_data, int *g_cov, int *num_thrd)
{
	int i;
	int out = 0;
	int dOk = 0;

	for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'D':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "D (number of covariables)",
							 0);
				*D = atoi(argv[i]);
				break;
                        case 'd':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_lfmm("cmd","d (numerous of the covariable)",0);
                                *d = atoi(argv[i]);
				dOk = 1;
                                break;
			case 'n':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "n (number of individuals)",
							 0);
				*N = atoi(argv[i]);
				break;
			case 'L':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "L (number of SNPs)",
							 0);
				*M = atoi(argv[i]);
				break;
			case 'K':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "K (number of latent factors)",
							 0);
				*K = atoi(argv[i]);
				break;
			case 'i':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "i (number of iterations in the GS)",
							 0);
				*Niter = atoi(argv[i]);
				break;
			case 'm':	// global
				*m = 1;
				break;
			case 'h':	// global
				print_help_lfmm();
				exit(1);
				break;
			case 'l':	// global
				print_licence_lfmm();
				exit(1);
				break;
			case 'b':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "b (burn parameter in the GS)",
							 0);
				*burn = atoi(argv[i]);
				break;
			case 'p':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "p (number of processes used)",
							 0);
				*num_thrd = atoi(argv[i]);
				break;
			case 'o':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "o (output file with z-scores)",
							 0);
				strcpy(output, argv[i]);
				out = 1;
				break;
			case 'g':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "g (genotype file)",
							 0);
				*g_data = 0;
				strcpy(input, argv[i]);
				break;
                        case 'C':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_lfmm("cmd","C (DIC file)",0);
                                strcpy(dev_file,argv[i]);
                                break;
			case 'v':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "v (variable file)",
							 0);
				*g_cov = 0;
				strcpy(cov_file, argv[i]);
				break;
			default:
				print_error_lfmm("basic", NULL, 0);
			}
		} else {
			print_error_lfmm("basic", NULL, 0);
		}
	}

	if (*g_data == -1)
		print_error_lfmm("option", "-g genotype_file", 0);

	if (*g_cov == -1)
		print_error_lfmm("option", "-v variable_file", 0);

	if (!out)
		print_error_lfmm("option", "-o output_file", 0);

	if (*D == 0 || *K == 0 || *M == 0 || *N == 0 || *burn == 0
	    || *Niter == 0)
		print_error_lfmm("missing", NULL, 0);

	if (dOk && (*d < 1 || *d > *D)) {
		print_error_lfmm("specific",
				 "(-d option). d should be between 1 and D",
				 0);
	}

	if (*burn >= *Niter) {
		print_error_lfmm("specific",
				 "the number of iterations for burnin "
				 "(b) is greater than the number total of iterations (i)",
				 0);
	}
}
