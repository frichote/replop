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

// diff_int

int diff_int(int *A, int *B, int n)
{
	int d = 1;
	int i;

	for (i = 0; i < n; i++)
		d = d & (A[i] == B[i]);

	return d;
}

// diff

double diff(double *A, double *B, int n)
{
	double d = 0;
	int i;

	for (i = 0; i < n; i++)
		d += fabs(A[i] - B[i]);

	printf("%G ", d / n);
	return d;
}

// ones

void ones(float *A, int size)
{
	int i;

	for (i = 0; i < size; i++)
		A[i] = 1;
}

// dble_sum2

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

// basic_prod

void basic_prod(float *a, float *b, float *res, int size)
{

	int i, j, k;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			res[i * size + j] = 0;
			for (k = 0; k < size; k++) {
				res[i * size + j] +=
				    a[i * size + k] * b[k * size + j];
			}
		}
	}
}

// vect_max

int vect_max(int *v, int n, int max)
{
	int i;
	int res = max;

	for (i = 0; i < n; i++)
		res = imax(res, v[i]);
	return res;
}

// vect_min

int vect_min(int *v, int n, int min)
{
	int i;
	int res = min;

	for (i = 0; i < n; i++)
		res = imin(res, v[i]);
	return res;
}

// imax

int imax(int a, int b)
{
	return (a < b) ? b : a;
}

// imin

int imin(int a, int b)
{
	return (a > b) ? b : a;
}

// prod

float *prod(float *A, float *B, int n, float alpha)
{

	float *res = (float *)calloc(n * n, sizeof(float));
	int i, j, k;
	float sum;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				sum += A[i * n + k] * B[k * n + j];
			}
			res[i * n + j] = alpha * sum;
		}
	}

	return res;
}

// norm_1

float norm_1(float *A, float *B, int n)
{

	float sum = 0;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum += fabs(A[i * n + j] - B[i * n + j]);
		}
	}

	return sum / (n * n);
}

// print_char_optim

void print_char_optim(unsigned char *out, int N, int M)
{
	int j, ip, i4;
	unsigned char res, res1;

	for (j = 0; j < M; j++) {
		for (ip = 0; ip < N / 4; ip++) {
			res = out[ip * M + j];
			for (i4 = 0; i4 < 4; i4++) {
				res1 = res % 4;
				//res1 = (res % 4 + 4)%4;
				printf("%d ", res1);
				res >>= 2;
			}
		}
		printf("\n");
	}
}

// print_mat

void print_mat(double *A, int N, int M)
{

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%5.5G ", A[i * M + j]);
		}
		printf("\n");
	}
	printf("\n");
}

// optim_mult

void optim_mult(double *A, double *B, double *C, int M, int N, int K)
{

	int i, j, k, d;
	int step = 4;
	int D = imax(1, (int)K / step);
	int from;		// note that this 'slicing' works fine
	int to;			// even if SIZE is not divisible by num_thrd

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			C[i * M + j] = 0;
		}
	}

	for (d = 0; d < D; d++) {
		from = (d * K) / D;	// note that this 'slicing' works fine
		to = ((d + 1) * K) / D;	// even if SIZE is not divisible by num_thrd
		//printf("from %d to %d\n",from,to);
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				//tmp = 0;
				for (k = from; k < to; k++) {
					C[i * M + j] +=
					    A[i * K + k] * (double)B[k * M + j];
				}
				//C[i*M+j] += tmp;
			}
		}
	}
}

// transpose

// from Rosetta Code
//void transpose_double (double *A, int K, int N)
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
	/*
	int k, i;
	double *At = (double *)calloc(K*N,sizeof(double));

	for (i = 0; i < N*K; i++) {
		At[i] = A[i];
	}

	for (k=0; k < K; k++) {
		for (i = 0; i < N; i++) {
			A[i*K+k] = At[k*N+i];
		}
	}

	free(At);
	*/
}

// transpose

void transpose_float (float *A, int K, int N)
{
	int k, i;
	float *At = (float *)calloc(K*N,sizeof(double));

	for (i = 0; i < N*K; i++) {
		At[i] = A[i];
	}

	for (k=0; k < K; k++) {
		for (i = 0; i < N; i++) {
			A[i*K+k] = At[k*N+i];
		}
	}

	free(At);
}

// transpose_int

void transpose_int (int *A, int K, int N)
{
	int k, i;
	int *At = (int *)calloc(K*N,sizeof(int));

	for (i = 0; i < N*K; i++) {
		At[i] = A[i];
	}

	for (k=0; k < K; k++) {
		for (i = 0; i < N; i++) {
			A[i*K+k] = At[k*N+i];
		}
	}

	free(At);
}
