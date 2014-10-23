/*
    LFMM, file: normalize.c
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
#include <math.h>
#include "normalize.h"

// normalize_data

void normalize_data(float *data, int N, int M, int *I, int missing_data)
{
	float mean;
	int i, j, sum;

	if (!missing_data) {
		for (j = 0; j < M; j++) {
			mean = 0;
			for (i = 0; i < N; i++) {
				mean += data[i * M + j];
			}
			mean /= N;
			for (i = 0; i < N; i++) {
				data[i * M + j] = (data[i * M + j] - mean);
			}
		}
	} else {
		for (j = 0; j < M; j++) {
			mean = 0;
			sum = 0;
			for (i = 0; i < N; i++) {
				if (I[i * M + j]) {
					mean += data[i * M + j];
					sum++;
				}
			}
			mean /= sum;
			for (i = 0; i < N; i++) {
				if (I[i * M + j]) {
					data[i * M + j] =
					    (data[i * M + j] - mean);
				}
			}
		}
	}
}

// normalize_cov

void normalize_cov(double *C, int N, int K)
{
	double mean, cov;
	int i, k;

	for (k = 0; k < K; k++) {
		mean = 0;
		for (i = 0; i < N; i++) {
			mean += C[i * K + k];
		}
		mean /= N;
		cov = 0;
		for (i = 0; i < N; i++) {
			cov += (C[i * K + k] - mean) * (C[i * K + k] - mean);
		}
		cov /= (N - 1);
		if (!cov) {
		        printf("Error: it seems that covariable %d is constant " 
				"among individuals.\n\n",k+1);
			exit(1);
		}

		for (i = 0; i < N; i++) {
			C[i * K + k] = (C[i * K + k] - mean) / sqrt(cov);
		}
	}
}

// normalize_lines

void normalize_lines(double *A, int N, int M)
{
	int i, j;
	double sum;
	for (i = 0; i < N; i++) {
		sum = 0.0;
		for (j = 0; j < M; j++) {
			sum += A[i * M + j];
		}
		for (j = 0; j < M; j++) {
			A[i * M + j] /= sum;
		}
	}

}

// normalize_cols

void normalize_cols(double *F, int K, int M)
{
	int i, j;
	double freq_0;

	for (j = 0; j < M; j++) {
		freq_0 = 0.0;
		for (i = 0; i < K; i++) {
			freq_0 += F[i * M + j];
		}
		for (i = 0; i < K; i++) {
			F[i * M + j] /= freq_0;
		}
	}
}
