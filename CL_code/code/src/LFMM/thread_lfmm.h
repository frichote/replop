/**
 * @file thread_lfmm.h
 *
 * @brief general function and structure to manage multithreading
 */

#ifndef THREAD_LFMM_H
#define THREAD_LFMM_H

/**
 * structure to manage multithreading
 */
typedef struct _matrix_lfmm *Matrix_lfmm;

struct _matrix_lfmm {
	float *R;
	float *datb;
	double *U;
	double *V;
	double *C;
	double *beta;
	double *m;
	double *inv_cov;
	double *L;
	int D;
	int N;
	int M;
	int K;
	double alpha;
	double alpha_R;
	int slice;
	int c;
	int num_thrd;
} matrix_lfmm;

/**
 * general multithreading function manager. Some parameters can be NULL
 *
 * @param R	data matrix
 * @param datb	data matrix
 * @param U	U matrix 
 * @param V	V matrix
 * @param C	covariable matrix
 * @param beta	beta matrix
 * @param m	true if missing data 
 * @param inv_cov	inverse of a covariance matrix
 * @param L	cholesky decomposition
 * @param K	the number of latent factors
 * @param D	the number of covariables
 * @param M	the number of loci
 * @param N	the number of individuals
 * @param num_thrd	the number of processes used
 * @param fct	the specific slice function
 * @param alpha	alpha parameter
 * @param alpha_R	alpha_R parameter
 */
void thread_fct_lfmm(float *R, float *datb, double *U, double *V, double *C,
		double *beta, double *m, double *inv_cov, double *L,
		int K, int D, int M, int N, int num_thrd, void (*fct) (),
		double alpha, double alpha_R);

#endif // THREAD_H
