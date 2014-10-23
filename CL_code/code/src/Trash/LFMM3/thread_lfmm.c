/*
    LFMM, file: thread_lfmm.c
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
#include <string.h>
#include <math.h>
#include <time.h>
#include <float.h>

// thread_fct_lfmm

void thread_fct_lfmm(float *R, float *datb, double *U, double *V, double *C,
		double *beta, double *m, double *inv_cov, double *L,
		int K, int D, int M, int N, int num_thrd, void (*fct) (),
		double *alpha, double alpha_R)
{
	pthread_t *thread;	// pointer to a group of threads
	int i;

	thread = (pthread_t *) malloc(num_thrd * sizeof(pthread_t));
	Matrix_lfmm *Ma = (Matrix_lfmm *) malloc(num_thrd * sizeof(Matrix_lfmm));

	/* this for loop not entered if threadd number is specified as 1 */
	for (i = 1; i < num_thrd; i++) {
		Ma[i] = (Matrix_lfmm) malloc(1 * sizeof(matrix_lfmm));
		Ma[i]->R = R;
		Ma[i]->datb = datb;
		Ma[i]->U = U;
		Ma[i]->V = V;
		Ma[i]->C = C;
		Ma[i]->beta = beta;
		Ma[i]->m = m;
		Ma[i]->inv_cov = inv_cov;
		Ma[i]->L = L;
		Ma[i]->D = D;
		Ma[i]->K = K;
		Ma[i]->N = N;
		Ma[i]->M = M;
		Ma[i]->alpha = alpha;
		Ma[i]->alpha_R = alpha_R;
		Ma[i]->num_thrd = num_thrd;
		Ma[i]->slice = i;
		/* creates each thread working on its own slice of i */
		if (pthread_create
		    (&thread[i], NULL, (void *)fct, (void *)Ma[i])) {
			perror("Can't create thread");
			free(thread);
			exit(1);
		}
	}

	/* main thread works on slice 0 so everybody is busy
	 * main thread does everything if threadd number is specified as 1*/
	Ma[0] = (Matrix_lfmm) malloc(1 * sizeof(matrix_lfmm));
	Ma[0]->R = R;
	Ma[0]->datb = datb;
	Ma[0]->U = U;
	Ma[0]->V = V;
	Ma[0]->C = C;
	Ma[0]->beta = beta;
	Ma[0]->m = m;
	Ma[0]->inv_cov = inv_cov;
	Ma[0]->L = L;
	Ma[0]->K = K;
	Ma[0]->D = D;
	Ma[0]->N = N;
	Ma[0]->M = M;
	Ma[0]->alpha = alpha;
	Ma[0]->alpha_R = alpha_R;
	Ma[0]->num_thrd = num_thrd;
	Ma[0]->slice = 0;
	/* creates each thread working on its own slice of i */
	fct(Ma[0]);

	/*main thead waiting for other thread to complete */
	for (i = 1; i < num_thrd; i++)
		pthread_join(thread[i], NULL);

	for (i = 0; i < num_thrd; i++)
		free(Ma[i]);
	free(Ma);
	free(thread);
}
