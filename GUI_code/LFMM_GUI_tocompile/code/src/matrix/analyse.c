/*
    LFMM, file: analyse.c
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
#include "analyse.h"
#include "error.h"

// analyse_col

void analyse_col(float *data, int N, int M, int *nM, int missing, int *I)
{
	int i, j, ind;
	int *col = (int *)malloc(M * sizeof(int));
	float *tmp = (float *)calloc(M, sizeof(float));

	for (j = 0; j < M; j++) {
		col[j] = 1;
		tmp[j] = 0;
	}

	if (!missing) {
		for (i = 1; i < N; i++) {
			for (j = 0; j < M; j++)
				col[j] = col[j] && (data[i * M + j] == data[j]);
		}
	} else {
		ind = 0;
		i = 0;
		while (ind < M && i < N) {
			for (j = 0; j < M; j++) {
				if (!tmp[j] && I[i * M + j]) {
					tmp[j] = data[i * M + j];
					ind++;
				}
			}
			i++;
		}
		if (i == M) {
			print_error_global("interne", NULL, 0);
		}
		for (i = 1; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (I[i * M + j])
					col[j] = col[j]
					    && (data[i * M + j] == tmp[j]);
			}
		}

	}

	*nM = 0;
	for (j = 0; j < M; j++) {
		if (col[j] == 1) {
			(*nM)++;
		}
	}

	free(col);
	free(tmp);
}

// analye_row

void analyse_row(float *data, int N, int M, int *row, int *nN)
{
	int i, j;

	for (i = 0; i < N; i++)
		row[i] = 1;

	for (i = 0; i < N; i++) {
		for (j = 1; j < M; j++) {
			row[i] = row[i] && (data[i * M + j] == data[i * M]);
		}
	}

	*nN = 0;
	for (i = 0; i < N; i++) {
		if (row[i] == 1) {
			(*nN)++;
		}
	}
}
