/*
    NMF, file: data_nmf.c
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
#include <math.h>
#include "data_nmf.h"
#include "../matrix/rand.h"

// inputation

void inputation(float *R, double *U, double *V, int *I, int N, int M, int K) 
{
	int i,j,k;
	double tmp1;

	for(i=0;i<N;i++) {
		for(j=0;j<M;j++) {
			if (!I[i*M+j]) {
				tmp1 = 0;
				for(k=0;k<K;k++)
					tmp1 += U[k*N+i]*V[k*M+j];
				R[i*M+j] = (float)(tmp1);
			}
		}
	}
}

void freq_inputation(float *X, int *I, int N, int M)
{
	int j,i, count;
	float freq;

	for (j = 0; j < M; j++) {
		count = 0;
		freq = 0.0;
		/*
		compteur = 0;
		freq_0 = 0;
		freq_1 = 0;
		freq[j] = 0;
		*/
		for (i = 0; i < N; i++) {
			if (I[i*M+j]) {
				count++;
				freq += X[i*M+j];
			}
		}
		freq /= count;
		for (i = 0; i < N; i++) {
			if (I[i*M+j]) {
				if (frand() > freq)
					X[i*M+j]++;
				if (frand() > freq)
					X[i*M+j]++;
			}
		}
	}
}
