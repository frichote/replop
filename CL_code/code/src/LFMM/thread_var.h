/**
 * @file thread_var.h
 *
 * @brief functions to compute new values for the variance
 *        (possibly multithreaded) 
 */

#ifndef THREAD_VAR_H
#define THREAD_VAR_H

/**
 * structure to manage multithreading
 */
typedef struct _mat *Mat;

typedef struct _mat {
	float *R;
	double *U;
	double *V;
	double *C;
	double *beta;
	int D;
	int N;
	int M;
	int K;
	double mean;
	double res;
	double res2;
	int slice;
	int num_thrd;
} mat;

/**
 * general multithreading function manager. Some parameters can be NULL
 *
 * @param R     data matrix
 * @param U     U matrix 
 * @param V     V matrix
 * @param C     covariable matrix
 * @param beta  beta matrix
 * @param K     the number of covariables
 * @param D     the number of latent factors
 * @param M     the number of loci
 * @param N     the number of individuals
 * @param num_thrd      the number of processes used
 * @param mean	the mean matrix
 * @param res	the first res
 * @param res2	the second res
 */
void thrd_var(float *R, double *U, double *V, double *C,
	      double *beta, int K, int D, int M, int N, int num_thrd,
	      void (*fct) (), double mean, double *res, double *res2);

/**
 * compute a slice of the mean
 *
 * @param G     a specific structure for multi-threading
 */
void slice_mean(void *G);

/**
 * compute a slice of the var
 *
 * @param G     a specific structure for multi-threading
 */
void slice_var(void *G);

#endif // THREAD_VAR_H
