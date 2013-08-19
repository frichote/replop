/*
    NMF, file: register_cds.c
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
#include "register_cds.h"
#include "print_cds.h"
#include "../sNMF/print.h"
#include "error_cds.h"

// analyse_param_cds

void analyse_param_cds(	int argc, char *argv[], int* m, long long* s,
			double *e, char *input) 
{
        	int i;
		int g_data = -1;

	    for (i = 1; i < argc; i++) {
                if (argv[i][0] == '-') {
                        switch (argv[i][1]) {
                        case 's':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_cds("cmd","s (seed number)");
                                *s = atoi(argv[i]);
                                break;
                        case 'm':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_cds("cmd","m (number of alleles)");
                                *m = atoi(argv[i]);
                                break;
			case 'r':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_cds("cmd","alpha (parameter of the algorithm)");
                                *e = (double) atof(argv[i]);
				if (*e < 0) 
					*e =  0;
				if (*e > 1) 
					*e =  1;
                                break;
                        case 'h':   // global
                                print_help_cds();
                                exit(1);
                                break;
                        case 'l':   // global
                                print_licence();
                                exit(1);
                                break;
                        case 'g':
                                i++;
                                if (argc == i || argv[i][0] == '-')
					print_error_cds("cmd","g (genotype file)");
                                g_data = 0;
                                strcpy(input,argv[i]);
                                break;
                        default:    print_error_cds("basic",NULL);
                        }
                } else {
                        print_error_cds("basic",NULL);
		}
        }

        if (g_data == -1)
		print_error_cds("option","-g genotype_file");
}

