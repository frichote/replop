/*
   LFMM, file: beta_k0.c
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
#include "../matrix/matrix.h"
#include "../matrix/cholesky.h"
#include "../matrix/inverse.h"
#include "../matrix/rand.h"
#include "beta_k0.h"
#include "beta.h"
#include "data_lfmm.h"
#include "error_lfmm.h"

// calc_beta_k0

void calc_beta_k0(double *C, float *R, double *beta, double *CCt,
		double* var_beta, int M, int N, int D, double *var_res)
{
	int i, j, d, d2;
	double *m_beta = (double *)calloc(M * D, sizeof(double));
	double *inv_CCt = (double *)calloc(D * D, sizeof(double));
	double res, tmp;

	// init beta
	for (d = 0; d < D; d++)
		for (j = 0; j < M; j++)
			beta[d * M + j] = 0;

	for (i = 0; i < N; i++) {
		// calculate C * R	
		for (d = 0; d < D; d++) {
			for (j = 0; j < M; j++)
				m_beta[d * M + j] += C[i * D + d] * (double)(R[i * M + j]);   // C(N,D)
		}
	}

	// inverse Ct*C
        if (D == 1) {
                inv_CCt[0] = 1.0 / CCt[0];
        } else {
                fast_inverse(CCt, D, inv_CCt);
        }

	// calc EBeta
	for (d = 0; d < D; d++) 
		for (d2 = 0; d2 < D; d2++) 
			for (j = 0; j < M; j++)
				beta[d * M + j] += inv_CCt[d * D + d2] * m_beta[d2 * M + j];

	*var_res = 0.0;
	// calc varBeta
	for (j = 0; j < M; j++) {
		res = 0.0;
		for (i = 0; i < N; i++) {
			tmp = 0.0;
			for (d = 0; d < D; d++) 
				tmp += C[i * D + d] * beta[d * M + j];
			res += ((double)R[i * M + j] - tmp) * ((double)R[i * M + j] - tmp);
			*var_res += res;
		}
		for (d = 0; d < D; d++) 
			var_beta[d * M + j] = res / ((N - 2) * CCt[d * (D + 1)]);

	}
	*var_res /= (N * M - 1);


	// free memory
	free(m_beta);
	free(inv_CCt);
}

void zscore_calc_k0(double *zscore, double *beta, double *var_beta, int D, int M)
{
	int d, j;

	for (d = 1; d < D; d++)
		for (j = 0; j < M; j++)
			zscore[(d - 1) * M + j] = fabs(beta[d * M + j]) / sqrt(var_beta[d * M + j]);

}
