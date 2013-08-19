/*
    NMF, file: register.c
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
#include "register.h"
#include "print.h"
#include "error_nmf.h"

// analyse_param

void analyse_param(	int argc, char *argv[], int* m, long long* s,
			int* K, double* alpha, double* tol,
			int *iter, char *input, int* num_thrd) 
{
        	int i;
		int g_data = -1;

	    for (i = 1; i < argc; i++) {
                if (argv[i][0] == '-') {
                        switch (argv[i][1]) {
                        case 'K':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","K (number of clusters)",0);
                                *K = atoi(argv[i]);
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
                                break;
			case 'a':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","alpha (parameter of the algorithm)",0);
                                *alpha = (double) atof(argv[i]);
				if (*alpha < 0) {
					*alpha = 0;
				}
                                break;
                        case 'h':   // global
                                print_help();
                                exit(1);
                                break;
                        case 'l':   // global
                                print_licence();
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
			case 'i':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","i (number of iterations)",0);
                                *iter = atoi(argv[i]);
                                break;
                        case 'g':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_nmf("cmd","g (genotype file)",0);
                                g_data = 0;
                                strcpy(input,argv[i]);
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
		print_error_nmf("option","-g genotype_file",0);

        if (*K == 0)
		print_error_nmf("missing",NULL,0);

}

