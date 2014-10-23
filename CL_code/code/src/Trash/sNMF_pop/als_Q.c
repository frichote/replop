/*
   sNMF, file: als_Q.c
   Copyright (C) 2013 François Mathieu, Eric Frichot

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
#include "als_Q.h"
#include "../matrix/matrix.h"
#include "../matrix/rand.h"
#include "../matrix/data.h"
#include "../matrix/inverse.h"
#include "../matrix/normalize.h"
#include "../io/print_bar.h"

#ifndef WIN32
	#include "thread_Q.h"
	#include "thread_snmf.h"
#endif

// udpate_Q (not used) TODO

void update_Q(double *Q, double *F, double *X, int N, int M, 
		int K, 	double alpha, Memory mem) {

	int i, j, k1, k2;
	double *temp1 = mem->temp1;
	double *temp2 = mem->tempQ;
	double *temp3 = mem->temp3;

	int jd, jm;

	zeros(F, M * K);
	//computation of t(F)*F
	for (j = 0; j < M; j++) {
		for (k1 = 0; k1 < K; k1++) {
			for (k2 = 0; k2 < K; k2++) {
				temp1[k1*K+k2] += F[j*K+k1] * F[j*K+k2];
				temp1[k1*K+k2] += alpha;
			}
		}
	}

	//inverse of t(F)*F
	fast_inverse(temp1, K, temp2);

	// t(F)*t(X)							(M N K)
	zeros(temp3,K*N);

	/*
	if (num_thrd > 1) {
		thread_fct_snmf(X, temp3, NULL, F, nc, K, M, Mp, N, num_thrd, slice_F_TX);
	} else {
	*/
	for (i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			for (k1 = 0; k1 < K; k1++) {
				temp3[k1*N+i] += F[j*K+k1] * X[i * M + j];
			}
		}
	}
	/*
	}
	*/

	// temp2 * temp3
	zeros(Q,K*N);
	for(k1 = 0; k1 < K; k1++) {
		for(k2 = 0; k2 < K; k2++) {
			for(i = 0; i < N; i++) {
				Q[i*K+k2] += temp2[k2*K+k1] * temp3[k1*N+i];
			}
		}
	}

	// Q[Q < 0] = 0.0;
	for(j = 0; j < N; j++) 
		for(i = 0; i < K; i++) 
			Q[j*K+i] = fmax(Q[j*K+i],0);
}

// update_nnlsm_Q

double update_nnlsm_Q(double *Q, double *F, double *X, int N, int M, 
	int K, double alpha, Memory mem, int num_thrd) {

	int i, k;

	double* temp1 = mem->temp1;
	double* tempQ = mem->tempQ;
	double* temp3 = mem->temp3;
	double* Y = mem->Y;
	double res;

	// compute F t(F) + alpha
	F_tF_alpha(temp1, F, K, M, N, num_thrd, alpha);

	// compute t(F) X
	tF_tX(temp3, X, F, K, M, N, num_thrd);

	// solve Q
	nnlsm_blockpivot(temp1, temp3, N, K, tempQ, Y, mem);

	// update Q
	for(i = 0; i < N; i++) 
		for(k = 0; k < K; k++) 
			Q[i*K+k] = tempQ[k*N+i];

	// new output criteria
	res = 0.0; 
	for(i = 0; i < N; i++)
		for(k = 0; k < K; k++)
			if (Q[i * K + k] > 0 || Y[k * N + i] < 0)
				res += Y[k * N + i] * Y[k * N + i];

	return sqrt(res);
}


// normalize_Q

void normalize_Q(double *Q, int N, int K)
{
	normalize_lines(Q, N, K);
}

// tF_F_alpha

void F_tF_alpha(double *temp1, double *F, int K, int M, int N,
	int num_thrd, double alpha) 
{
	int j, k1, k2;

	// t(F)*F							(M K2)
	zeros(temp1,K*K);

#ifndef WIN32
	/*
	if (num_thrd > 1) {
		thread_fct_snmf(NULL, temp1, NULL, F, nc, K, M, Mp, N, num_thrd, slice_F_TF);
	} else {
	*/
#endif
		for (j = 0; j < M; j++) {
			for (k1 = 0; k1 < K; k1++) {
				for (k2 = 0; k2 < K; k2++) {
					temp1[k1*K+k2] += F[j*K+k1] * F[j*K+k2];
				}
			}
		}
#ifndef WIN32
	/*
	}
	*/
#endif

	if (alpha) {
		for (k1 = 0; k1 < K; k1++) {
			for (k2 = 0; k2 < K; k2++) {
				temp1[k1*K+k2] += alpha;
			}
		}
	}
}

// tF_tX

void tF_tX(double *temp3, double *X, double *F, int K, int M, 
	int N, int num_thrd)
{
        int i, k1, j;

        // F*t(X)                                                       (M N K)
        zeros(temp3,K*N);

#ifndef WIN32
	/*
        if (num_thrd > 1) {
                thread_fct_snmf(X, temp3, NULL, F, nc, K, M, Mp, N, num_thrd, slice_F_TX);
        } else {
	*/
#endif
                for (i = 0; i < N; i++) {
                	for (j = 0; j < M; j++) {
                                for (k1 = 0; k1 < K; k1++) {
                                        temp3[k1 * N + i] += F[j * K + k1] * X[i * M + j];
                                }
                        }
                }
#ifndef WIN32
	/*
        }
	*/
#endif
}

