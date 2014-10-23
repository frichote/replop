/*
   NMF, file: criteria.c
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
#include "criteria.h"

// least_square

double least_square(double *X, double *Q, double *F, int N, int M, 
	int K, double alpha) 
{
	int i, k, j;
	double like = 0.0;
	double tmp;

	// for each individual
        for(i = 0; i < N; i++) {
		// least square part
                for (j = 0; j < M; j++) {
			tmp = 0.0;
                        for (k = 0; k < K; k++)
                              	tmp += F[j * K + k] * Q[i * K + k];
			like += (X[i * M + j] - tmp) *(X[i * M + j] - tmp);
		}
	}

	// likelihood
	// like += 2*sqrt(alpha)*norm1;

	return like;
}
