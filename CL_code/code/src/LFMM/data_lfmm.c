/*
   LFMM, file: data_lfmm.c
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
#include "../matrix/rand.h"
#include "../matrix/matrix.h"
#include "../io/io_tools.h"

# ifndef WIN32
#include "thread_var.h"
# endif

// pvalue_qvalue

void pvalue_qvalue(long double *pvalues, long double *qvalues, int n)
{
	int *index = (int *)calloc(n, sizeof(int));
	int i;

	// sort pvalue table
	sort_index(pvalues, index, n);

	for (i = 0; i < n; i++)
		qvalues[index[i]] = pvalues[index[i]] 
				  * (long double)(n) / (long double) (i+1);	
	

	free(index);
}

// zscore_calc

void zscore_calc(double *zscore, double *sum, double *sum2, int n, int cur, int D)
{
	int i;
	double var;
	
	for (i = n; i < D * n; i++) {
		// calculate var beta
		var =
			((sum2[i] - sum[i] * sum[i] / (double)cur) / (double)(cur -
				1));
		// calculate zscore beta
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

void modify_C(double *C, int N, int nD, double *Cpp, int d, int all)
{
	int i, nd;

	if (all) {
		for (i = 0; i < N; i++)
			Cpp[i * (nD+1)] = 1.0;
		for (i = 0; i < N; i++)
			for (nd = 0; nd < nD; nd++)
				Cpp[i * (nD+1) + (nd+1)] = C[i * nD + nd];

	} else {
		for (i = 0; i < N; i++)
			Cpp[i * 2] = 1.0;
		for (i = 0; i < N; i++)
			Cpp[i * 2 + 1] = C[i * nD + d];
	}
}

// write_DIC

void write_DIC(char *file_data, double deviance, double DIC)
{
	FILE *file = NULL;

	file = fopen_write(file_data);

	fprintf(file, "Deviance DIC\n");
	fprintf(file, "%G %G\n", deviance, DIC);
	fclose(file);
}

// write_zscore_double

void write_zscore_double(char *output_file, int M, double *zscore, int D, int all, int nd, int K)
{
	FILE *file = NULL;
	int j;
	int d;
	char zscore_file[512]; 
	long double* pvalues = (long double *)calloc(M, sizeof(long double));
	long double* qvalues = (long double *)calloc(M, sizeof(long double));

	if (all) {
		for (d = 0; d < D; d++) {
			// calculate pvalues
			for (j = 0; j < M; j++)
				pvalues[j] = zscore2pvalue((long double)fabs(zscore[d*M+j]));
			// calculate qvalues
			pvalue_qvalue(pvalues, qvalues, M);
			
			// write file name 
                	snprintf(zscore_file, 512, "%s_a%d.%d.zscore", output_file,d+1,K);
			// and write 
			file = fopen_write(zscore_file);
			for (j = 0; j < M; j++) {
				fprintf(file, "%Lg %Lg %Lg %Lg %Lg", (long double)fabs(zscore[d*M+j]),
						(long double)(-log10(pvalues[j])), pvalues[j],
						(long double)(-log10(qvalues[j])), qvalues[j]);
				fprintf(file, "\n");
			}
			fclose(file);
                        printf("\tThe zscores for variable %d were registered in:\n \t\t%s.\n"
				"\tThe columns are: zscore, -log10(p-value), p-value, -log10(q-value), q-value.\n"
				"\n\n", d+1, zscore_file);
		}
	} else {
		// calculate pvalues
		for (j = 0; j < M; j++)
			pvalues[j] = zscore2pvalue((long double)fabs(zscore[j]));
		// calculate qvalues
		pvalue_qvalue(pvalues, qvalues, M);

		// write file name
                snprintf(zscore_file, 512, "%s_s%d.%d.zscore", output_file,nd+1,K);
		// and write it
		file = fopen_write(zscore_file);
		for (j = 0; j < M; j++) {
			fprintf(file, "%Lg %Lg %Lg %Lg %Lg", (long double)fabs(zscore[j]),
					(long double)(-log10(pvalues[j])), pvalues[j],
					(long double)(-log10(qvalues[j])), qvalues[j]);
			fprintf(file, "\n");
		}
		fclose(file);
                printf("\tThe zscores for variable %d were registered in:\n \t\t%s.\n"
			"\tThe columns are: zscore, -log10(p-value), p-value, -log10(q-value), q-value.\n"
			"\n\n", nd+1, zscore_file);
	}

	free(pvalues);
	free(qvalues);
}

// var_data

double var_data(float *R, double *U, double *V, double *C, double *beta, int N,
		int M, int K, int D, double *thrd_m2, int num_thrd)
{
	double mean, mean2, tmp1, tmp2, tmp;
	int i, j, d, k;
	/*
	   thrd_var(R,U,V,C,beta,K,D,M,N,num_thrd,slice_mean,0,&mean,0);
	   mean /= N*M;
	 */
