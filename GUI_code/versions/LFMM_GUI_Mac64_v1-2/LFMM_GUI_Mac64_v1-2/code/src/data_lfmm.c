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
#include "data_lfmm.h"
#include "error_lfmm.h"
#include "thread_var.h"
#include "matrix/rand.h"

// zscore_calc

void zscore_calc(double *zscore, double *sum, double *sum2, int n, int cur)
{
	int i;
	double var;

	for (i = n; i < 2 * n; i++) {
		var =
		    ((sum2[i] - sum[i] * sum[i] / (double)cur) / (double)(cur -
									  1));
		zscore[(i - n)] = (sum[i]) / (sqrt(var) * (double)cur);
	}

}

// update_sum

void update_sum(double *beta, double *sum, int n)
{
	int i;

	for (i = 0; i < n; i++)
		sum[i] += beta[i];
}

// update_sum2

void update_sum2(double *beta, double *sum2, int n)
{
	int i;

	for (i = 0; i < n; i++)
		sum2[i] += (beta[i] * beta[i]);
}

// update_deviance

void update_deviance(double *deviance, int cur, double var, double thrd_m)
{
	double mean = thrd_m / var;
	//thrd_var(R,U,V,C,beta,K,D,M,N,num_thrd,slice_var,0,&mean);
	*deviance = ((double)(cur - 1) * (*deviance) + mean) / (double)cur;
}

// update_mean

void update_mean(double *beta, double *mean, int n, int cur)
{
	int i;

	for (i = 0; i < n; i++)
		mean[i] = ((double)(cur - 1) * mean[i] + beta[i]) / (double)cur;
}

// modify_C

void modify_C(double *C, int N, int nD, double *Cpp, int d)
{
	int i;

	for (i = 0; i < N; i++)
		Cpp[i * 2] = 1.0;

	for (i = 0; i < N; i++)
		Cpp[i * 2 + 1] = C[i * nD + d];
}

// write_DIC

void write_DIC(char *file_data, double deviance, double DIC)
{
	FILE *file = NULL;

	file = fopen(file_data, "a");
	if (!file)
		print_error_global("open", file_data, 0);

	fprintf(file, "Deviance DIC\n");
	fprintf(file, "%G %G\n", deviance, DIC);
	fclose(file);
}

// write_zscore_double

void write_zscore_double(char *file_data, int M, double *zscore)
{
	FILE *file = NULL;
	int j;
	long double pvalue;

	file = fopen(file_data, "w");
	if (!file)
		print_error_global("open", file_data, 0);

	for (j = 0; j < M; j++) {
		pvalue = zscore2pvalue((long double)fabs(zscore[j]));
		fprintf(file, "%Lg %Lg %Lg ", (long double)fabs(zscore[j]),
			(long double)(-log10(pvalue)), pvalue);
		fprintf(file, "\n");
	}
	fclose(file);
}

// var_data

double var_data(float *R, double *U, double *V, double *C, double *beta, int N,
		int M, int K, int D, double *thrd_m2, int num_thrd)
{
	double mean, mean2;

	/*
	   thrd_var(R,U,V,C,beta,K,D,M,N,num_thrd,slice_mean,0,&mean,0);
	   mean /= N*M;
	 */
	thrd_var(R, U, V, C, beta, K, D, M, N, num_thrd, slice_var, 0, &mean,
		 &mean2);

	*thrd_m2 = mean2;

	return (mean2 - mean * mean / (N * M)) / (N * M - 1);
}

// inputation

void inputation(float *R, double *U, double *V, double *C, double *beta, int *I,
		int N, int M, int K, int D)
{
	int i, j, k, d;
	double tmp1, tmp2;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (!I[i * M + j]) {
				tmp1 = 0;
				for (d = 0; d < D; d++)
					tmp1 += C[i * D + d] * beta[d * M + j];
				tmp2 = 0;
				for (k = 0; k < K; k++)
					tmp2 += U[k * N + i] * V[k * M + j];
				R[i * M + j] = (float)(tmp1 + tmp2);
			}
		}
	}
}
