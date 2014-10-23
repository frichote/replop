/*
 *     ancestrymap2geno, file: main_ancestrymap2geno.c
 *     Copyright (C) 2013 Eric Frichot
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "../io/io_data_int.h"
#include "../convert/geno.h"
#include "../io/io_tools.h"

int main (int argc, char *argv[]) {

	int i, j;
	int *lines = (int *) malloc(20000 * 1092 * sizeof(int));
	int N  = 1092;
	int M = 20000;

	read_geno(argv[1], lines, 1092, 20000);

	for (i = 0; i < N; i++) {
		printf("%d 1 0 0 1 2", i);
		for (j = 0; j < M; j++) {
			if (lines[i * M + j] == 0) 
				printf(" 0 0");
			else if (lines[i * M + j] == 1)
				printf(" 0 1");
			else 
				printf(" 1 1");
		}
		printf("\n");
	}
	
	return 0;
}

