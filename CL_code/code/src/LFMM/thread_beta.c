/*
   LFMM, file: thread_beta.c
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

// slice_mbeta_beta

void slice_mbeta_beta(void *G)
{
	Matrix_lfmm Ma = (Matrix_lfmm) G;
	float *R = Ma->R;
	double *U = Ma->U;
	double *V = Ma->V;
	double *C = Ma->C;
	double *m_beta = Ma->m;
	int N = Ma->N;
	int M = Ma->M;
	int K = Ma->K;
	int D = Ma->D;
	double *tmp_i = (double *)malloc(M * sizeof(double));
	int nb_data = M;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int i, j, k, d;

	for (d = 0; d < D; d++) {
		for (j = from; j < to; j++) {
			m_beta[d * M + j] = 0;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = from; j < to; j++)
			tmp_i[j] = (double)(R[i * M + j]);	// R(N,M)
		for (k = 0; k < K; k++) {
			for (j = from; j < to; j++)
				tmp_i[j] -= U[k * N + i] * V[k * M + j];	// U(K,N) V(K,M)
		}
		for (d = 0; d < D; d++) {
			for (j = from; j < to; j++)
				m_beta[d * M + j] += C[i * D + d] * tmp_i[j];	// C(N,D)
		}
	}

	free(tmp_i);
}

// slice_rand_beta

void slice_rand_beta(void *G)
{
	Matrix_lfmm Ma = (Matrix_lfmm) G;
	double *m_beta = Ma->m;
	double *inv_cov_beta = Ma->inv_cov;
	double *beta = Ma->beta;
	double *L = Ma->L;
	double alpha_R = Ma->alpha_R;
	int M = Ma->M;
	int D = Ma->D;
	int nb_data = M;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int j, d, dp;
	double *mu = (double *)calloc(D, sizeof(double));
	double *y = (double *)calloc(D, sizeof(double));

	for (j = from; j < to; j++) {
		for (d = 0; d < D; d++) {
			mu[d] = 0;
			for (dp = 0; dp < D; dp++) {
				mu[d] += inv_cov_beta[d * D + dp] * m_beta[dp * M + j];	// inv(D,D) 
			}
			mu[d] *= alpha_R;
		}
		mvn_rand(mu, L, D, y);
		for (d = 0; d < D; d++)
			beta[d * M + j] = y[d];	// beta(D,M)
	}
	free(mu);
	free(y);
}
