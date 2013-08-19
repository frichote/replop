/*
    LFMM, file: thread_var.c
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
#include "thread_var.h"
#include <string.h>
#include <math.h>
#include <time.h>
#include <float.h>

// thrd_var

void thrd_var(float *R, double *U, double *V, double *C,
	      double *beta, int K, int D, int M, int N, int num_thrd,
	      void (*fct) (), double mean, double *res, double *res2)
{
	pthread_t *thread;	// pointer to a group of threads
	int i;

	thread = (pthread_t *) malloc(num_thrd * sizeof(pthread_t));
	Mat *Ma = (Mat *) malloc(num_thrd * sizeof(Mat));

	/* this for loop not entered if threadd number is specified as 1 */
	for (i = 1; i < num_thrd; i++) {
		Ma[i] = (Mat) malloc(sizeof(mat));
		Ma[i]->R = R;
		Ma[i]->U = U;
		Ma[i]->V = V;
		Ma[i]->C = C;
		Ma[i]->beta = beta;
		Ma[i]->D = D;
		Ma[i]->K = K;
		Ma[i]->N = N;
		Ma[i]->M = M;
		Ma[i]->mean = mean;
		Ma[i]->res = 0;
		Ma[i]->res2 = 0;
		Ma[i]->num_thrd = num_thrd;
		Ma[i]->slice = i;
		/* creates each thread working on its own slice of i */
		if (pthread_create
		    (&thread[i], NULL, (void *)fct, (void *)Ma[i])) {
			perror("Can't create thread");
			free(thread);
			exit(-1);
		}
	}

	/* main thread works on slice 0
	 *          so everybody is busy
	 *                   main thread does everything if threadd number is specified as 1*/
	Ma[0] = (Mat) malloc(sizeof(mat));
	Ma[0]->R = R;
	Ma[0]->U = U;
	Ma[0]->V = V;
	Ma[0]->C = C;
	Ma[0]->beta = beta;
	Ma[0]->K = K;
	Ma[0]->D = D;
	Ma[0]->N = N;
	Ma[0]->M = M;
	Ma[0]->mean = mean;
	Ma[0]->res = 0;
	Ma[0]->res2 = 0;
	Ma[0]->num_thrd = num_thrd;
	Ma[0]->slice = 0;
	/* creates each thread working on its own slice of i */
	fct(Ma[0]);

	/*main thead waiting for other thread to complete */
	for (i = 1; i < num_thrd; i++)
		pthread_join(thread[i], NULL);

	*res = 0;
	for (i = 0; i < num_thrd; i++)
		*res += Ma[i]->res;

	if (res2) {
		*res2 = 0;
		for (i = 0; i < num_thrd; i++)
			*res2 += Ma[i]->res2;
	}

	for (i = 0; i < num_thrd; i++)
		free(Ma[i]);
	free(Ma);
	free(thread);
}

// slice_mean

void slice_mean(void *G)
{
	Mat Ma = (Mat) G;
	double *C = Ma->C;
	double *U = Ma->U;
	double *V = Ma->V;
	double *beta = Ma->beta;
	float *R = Ma->R;
	int M = Ma->M;
	int K = Ma->K;
	int D = Ma->D;
	int N = Ma->N;
	int nb_data = N;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int i, j, k, d;
	double tmp1, tmp2, mean;

	mean = 0;
	for (i = from; i < to; i++) {
		for (j = 0; j < M; j++) {
			tmp1 = 0;
			for (d = 0; d < D; d++)
				tmp1 += C[i * D + d] * beta[d * M + j];
			tmp2 = 0;
			for (k = 0; k < K; k++)
				tmp2 += U[k * N + i] * V[k * M + j];
			mean += (double)(R[i * M + j]) - tmp1 - tmp2;
		}
	}
	Ma->res = mean;
}

void slice_var(void *G)
{
	Mat Ma = (Mat) G;
	double *C = Ma->C;
	double *U = Ma->U;
	double *V = Ma->V;
	double *beta = Ma->beta;
	float *R = Ma->R;
	int M = Ma->M;
	int K = Ma->K;
	int D = Ma->D;
	int N = Ma->N;
	int nb_data = N;
	int s = Ma->slice;
	int num_thrd = Ma->num_thrd;
	int from = (s * nb_data) / num_thrd;	// note that this 'slicing' works fine
	int to = ((s + 1) * nb_data) / num_thrd;	// even if SIZE is not divisible by num_thrd
	int i, j, k, d;
	double tmp1, tmp2, var, var2, tmp;

	var = 0;
	var2 = 0;
	for (i = from; i < to; i++) {
		for (j = 0; j < M; j++) {
			tmp1 = 0;
			for (d = 0; d < D; d++)
				tmp1 += C[i * D + d] * beta[d * M + j];
			tmp2 = 0;
			for (k = 0; k < K; k++)
				tmp2 += U[k * N + i] * V[k * M + j];
			tmp = ((double)(R[i * M + j]) - tmp1 - tmp2);
			var += tmp;	//((double)(R[i*M+j])-tmp1-tmp2);// - mean)*((double)(R[i*M+j])-tmp1-tmp2 - mean);
			var2 += tmp * tmp;	//((double)(R[i*M+j])-tmp1-tmp2)*((double)(R[i*M+j])-tmp1-tmp2);
		}
	}
	Ma->res = var;
	Ma->res2 = var2;
}
