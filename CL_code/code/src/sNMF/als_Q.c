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
#include "data_snmf.h"
#include "../bituint/bituint.h"

#ifndef WIN32
	#include "thread_F.h"
	#include "thread_snmf.h"
#endif
// udpate_Q (not used) TODO

void update_Q(double *Q, double *F, bituint *X, int N, int M, int nc, int Mp, 
		int K, 	double alpha, Memory mem) {

	int i, j, k1, k2;
	double *temp1 = mem->temp1;
	double *temp2 = mem->tempQ;
	double *temp3 = mem->temp3;

	int Mc = nc*M;
	int Md = Mc / SIZEUINT;
	int Mm = Mc % SIZEUINT;
	int jd, jm;
	bituint value;

	zeros(F,Mc*K);
	//computation of F*t(F)
	for (j = 0; j < Mc; j++) {
		for (k1 = 0; k1 < K; k1++) {
			for (k2 = 0; k2 < K; k2++) {
				temp1[k1*K+k2] += F[j*K+k1] * F[j*K+k2];
				temp1[k1*K+k2] += alpha;
			}
		}
	}

	//inverse of F*t(F)
	fast_inverse(temp1, K, temp2);

	// F*t(X)							(M N K)
	zeros(temp3,K*N);

	/*
	if (num_thrd > 1) {
		thread_fct_snmf(X, temp3, NULL, F, nc, K, M, Mp, N, num_thrd, slice_F_TX);
	} else {
	*/
		for (jd = 0; jd<Md; jd++) {
			for (i = 0; i < N; i++) {
				value = X[i*Mp+jd];
				for (jm = 0; jm<SIZEUINT; jm++) {
					if (value % 2) {
						for (k1 = 0; k1 < K; k1++) 
							temp3[k1*N+i] += F[(jd*SIZEUINT+jm)*K+k1];
					}
					value >>= 1;
				}
			}
		}
	/*
	}
	*/

	for (i = 0; i < N; i++) {
		value = X[i*Mp+Md];
		for (jm = 0; jm<Mm; jm++) {
			if (value % 2) {
				for (k1 = 0; k1 < K; k1++) 
					temp3[k1*N+i] += F[(Md*SIZEUINT+jm)*K+k1];
			}
			value >>= 1;
		}
	}

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

double update_nnlsm_Q(double *Q, double *F, bituint *X, int N, int M, int nc, 
		int Mp, int K, double alpha, Memory mem, int num_thrd) {

	int i, j, k1, k2, k;

	double* temp1 = mem->temp1;
	double* tempQ = mem->tempQ;
	double* temp3 = mem->temp3;
	double* Y = mem->Y;
	double res;
	int Mc = nc*M;
	int Md = Mc / SIZEUINT;
	int Mm = Mc % SIZEUINT;
	int jd, jm;
	bituint value;


	// F*t(F)							(M K2)
	zeros(temp1,K*K);

	if (num_thrd > 1) {
		thread_fct_snmf(X, temp1, NULL, F, nc, K, M, Mp, N, num_thrd, slice_F_TF);
	} else {
		for (j = 0; j < Mc; j++) {
			for (k1 = 0; k1 < K; k1++) {
				for (k2 = 0; k2 < K; k2++) {
					temp1[k1*K+k2] += F[j*K+k1] * F[j*K+k2];
				}
			}
		}
	}

	if (alpha) {
		for (k1 = 0; k1 < K; k1++) {
			for (k2 = 0; k2 < K; k2++) {
				temp1[k1*K+k2] += alpha;
			}
		}
	}
	// F*t(X)							(M N K)
	zeros(temp3,K*N);

#ifndef WIN32
	if (num_thrd > 1) {
		thread_fct_snmf(X, temp3, NULL, F, nc, K, M, Mp, N, num_thrd, slice_F_TX);
	} else {
#else
		for (jd = 0; jd<Md; jd++) {
			for (i = 0; i < N; i++) {
				value = X[i*Mp+jd];
				for (jm = 0; jm<SIZEUINT; jm++) {
					if (value % 2) {
						for (k1 = 0; k1 < K; k1++) 
							temp3[k1*N+i] += F[(jd*SIZEUINT+jm)*K+k1];
					}
					value >>= 1;
				}
			}
		}
#endif
#ifndef WIN32
	}
#else

	for (i = 0; i < N; i++) {
		value = X[i*Mp+Md];
		for (jm = 0; jm<Mm; jm++) {
			if (value % 2) {
				for (k1 = 0; k1 < K; k1++) 
					temp3[k1*N+i] += F[(Md*SIZEUINT+jm)*K+k1];
			}
			value >>= 1;
		}
	}

	// solve Q
	nnlsm_blockpivot(temp1,temp3,N,K,tempQ,Y,mem);

	// update Q
	for(i = 0; i < N; i++) 
		for(k = 0; k < K; k++) 
			Q[i*K+k] = tempQ[k*N+i];

	// ouptput criteria
	res = 0.0;
	for (j = 0; j < N*K; j++) {
		res += fabs(Y[j]);
	}

	return res;
}

// diff_rel

double diff_rel(double *Q_prec, double *Q, int n)
{
	double mean = 0.0;
	double max = 0.0;
	int i;

	for (i = 0; i < n; i++) {
		if (fabs(Q_prec[i]) >= 0.000001) {
			mean += fabs(Q_prec[i]-Q[i])/fabs(Q_prec[i]);
			max = fmax(max,fabs(Q_prec[i]-Q[i])/fabs(Q_prec[i]));
		}
		Q_prec[i] = Q[i];
	}

	return mean/n;
}

// normalize_Q

void normalize_Q(double *Q, int N, int K)
{
	normalize_lines(Q, N, K);
}
