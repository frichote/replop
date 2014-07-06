/**
 * @addtogroup thread_lfmm
 * @ingroup LFMM
 * @{
 *
 * @brief general function and structure to manage multithreading
 */

#ifndef THREAD_LFMM_H
#define THREAD_LFMM_H

/**
 * structure to manage multithreading
 */
typedef struct _matrix_lfmm *Matrix_lfmm;

typedef struct _matrix_lfmm {
	float *R;
	double *A;
	double *B;
	double *C;
	double *m;
	double *inv_cov;
	double *L;
	int J;
	int N;
	int M;
	int K;
	double* alpha;
	double alpha_R;
	int slice;
	int c;
	int num_thrd;
} matrix_lfmm;

/**
 * general multithreading function manager. Some parameters can be NULL
 *
 */
void thread_fct_lfmm(float *R, double *A, double *B, double *C, double *m,
	double *inv_cov, double *L, int J, int K, int N, int M, double *alpha,
	double alpha_R, int num_thrd, void (*fct) ());

#endif // THREAD_H

/** @} */
