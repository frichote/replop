/**
 * @addtogroup V
 * @ingroup LFMM
 * @{
 * @file V.h
 *
 * @brief functions to update V parameters in LFMM model
 */

#ifndef V_H
#define V_H
#include "data_lfmm.h"

/**
 * compute the conditional mean for V
 *
 * @param U     the V matrix (of size KxN)
 * @param R     the data matrix (of size NxM)
 * @param C     The covariable matrix (of size NxD)
 * @param beta  the beta matrix (of size DxM)
 * @param m_V   the output V mean matrix (of size KxM)
 * @param M     the number of loci
 * @param N     the number of individuals
 * @param D     the number of covariables
 * @param K     the number of latent factors
 * @param num_thrd      the number of processes used
 */
/*	
void create_m_V(double *U, float *R, double *C, double *beta, double *m_V,
		int M, int N, int D, int K, int num_thrd);
*/	

/**
 * compute the inverse of the conditional covariance for V
 *
 * @param inv_cov_V  the output matrix (of size KxK)
 * @param alpha the hyperparameters for U
 * @param alpha_R       the inverse of the residual variance
 * @param V     the V matrix (of size KxM)
 * @param K     the number of latent factors 
 * @param M     the number of individuals
 * @param num_thrd      the number of processes used
 */
//void create_inv_cov_V(double *inv_cov_V, double alpha, double alpha_R,
//		      double *C, int K, int N, int num_thrd);

/**
 * compute a realization of the conditional law for V
 *
 * @param V     the output V realization (of size KxM)
 * @param m_V   the conditional V mean matrix (of size KxM)
 * @param inv_cov_V     the conditional V covariance matrix (of size KxK)
 * @param alpha_R       the inverse of the residual variance
 * @param K     the number of latent factors
 * @param M     the number of loci
 * @param num_thrd      the number of processes used
 */
//void rand_V(double *V, double *m_V, double *inv_cov_V, double alpha_R, int K,
//	    int M, int num_thrd);

/**
 * update V matrix
 *
 * @param param         parameter structure
 * @param GS_param      GS parameter structure
 */
void update_V(LFMM_param param, LFMM_GS_param GS_param); 

#endif // V_H

/** @} */
