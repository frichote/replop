/**
 * @file U.h
 *
 * @brief functions to update U parameters in LFMM model
 */

#ifndef U_H
#define U_H
#include "data_lfmm.h"

/**
 * compute the conditional mean for U
 *
 * @param V     the V matrix (of size KxM)
 * @param R     the data matrix (of size NxM)
 * @param C     The covariable matrix (of size NxD)
 * @param beta	the beta matrix (of size DxM)
 * @param m_U   the output U mean matrix (KxN)
 * @param M     the number of loci
 * @param N     the number of individuals
 * @param D     the number of covariables
 * @param K     the number of latent factors
 * @param num_thrd      the number of processes used
 */
void create_m_U(double *V, float *R, double *C, double *beta, double *m_U,
		int M, int N, int D, int K, int num_thrd);

/**
 * compute the inverse of the conditional covariance for U
 *
 * @param inv_cov_U  the output matrix (of size KxK)
 * @param alpha the hyperparameters for U
 * @param alpha_R       the inverse of the residual variance
 * @param V	the V matrix (of size KxM)
 * @param K     the number of latent factors 
 * @param M     the number of loci 
 * @param num_thrd      the number of processes used
 */
void create_inv_cov_U(double *inv_cov_U, double alpha, double alpha_R,
		      double *V, int K, int M, int num_thrd);

/**
 * compute a realization of the conditional law for U
 *
 * @param U  	the output U realization (of size KxN)
 * @param m_U   the conditional U mean matrix (of size KxN)
 * @param inv_cov_U  	the conditional U covariance matrix (of size KxK)
 * @param alpha_R       the inverse of the residual variance
 * @param K     the number of latent factors
 * @param N     the number of individuals
 * @param num_thrd      the number of processes used
 */
void rand_U(double *U, double *m_U, double *inv_cov_U, double alpha_R, int K,
	    int N, int num_thrd);

/**
 * update U matrix
 *
 * @param C	the covariable matrix (of size NxD)
 * @param dat	the data matrix (of size NxM)
 * @param U	the output U realization (of size KxN)
 * @param V	the V matrix (of size DxM)
 * @param beta	the beta matrix (of size KxM)
 * @param m_U   the conditional U mean matrix (of size KxN)
 * @param inv_cov_U  	the conditional U covariance matrix (of size KxK)
 * @param alpha_U	the hyperparameter for U
 * @param alpha_R	the inverse of the residual variance
 * @param M	the number of loci
 * @param N	the number of individuals
 * @param K	the number of latent factors
 * @param D	the number of covariables
 * @param num_thrd	the number of processes used
 */
void update_U(double *C, float *dat, double *U, double *V, double *beta,
	      double *m_U, double *inv_cov_U, double alpha_U, double alpha_R,
	      int M, int N, int K, int D, int num_thrd);

/**
 * update alpha_U hyperparameter
 *
 * @param U	the U matrix (of size KxN)
 * @param alpha_U	the output hyperparameter for U
 * @param epsilon	epsilon constant
 * @param K	the number of latent factors
 * @param N	the number of individuals
 */
void update_alpha_U(double *U, double *alpha_U, double epsilon, int K, int N);

#endif // U_H
