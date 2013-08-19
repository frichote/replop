/**
 * @file thread.h
 *
 * @brief general function and structure to manage multithreading
 */

#ifndef THREAD_H
#define THREAD_H

#include "../bituint/bituint.h"

/**
 * structure to manage multithreading
 */
typedef struct _matrix *Matrix;

struct _matrix {
	bituint *R;
	double *out;
	double *Q;
	double *F;
	int K;
	int N;
	int M;
	int Mp;
	int nc;
	int slice;
	int num_thrd;
} matrix;

/** FAUX
 * general multithreading function manager. Some parameters can be NULL
 *
 * @param R	data matrix
 * @param out	output matrix
 * @param Q	Q matrix 
 * @param F	F matrix
 * @param nc	number of different values in X
 * @param K	the number of latent factors
 * @param D	the number of covariables
 * @param M	the number of loci
 * @param Mp	number of columns of X
 * @param N	the number of individuals
 * @param num_thrd	the number of processes used
 * @param fct	the specific slice function
 */
void thread_fct(bituint *R, double *out, double *Q, double *F,
                int nc, int K, int M, int Mp, int N, int num_thrd, void (*fct) ());

#endif // THREAD_H
