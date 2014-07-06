/**
 * @addtogroup thread_var
 * @ingroup LFMM
 * @{
 *
 * @brief functions to compute new values for the variance
 *        (possibly multithreaded) 
 */

#ifndef THREAD_VAR_H
#define THREAD_VAR_H

#include "register_lfmm.h"
#include "lfmm_algo.h"

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
 * @param param		parameter structure
 * @param GS_param	GS parameter structure
 * @param fct		generic pointer function
 * @param res	the first res
 * @param res2	the second res
 */
void thrd_var(LFMM_param param, LFMM_GS_param GS_param, 
	      void (*fct) (), double *res, double *res2);

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

/** @} */
