/*
   sNMF, file: als.c
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
#include "als.h"
#include "../matrix/matrix.h"
#include "../matrix/rand.h"
#include "../matrix/data.h"
#include "../matrix/inverse.h"
#include "../matrix/normalize.h"
#include "../io/print_bar.h"
#include "als_Q.h"
#include "als_F.h"

// ALS

void ALS(double *X, double *Q, double *F, int N, int M, int K,
		int maxiter, double tol, int num_thrd, double alpha) 
{
	double prec2 = 1.0, sum2 = 0.0;
	int k, i, j, l, c;
	Memory mem;

	//Initialisation of Q, prec and bar
	//rand_matrix_double(Q, N, K);
	normalize_lines(Q, N, K);
	init_bar(&i,&j);

	// allocate memory for the all algorithm
	mem = allocate_memory(N, K);

	for (k = 0; k < maxiter; k++) {
		print_bar(&i,&j,maxiter);

		// update F
		update_F(F, Q, X, N, M, K, num_thrd, mem);
		// check numerical issues
		if (isnan(F[0])) {
			printf("ALS: Internal Error, F is NaN.\n");
			exit(1);
		}
		// TODO 
		// normalize_F(F,M,nc, K);

		// update Q
		sum2 = update_nnlsm_Q(Q, F, X, N, M, K, alpha,
				mem, num_thrd);
		// check numerical issues
		if (isnan(Q[0])) {
			printf("ALS: Internal Error, Q is NaN.\n");
			exit(1);
		}
		normalize_Q(Q,N,K);

		// stopping criteria
                if (k > 15 && fabs(prec2-sum2)/fabs(prec2) < tol) {
                        break;
                }
                prec2 = sum2;
		printf("%G\n",sum2);
		
		//prec2 = sum2;

	}
	final_bar();
	printf("Number of iterations: %d\n",k);
	// TODO
	// normalize_F(F,M,nc, K);
	//normalize_Q(Q,N,K);

	// to avoid numerical issues
	/*
	for(l = 0; l < N*K; l++) {
		if (fabs(Q[l]) < 0.0001)
			Q[l] = 0.0001;
		if (fabs(1-Q[l]) < 0.0001)
			Q[l] = 1-0.0001;
	}
	*/

	/*
	for(j = 0; j < M; j++) {
		for (c = 0; c < nc; c++) {
			for(k = 0; k < K; k++) {
				if (fabs(F[(nc*j+c)*K+k]) < 0.0001)
					F[(nc*j+c)*K+k] = 0.0001;
				if (fabs(1-F[(nc*j+c)*K+k]) < 0.0001)
					F[(nc*j+c)*K+k] = 1-0.0001;
			}
		}
	}
	*/

	//normalize_Q(Q,N,K);

	// free memory
	free_memory(mem);
	free(mem);
}

