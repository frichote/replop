/*
   LFMM, file: print_tools.c
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

#include "print_tools.h"
#include <stdio.h>
#include <stdlib.h>

// init_bar

void init_bar(int *i, int *j)
{
	*i = 0;
	*j = 0;
	printf("[");
}

// print_bar

void print_bar(int *i, int *j, int Niter)
{
	int shell_size = 77;
	int shell_unit = (int)(Niter / shell_size);
	int jp;

	// print shell
	if (*i < shell_unit)
		(*i)++;
	else {
		(*j)++;
		for (*i = 0; *i < 100; (*i)++) {
			printf("\b");
		}
		printf("\r[");
		*i = 0;
		for (jp = 0; jp < *j; jp++)
			printf("=");
		for (jp = *j; jp < shell_size - 5; jp++)
			printf(" ");
		printf("]");
	}
	fflush(stdout);
}
