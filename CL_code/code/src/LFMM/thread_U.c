/*
   LFMM, file: thread_U.c
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

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "thread_lfmm.h"
#include "../matrix/rand.h"
#include "thread_beta.h"
#include <string.h>
#include <math.h>
#include <time.h>
#include <float.h>

// slice_mU_U

void slice_mU_U(void *G)
{
	Matrix_lfmm Ma = (Matrix_lfmm) G;
	float *R = Ma->R;
	double *beta = Ma->beta;
	double *V = Ma->V;
	double *C = Ma->C;
	double *m_U = Ma->m;
	int N = Ma->N;
	int M = Ma->M;
	int K = Ma->K;
	int D = Ma->D;
	double *tmp_i = (double *)malloc(M * sizeof(double));
	int nb_data = N;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int i, j, k, d;

	for (i = from; i < to; i++) {
		for (j = 0; j < M; j++)
			tmp_i[j] = (double)(R[i * M + j]);
		for (d = 0; d < D; d++) {
			for (j = 0; j < M; j++)
				tmp_i[j] -= C[i * D + d] * beta[d * M + j];
		}
		for (k = 0; k < K; k++) {
			m_U[i * K + k] = 0;
			for (j = 0; j < M; j++)
				m_U[i * K + k] += V[k * M + j] * tmp_i[j];
		}
	}

	free(tmp_i);
}

// slice_rand_U

void slice_rand_U(void *G)
{
	Matrix_lfmm Ma = (Matrix_lfmm) G;
	double *m_U = Ma->m;
	double *inv_cov_U = Ma->inv_cov;
	double *U = Ma->U;
	double *L = Ma->L;
	double alpha_R = Ma->alpha_R;
	int N = Ma->N;
	int K = Ma->K;
	int nb_data = N;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int i, k, kp;
	double *mu = (double *)calloc(K, sizeof(double));
	double *y = (double *)calloc(K, sizeof(double));

	for (i = from; i < to; i++) {
		for (k = 0; k < K; k++) {
			mu[k] = 0;
			for (kp = 0; kp < K; kp++) {
				mu[k] +=
				    inv_cov_U[k * K + kp] * m_U[i * K + kp];
			}
			mu[k] *= alpha_R;
		}
		mvn_rand(mu, L, K, y);
		for (k = 0; k < K; k++)
			U[k * N + i] = y[k];
	}
	free(mu);
	free(y);
}

// slice_inv_cov_U

void slice_inv_cov_U(void *G)
{
	Matrix_lfmm Ma = (Matrix_lfmm) G;
	double *inv_cov_U = Ma->inv_cov;
	double *V = Ma->V;
	int M = Ma->M;
	int K = Ma->K;
	double alpha = Ma->alpha;
	double alpha_R = Ma->alpha_R;
	int nb_data = K;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int j, k1, k2;

	for (k1 = from; k1 < to; k1++) {
		for (k2 = 0; k2 < K; k2++) {
			inv_cov_U[k1 * K + k2] = 0;
			for (j = 0; j < M; j++)
				inv_cov_U[k1 * K + k2] +=
				    (V[k1 * M + j] * V[k2 * M + j]);
			inv_cov_U[k1 * K + k2] *= alpha_R;
		}
		inv_cov_U[k1 * (K + 1)] += alpha;
	}
}
