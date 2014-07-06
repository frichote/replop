/**
 * @addtogroup beta
 * @ingroup LFMM
 * @{
 *
 * @brief functions to update beta parameters in LFMM model.
 * 	The code is based on a previous matlab version. 
 *	Comments in matlab code format can be found in the code.
 */

#ifndef BETA_H
#define BETA_H
#include "data_lfmm.h"
#include "lfmm_algo.h"
#include "register_lfmm.h"

/**
 * compute the conditional mean for beta
 *
 * @param C	The covariable matrix (of size NxD)
 * @param R	the data matrix (of size NxM)
 * @param U	the U matrix (of size KxN)
 * @param V	the V matrix (of size KxM)
 * @param m_beta	the output beta mean matrix (of size DxM)
 * @param M	the number of loci
 * @param N	the number of individuals
 * @param D	the number of covariables
 * @param K	the number of latent factors
 * @param num_thrd	the number of processes used
 */
	/*
void create_m_beta(double *C, float *R, double *U, double *V, double *m_beta,
		   int M, int N, int D, int K, int num_thrd);
*/

/**
 * compute the C'*C in tmp
 *
 * @param cov	the output matrix (of size DxD)
 * @param C	the covariable matrix (of size NxD)
 * @param D	the number of covariables
 * @param N	the number of individuals
 */
// void create_CCt(double *cov, double *C, int D, int N);
 
/**
 * compute the inverse of the conditional covariance for beta
 *
 * @param inv_cov_beta	the output matrix (of size DxD)
 * @param alpha_beta	the vector of hyperparameters for beta (of size D)
 * @param alpha_R	the inverse of the residual variance
 * @param D	the number of covariables 
 * @param cov	C'*C previously calculated
 */
//void create_inv_cov_beta(double *inv_cov_beta, double *alpha_beta,
//			 double alpha_R, int D, double *cov);

/**
 * compute a realization of the conditional law for beta
 *
 * @param beta	the output beta realization (of size DxM)
 * @param m_beta	the conditional beta mean matrix (of size DxM)
 * @param inv_cov_beta	the conditional beta covariance matrix (of size DxD)
 * @param alpha_R	the inverse of the residual variance
 * @param D	the number of covariables 
 * @param M	the number of loci
 * @param num_thrd	the number of processes used
 */
//void rand_beta(double *beta, double *m_beta, double *inv_cov_beta,
//	       double alpha_R, int D, int M, int num_thrd);

/**
 * update beta matrix
 *
 * @param param 	parameter structure
 * @param GS_param 	GS parameter structure 
 */
void update_beta(LFMM_param param, LFMM_GS_param GS_param);

/**
 * update alpha_beta hyperparameters
 *
 * @param param 	parameter structure
 */
void update_alpha_beta(LFMM_param param); 

#endif // BETA_H

/** @} */