# ifndef WIN32
	if (num_thrd > 1) {
		thrd_var(R, U, V, C, beta, K, D, M, N, num_thrd, slice_var, 0, &mean,
				&mean2);
	} else {
# endif
		mean = 0.0;
		mean2 = 0.0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				tmp1 = 0.0;
				for (d = 0; d < D; d++)
					tmp1 += C[i * D + d] * beta[d * M + j];
				tmp2 = 0.0;
				for (k = 0; k < K; k++)
					tmp2 += U[k * N + i] * V[k * M + j];
				tmp = ((double)(R[i * M + j]) - tmp1 - tmp2);
				mean += tmp;     //(double)(R[i*M+j])-tmp1-tmp2)
				mean2 += tmp * tmp;  	//((double)(R[i*M+j])-tmp1-tmp2)*
				// ((double)(R[i*M+j])-tmp1-tmp2);
			}
		}
# ifndef WIN32
	}
# endif

	*thrd_m2 = mean2;

	return (mean2 - mean * mean / (N * M)) / (N * M - 1);
}

// var_data_inputation

double var_data_inputation(float *R, int *I, double *U, double *V, double *C, 
	double *beta, int N, int M, int K, int D, double *thrd_m2, int num_thrd)
{
	double mean, mean2, tmp1, tmp2, tmp;
	int i, j, d, k;

# ifndef WIN32
	if (num_thrd > 1) {
		thrd_var(R, U, V, C, beta, K, D, M, N, num_thrd, slice_var, 0, &mean,
				&mean2);
	} else {
# endif
		mean = 0.0;
		mean2 = 0.0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				tmp1 = 0.0;
				for (d = 0; d < D; d++)
					tmp1 += C[i * D + d] * beta[d * M + j];
				tmp2 = 0.0;
				for (k = 0; k < K; k++)
					tmp2 += U[k * N + i] * V[k * M + j];
				tmp = ((double)(R[i * M + j]) - tmp1 - tmp2);
				if (!I[i * M + j])	
					R[i * M + j] = (float)(tmp1 + tmp2);
				mean += tmp;     //(double)(R[i*M+j])-tmp1-tmp2)
				mean2 += tmp * tmp;  	//((double)(R[i*M+j])-tmp1-tmp2)*
				// ((double)(R[i*M+j])-tmp1-tmp2);
			}
		}
# ifndef WIN32
	}
# endif

	*thrd_m2 = mean2;

	return (mean2 - mean * mean / (N * M)) / (N * M - 1);
}

// inputation

void inputation_lfmm(float *R, double *U, double *V, double *C, double *beta, int *I,
		int N, int M, int K, int D)
{
	int i, j, k, d;
	double tmp1, tmp2;

	// for each data in R
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			// if missing data
			if (!I[i * M + j]) {
				// U V + C beta
				tmp1 = 0.0;
				for (d = 0; d < D; d++)
					tmp1 += C[i * D + d] * beta[d * M + j];
				tmp2 = 0.0;
				for (k = 0; k < K; k++)
					tmp2 += U[k * N + i] * V[k * M + j];
				// imput
				R[i * M + j] = (float)(tmp1 + tmp2);
			}
		}
	}
}
