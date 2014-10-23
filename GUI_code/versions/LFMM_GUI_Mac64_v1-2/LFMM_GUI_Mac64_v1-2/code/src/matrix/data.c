/*
    LFMM, file: data.c
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
#include "data.h"
#include "error.h"
#include "rand.h"

// zeros

void zeros(double *A, int n)
{
	int i;

	for (i = 0; i < n; i++)
		A[i] = 0;
}

// check_mat

int check_mat(double *A, int n, int nd, int nD)
{
	int i;

	for (i = 0; i < n; i++) {
		if (isnan(A[i * nD + nd]))
			return 1;
	}
	return 0;
}

// update_m

void update_m(double *beta, int n, int nb)
{
	int i;

	for (i = 0; i < n; i++)
		beta[i] /= nb;
}

// create_I

void create_I(float *dat, int *I, int N, int M)
{
	int i;

	for (i = 0; i < N * M; i++) {
		if (dat[i] == 9 || dat[i] == -9)
			I[i] = 0;
		else
			I[i] = 1;
	}
}

// write_data_float

void write_data_float(char *file_data, int N, int M, float *dat)
{
	FILE *file = NULL;
	int i, j;

	file = fopen(file_data, "w");
	if (!file)
		print_error_global("open", file_data, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			fprintf(file, "%G ", dat[i * M + j]);
		}
		fprintf(file, "%G", dat[i * M + (M - 1)]);
		fprintf(file, "\n");
	}
	fclose(file);
}

// write_data_double

void write_data_int(char *file_data, int N, int M, int *dat)
{
	FILE *file = NULL;
	int i, j;

	file = fopen(file_data, "w");
	if (!file)
		print_error_global("open", file_data, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			fprintf(file, "%d ", dat[i * M + j]);
		}
		fprintf(file, "%d", dat[i * M + (M - 1)]);
		fprintf(file, "\n");
	}
	fclose(file);
}

void write_data_double(char *file_data, int N, int M, double *dat)
{
	FILE *file = NULL;
	int i, j;

	file = fopen(file_data, "w");
	if (!file)
		print_error_global("open", file_data, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			fprintf(file, "%G ", dat[i * M + j]);
		}
		fprintf(file, "%G", dat[i * M + (M - 1)]);
		fprintf(file, "\n");
	}
	fclose(file);
}

// print_data

void print_data(float *dat, int N, int M)
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%f ", dat[i * M + j]);
		}
		printf("\n");
	}
}

// clean_data

void clean_data(float *dat, int *col, int N, int M, int nM)
{
	int i, j, jp, newM;
	float *tmp, *tmp2;

	if (nM) {
		newM = M - nM;
		tmp = (float *)malloc(N * newM * sizeof(float));
		jp = 0;
		for (j = 0; j < M; j++) {
			if (!col[j]) {
				for (i = 0; i < N; i++) {
					tmp[i * M + jp] = dat[i * M + j];
				}
				jp++;
			}
		}
		tmp2 = dat;
		free(tmp2);
		dat = tmp;
	}
}
