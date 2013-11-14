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
#include "../io/io_tools.h"

// analyse_param_lfmm

void analyse_param_lfmm(int argc, char *argv[], int* d, int *K, int *Niter, int *burn,
		   int *m, char *output, char *input, char *cov_file, char *dev_file,
		   int *num_thrd, long long *s, int *all)
{
	int i, g_data = 0, g_cov = 0;
        char* tmp_file;
	int g_d = 0;

	for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'a':	// global
				*all = 1;
				break;
                        case 'd':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_lfmm("cmd","d (numerous of the covariable)",0);
                                *d = atoi(argv[i]);
				g_d = 1;
                                break;
			case 'K':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "K (number of latent factors)",
							 0);
				*K = atoi(argv[i]);
				break;
			case 'n':
				i++;
				if (argv[i][0] == '-')
					i--;
				printf("Warning: '-n' option is not necessary, (from LFMM v1.3)."
					" The number of individuals is automatically computed.\n\n");
				break;
			case 'L':
				i++;
				if (argv[i][0] == '-')
					i--;
				printf("Warning: '-L' option is not necessary, (from LFMM v1.3)."
					" The number of loci is automatically computed.\n\n");
				break;
			case 'D':
				i++;
				if (argv[i][0] == '-')
					i--;
				printf("Warning: '-D' option is not necessary (from LFMM v1.3)."
				" The number of environmental variables is automatically computed.\n\n");
				break;
			case 'i':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "i (number of iterations in the GS)",
							 0);
				*Niter = atoi(argv[i]);
				break;
                        case 's':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_lfmm("cmd","s (seed number)",0);
                                *s = atoi(argv[i]);
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
				break;
			case 'g':
				i++;
				if (argc == i || argv[i][0] == '-')
					print_error_lfmm("cmd",
							 "g (genotype file)",
							 0);
				g_data = 1;
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
				g_cov = 1;
				strcpy(cov_file, argv[i]);
				break;
			default:
				print_error_lfmm("basic", NULL, 0);
			}
		} else {
			print_error_lfmm("basic", NULL, 0);
		}
	}

	// checks 
	if (!g_data)
		print_error_lfmm("option", "-g genotype_file", 0);

	if (!g_cov)
		print_error_lfmm("option", "-v variable_file", 0);

	if (*all && *d) {
		print_error_lfmm("specific",
				 "-a (to run LFMM on all covariables at the same time) and -d (to run LFMM"
				 " on a specific variable) cannot be provided in the same command line.",
				 0);
	}

	if (g_d && *d <= 0)
		print_error_lfmm("missing", NULL, 0);

	if (*K < 0 || *num_thrd <= 0 || *burn <= 0 || *Niter <= 0)
		print_error_lfmm("missing", NULL, 0);
	else if (*K == 0)
		printf("TODO: not implemented yet !\n\n");

	if (*burn >= *Niter) {
		print_error_lfmm("specific",
				 "the number of iterations for burnin "
				 "(b) is greater than the number total of iterations (i)",
				 0);
	}

        // write output file name
        tmp_file = remove_ext(input,'.','/');
        if (!strcmp(output,"")) {
                strcpy(output, tmp_file);
                strcat(output, ".zscore");
        }
        // write dev file name
        if (!strcmp(dev_file,"")) {
                strcpy(dev_file,tmp_file);
                strcat(dev_file,".dic");
        }
        free(tmp_file);

}
