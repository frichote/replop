/*
    LFMM, file: matrix.c
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
#include "matrix.h"

void dble_sum2(double *A, int K, int M, double *res, double epsilon)
{
	int k, j;
	for (k = 0; k < K; k++) {
		res[k] = 0;
		for (j = 0; j < M; j++)
			res[k] += A[k * M + j] * A[k * M + j];
		res[k] = res[k] / 2 + epsilon;
	}
}

// dble_sum

double dble_sum(double *A, int size)
{

	double res = 0;
	int i;
	for (i = 0; i < size; i++)
		res += A[i] * A[i];

	return res;
}

// copy_vect

void copy_vect(double *in, double *out, int size)
{
	int i;
	for (i = 0; i < size; i++)
		out[i] = in[i];
}

// transpose_double

// from Rosetta Code
void transpose_double (double *m, int w, int h)
{
	int start, next, i;
	double tmp;
 
	for (start = 0; start <= w * h - 1; start++) {
		next = start;
		i = 0;
		do {	i++;
			next = (next % h) * w + next / h;
		} while (next > start);
		if (next < start || i == 1) continue;
 
		tmp = m[next = start];
		do {
			i = (next % h) * w + next / h;
			m[next] = (i == start) ? tmp : m[i];
			next = i;
		} while (next > start);
	}
}

// transpose_float

// from Rosetta Code
void transpose_float (float *m, int w, int h)
{
	int start, next, i;
	float tmp;
 
	for (start = 0; start <= w * h - 1; start++) {
		next = start;
		i = 0;
		do {	i++;
			next = (next % h) * w + next / h;
		} while (next > start);
		if (next < start || i == 1) continue;
 
		tmp = m[next = start];
		do {
			i = (next % h) * w + next / h;
			m[next] = (i == start) ? tmp : m[i];
			next = i;
		} while (next > start);
	}
}

// transpose_int

// from Rosetta Code
void transpose_int (int *m, int w, int h)
{
	int start, next, i;
	int tmp;
 
	for (start = 0; start <= w * h - 1; start++) {
		next = start;
		i = 0;
		do {	i++;
			next = (next % h) * w + next / h;
		} while (next > start);
		if (next < start || i == 1) continue;
 
		tmp = m[next = start];
		do {
			i = (next % h) * w + next / h;
			m[next] = (i == start) ? tmp : m[i];
			next = i;
		} while (next > start);
	}
}
