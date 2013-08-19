/*
    LFMM, file: generative.c
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
#include "generative.h"
#include "../matrix/rand.h"

void generate_data(float *data, double *beta, double *U, double *V,
		   double *C, int N, int M, int K, int D)
{
	int i, j, d, k;
	double tmp;

	// generate U
	for (i = 0; i < N; i++) {
		for (k = 0; k < K; k++) {
			U[k * N + i] = rand_normal(0, 1);
		}
	}

	// generate V
	for (j = 0; j < M; j++) {
		for (k = 0; k < K; k++) {
			V[k * M + j] = rand_normal(0, 1);
		}
	}

	// generate U'*V
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			data[i * M + j] = 0;
			for (k = 0; k < K; k++) {
				data[i * M + j] +=
				    (float)(U[k * N + i] * V[k * M + j]);
			}
		}
	}

	// generate beta
	for (j = 0; j < M; j++) {
		for (d = 0; d < D; d++) {
			beta[d * M + j] = rand_normal(0, 1);
		}
	}

	// generate data
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			tmp = 0;
			for (d = 0; d < D; d++) {
				tmp += C[i * D + d] * beta[d * M + j];
			}
			data[i * M + j] += (float)(rand_normal(0, 1));
		}
	}
}
