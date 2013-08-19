/**
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
 * @param U     the V matrix (of size DxN)
 * @param R     the data matrix (of size NxM)
 * @param C     The covariable matrix (of size NxK)
 * @param beta  the beta matrix (of size KxM)
 * @param m_V   the output V mean matrix
 * @param M     the number of loci
 * @param N     the number of individuals
 * @param D     the number of covariables
 * @param K     the number of latent factors
 * @param datb  the data set
 * @param num_thrd      the number of processes used
 */
void create_m_V(double *U, float *R, double *C, double *beta, double *m_V,
		int M, int N, int D, int K, float *datb, int num_thrd);

/**
 * compute the inverse of the conditional covariance for V
 *
 * @param inv_cov_V  the output matrix (of size DxD)
 * @param alpha the hyperparameters for U
 * @param alpha_R       the inverse of the residual variance
 * @param V     the V matrix (of size DxM)
 * @param K     the number of latent factors 
 * @param M     the number of individuals
 * @param num_thrd      the number of processes used
 */
void create_inv_cov_V(double *inv_cov_V, double alpha, double alpha_R,
		      double *C, int K, int N, int num_thrd);

/**
 * compute a realization of the conditional law for V
 *
 * @param V     the output V realization (of size DxM)
 * @param m_V   the conditional V mean matrix (of size DxM)
 * @param inv_cov_V     the conditional V covariance matrix (of size DxD)
 * @param alpha_R       the inverse of the residual variance
 * @param K     the number of latent factors
 * @param M     the number of loci
 * @param num_thrd      the number of processes used
 */
void rand_V(double *V, double *m_V, double *inv_cov_V, double alpha_R, int K,
	    int M, int num_thrd);

/**
 * update V matrix
 *
 * @param C	the covariable matrix (of size NxK)
 * @param dat	the data matrix (of size NxM)
 * @param U	the U matrix (of size DxN)
 * @param V	the output V realization (of size DxM)
 * @param beta	the beta matrix (of size KxM)
 * @param m_V   the conditional V mean matrix (of size DxM)
 * @param inv_cov_V  	the conditional V covariance matrix (of size DxD)
 * @param alpha_V	the hyperparameter for V
 * @param alpha_R	the inverse of the residual variance
 * @param M	the number of loci
 * @param N	the number of covariables
 * @param K	the number of latent factors
 * @param D	the number of individuals
 * @param num_thrd	the number of processes used
 */
void update_V(double *C, float *dat, double *U, double *V, double *beta,
	      double *m_V, double *inv_cov_V, double alpha_V, double alpha_R,
	      int M, int N, int K, int D, int num_thrd);

#endif // V_H
