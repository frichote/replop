/*
    NMF, file: register_snmf.c
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "register_snmf.h"
#include "print_snmf.h"
#include "error_nmf.h"
#include "../io/io_tools.h"

// analyse_param_snmf

void analyse_param_snmf(int argc, char *argv[], int* m, long long* s,
			int* K, double* alpha, double* tol, double *e,
			int *iter, char *input, int* num_thrd,
			char* input_Q, char* output_Q, char* output_F, 
			int* I) 
{
      	int i;
	int g_data = -1;
	char *tmp_file;
	char tmp[512];
	int g_c = 0;
	int g_m = 0;

    	for (i = 1; i < argc; i++) {
                if (argv[i][0] == '-') {
                        switch (argv[i][1]) {
                        case 'K':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","K (number of clusters)",0);
                                *K = atoi(argv[i]);
                                strcpy(tmp,argv[i]);
                                break;
                        case 's':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","s (seed number)",0);
                                *s = atoi(argv[i]);
                                break;
                        case 'm':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","m (number of alleles)",0);
                                *m = atoi(argv[i]);
				g_m = 1;
                                break;
			case 'a':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","alpha (regularization parameter)",0);
                                *alpha = (double) atof(argv[i]);
				if (*alpha < 0) {
					*alpha = 0;
				}
                                break;
                        case 'h':   // global
                                print_help_snmf();
                                exit(1);
                                break;
                        case 'l':   // global
                                print_licence_snmf();
                                exit(1);
                                break;
			case 'e':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","e (tolerance error in the algorithm)",0);
                                *tol = (double) atof(argv[i]);
				if (*tol < 0) {
					*tol = 0;
				}
                                break;
			case 'c':
                                i++;
                                if (argc == i || argv[i][0] == '-') {
					*e = 0.05;
					i--;
				} else  {
                                	*e = (double) atof(argv[i]);
				}
				g_c = 1;
                                break;
			case 'i':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","i (number of iterations)",0);
                                *iter = atoi(argv[i]);
                                break;
			case 'I':
                                i++;
                                if (argc == i || argv[i][0] == '-') {
					*I = -1;	
					i--;
				} else
                                	*I = (int) atoi(argv[i]);
				break;
                        case 'x':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","x (genotype file)",0);
                                g_data = 0;
                                strcpy(input,argv[i]);
                                break;
                        case 'q':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_nmf("cmd","q (individual admixture coefficients file)",0);
                                strcpy(output_Q,argv[i]);
                                break;
                        case 'Q':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_nmf("cmd","Q (admixture coefficients initialization file)",0);
                                strcpy(input_Q,argv[i]);
                                break;
                        case 'g':
                                i++;
                                if (argc == i || argv[i][0] == '-')
                                        print_error_nmf("cmd","g (ancestral genotype frequencies file)",0);
                                strcpy(output_F,argv[i]);
                                break;
			case 'p':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","p (number of processes)",0);
                              	*num_thrd = atoi(argv[i]);
                                break;
                        default:    print_error_nmf("basic",NULL,0);
                        }
                } else {
                        print_error_nmf("basic",NULL,0);
		}
        }

        if (g_data == -1)
		print_error_nmf("option","-x genotype_file",0);

        if (*K <= 0)
		print_error_nmf("missing",NULL,0);

        if (*num_thrd <= 0)
		print_error_nmf("missing",NULL,0);

        if (g_m && *m <= 0)
		print_error_nmf("missing",NULL,0);

        if (*iter <= 0)
		print_error_nmf("missing",NULL,0);

        if (g_c && (*e <= 0 || *e >= 1))
                print_error_nmf("missing",NULL,0);

        // write output file name
        tmp_file = remove_ext(input,'.','/');
	if (!strcmp(output_Q,"")) {
                strcpy(output_Q,tmp_file);
                strcat(output_Q,".");
                strcat(output_Q,tmp);
                strcat(output_Q,".Q");
	}
	if (!strcmp(output_F,"")) {
                strcpy(output_F,tmp_file);
                strcat(output_F,".");
                strcat(output_F,tmp);
                strcat(output_F,".G");
	}
        free(tmp_file);
}

