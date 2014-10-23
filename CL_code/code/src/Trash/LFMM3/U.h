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
 * @param V     the V matrix (of size KpxM)
 * @param R     the data matrix (of size NxM)
 * @param m_U   the output U mean matrix (KpxN)
 * @param M     the number of loci
 * @param N     the number of individuals
 * @param Kp     the number of latent factors + covariables
 * @param num_thrd      the number of processes used
 */
void create_m_U(double *V, float *R, double *m_U,
		int M, int N, int Kp, int num_thrd);

/**
 * compute the inverse of the conditional covariance for U
 *
 * @param inv_cov_U  	the output matrix (of size KpxKp)
 * @param cov_U  	the output matrix (of size KpxKp)
 * @param alpha_U 	the hyperparameters for U
 * @param alpha_R       the inverse of the residual variance
 * @param V	the V matrix (of size KxM)
 * @param K     the number of latent factors 
 * @param M     the number of loci 
 * @param num_thrd      the number of processes used
 */
void create_inv_cov_U(double *inv_cov_U, double *cov_U, double* alpha_U, 
		      double alpha_R, double *V, int Kp, int M, int num_thrd);

/**
 * compute a realization of the conditional law for U
 *
 * @param U  	the output U realization (of size KxN)
 * @param m_U   the conditional U mean matrix (of size KxN)
 * @param inv_cov_U  	the conditional U covariance matrix (of size KxK)
 * @param alpha_R       the inverse of the residual variance
 * @param K     the number of latent factors
 * @param D     the number of covariables
 * @param N     the number of individuals
 * @param num_thrd      the number of processes used
 */
void rand_U(double *U, double *m_U, double *inv_cov_U, double alpha_R, int K,
	    int D, int N, int num_thrd);

/**
 * update U matrix
 *
 * @param dat	the data matrix (of size NxM)
 * @param U	the output U realization (of size (K+D)xN)
 * @param V	the V matrix (of size (D+K)xM)
 * @param m_U   the conditional U mean matrix (of size (K+D)xN)
 * @param inv_cov_U  	the conditional U inverse covariance matrix (of size (K+D)x(K+D))
 * @param cov_U  	the conditional U covariance matrix (of size (K+D)x(K+D))
 * @param alpha_U	the hyperparameters for U (of size K+D)
 * @param alpha_R	the inverse of the residual variance
 * @param M	the number of loci
 * @param N	the number of individuals
 * @param K	the number of latent factors
 * @param D	the number of covariables
 * @param num_thrd	the number of processes used
 */
void update_U(float *dat, double *U, double *V, 
	      double *m_U, double *inv_cov_U, double *cov_U, double *alpha_U, 
		double alpha_R, int M, int N, int K, int D, int num_thrd);

/**
 * update alpha_U hyperparameter
 *
 * @param U	the U matrix (of size KxN)
 * @param alpha_U	the output hyperparameter for U
 * @param epsilon	epsilon constant
 * @param D	the number of variables
 * @param K	the number of latent factors
 * @param N	the number of individuals
 * @param M	the number of SNPs
 */
void update_alpha_U(double *U, double *alpha_U, double epsilon, int D, int K, 
	int N, int M);

#endif // U_H
