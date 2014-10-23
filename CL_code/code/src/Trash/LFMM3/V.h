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
 * @param U     the V matrix (of size KxN)
 * @param R     the data matrix (of size NxM)
 * @param m_V   the output V mean matrix (of size KxM)
 * @param M     the number of loci
 * @param N     the number of individuals
 * @param Kp     the number of latent factors + covariables
 * @param num_thrd      the number of processes used
 */
void create_m_V(double *U, float *R, double *m_V, int M, int N, int Kp, int num_thrd);

/**
 * compute the inverse of the conditional covariance for V
 *
 * @param inv_cov_V  the output matrix (of size KxK)
 * @param alpha_V the hyperparameters for V
 * @param alpha_R       the inverse of the residual variance
 * @param V     the V matrix (of size KxM)
 * @param Kp     the number of latent factors + covariables
 * @param M     the number of individuals
 * @param num_thrd      the number of processes used
 */
void create_inv_cov_V(double *inv_cov_V, double* alpha_V, double alpha_R,
		      double *C, int K, int N, int num_thrd);

/**
 * compute a realization of the conditional law for V
 *
 * @param V     the output V realization (of size KxM)
 * @param m_V   the conditional V mean matrix (of size KxM)
 * @param inv_cov_V     the conditional V covariance matrix (of size KxK)
 * @param alpha_R       the inverse of the residual variance
 * @param Kp     the number of latent factors + covariables
 * @param M     the number of loci
 * @param num_thrd      the number of processes used
 */
void rand_V(double *V, double *m_V, double *inv_cov_V, double alpha_R, int Kp,
	    int M, int num_thrd);

/**
 * update V matrix
 *
 * @param dat	the data matrix (of size NxM)
 * @param U	the U matrix (of size (K+D)xN)
 * @param V	the output V realization (of size (K+D)xM)
 * @param m_V   the conditional V mean matrix (of size (K+D)xM)
 * @param inv_cov_V  	the conditional V covariance matrix (of size (K+D)x(K+D))
 * @param alpha_V	the hyperparameters for V (of size K+D)
 * @param alpha_R	the inverse of the residual variance
 * @param M	the number of loci
 * @param N	the number of covariables
 * @param K	the number of latent factors
 * @param D	the number of individuals
 * @param num_thrd	the number of processes used
 */
void update_V(float *dat, double *U, double *V,
	      double *m_V, double *inv_cov_V, double* alpha_V, double alpha_R,
	      int M, int N, int K, int D, int num_thrd);

/**
 * update alpha_V hyperparameters
 *
 * @param V  the V realization (of size (K+D)xM)
 * @param alpha_V    the output vector of hyperparameters for beta (of size K+D)
 * @param epsilon       epsilon constant
 * @param D     the number of covariables
 * @param K     the number of factors
 * @param N     the number of individuals
 * @param M     the number of loci
 */
void update_alpha_V(double *V, double *alpha_V, double epsilon,
                int D, int K, int N, int M);
#endif // V_H
