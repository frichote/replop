/**
 * @file lfmm_algo.h
 *
 * @brief functions to compute lfmm parameters (zscores)
 */

#ifndef lfmm_ALGO_H
#define lfmm_ALGO_H

/**
 * calculate LFMM parameters
 *
 * @param dat   the data matrix (of size NxM)
 * @param I	missing data matrix
 * @param zscore	the output zscore matrix
 * @param U     the U matrix (of size KxN)
 * @param V     the V matrix (of size KxM)
 * @param alpha_U       the hyperparameter for U
 * @param alpha_R       the inverse of the residual variance
 * @param alpha_V       the hyperparameters for V
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 * @param epsilon       epsilon constant
 * @param Niter the number of iterations
 * @param burn  the number of burnin
 * @param missing_data	true if missing data
 * @param num_thrd      the number of processes used
 * @param dev_file	the name of the output DIC file
 */
void lfmm_emcmc(float *dat, int *I, double *zscore, double *U, double *V, 
		double *alpha_U, double *alpha_R, double *alpha_V, int N, 
		int M, int K, int D,
		double epsilon, int Niter, int burn, int missing_data,
		int num_thrd, char *dev_file);

/**
 * update different sums
 *
 * @param U	U (of size KpxN)
 * @param V	posterior V mean (of size KxM)
 * @param cov_X_U	temporary vector (sum) (of size KpxKp)
 * @param sum2_beta_V	temporary vector (sum of squares)(of size KpxM)
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_beta_V	posterior V mean (of size KpxM)
 * @param mean_cov_X_U	temporary vector (sum) (of size KpxKp)
 * @param deviance	deviance 
 * @param thrd_m2	???
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 * @param alpha_R       the inverse of the residual variance
 */
void update_sums(double *U, double *V, double *cov_X_U, double *sum2_beta_V,
                 double *mean_U, double *mean_beta_V, double *mean_cov_X_U, double *deviance,
                 double thrd_m2, int N, int M, int K, int D, double alpha_R);

/** 
 * update alpha_R
 * 
 * @param dat     the data matrix (of size NxM)
 * @param I	missing data matrix
 * @param U     the U matrix (of size KxN)
 * @param V     the V matrix (of size KxM)
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param Kp    the number of factors (K+D)
 * @param D     the number of covariables
 * @param thrd_m2	???
 * @param epsilon       epsilon constant
 * @param num_thrd      the number of processes used
 * @param missing_data	true if missing data
 */
double update_alpha_R(float* dat, int *I, double *U, double *V, int N, int M,
		      int Kp, double *thrd_m2, int num_thrd, int missing_data); 

/**
 * update dp and deviance
 *
 * @param dat     the data matrix (of size NxM)
 * @param U	  U (of size KpxM)
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_beta_V	posterior V mean (of size KpxM)
 * @param mean_cov_X_U	mean covariance of U
 * @param deviance	deviance
 * @param I	missing data matrix
 * @param missing_data	true if missing data
 * @param dp	???
 * @param size	numbre of iterations after burnin
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 * @param num_thrd      the number of processes used
 */
void calc_dp_deviance(float *dat, double *U, double *mean_U, double *mean_beta_V,
		      double *mean_cov_X_U, double *deviance, int *I, 
		      int missing_data, double *dp, int size, int N, int M, 
		      int K, int D, int num_thrd);

/**
 * allocate all temporary memory
 *
 * @param m_beta_V	conditional beta mean (of size (D+K)xM)
 * @param inv_cov_beta_V	inverse conditional beta covariance (of size (D+K)x(D+K))
 * @param m_X_U	conditional U mean (of size (D+K)xN)
 * @param inv_cov_X_U	inverse conditional U covariance (of size (K+D)x(K+D))
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_beta_V	posterior V mean (of size (K+D)xM)
 * @param sum2_beta_V	temporary vector of sum^2 of beta_V (of size (D+K)xM)
 * @param bb	temporary vector ??? (of size D)
 * @param cov_X_U	[C,U] covariance matrix (of size (D+K)x(D+K))
 * @param mean_cov_X_U	mean of [C,U] covariance matrix (of size (D+K)x(D+K))
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 */
void allocate_all(double **m_beta_V, double **inv_cov_beta_V, double **m_X_U,
		  double **inv_cov_X_U, double **mean_U, double **mean_beta_V,
		  double **sum2_beta_V, double **bb, double **cov_X_U, double **mean_cov_X_U, 
		  int N, int M, int K, int D);

/**
 * free all temporary memory
 *
 * @param m_beta_V	conditional beta mean (of size (D+K)xM)
 * @param inv_cov_beta_V	inverse conditional beta covariance (of size (D+K)x(D+K))
 * @param m_X_U	conditional U mean (of size (D+K)xN)
 * @param inv_cov_X_U	inverse conditional U covariance (of size (K+D)x(K+D))
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_beta_V	posterior V mean (of size (K+D)xM)
 * @param sum2_beta_V	temporary vector of sum^2 of beta_V (of size (D+K)xM)
 * @param bb	temporary vector ??? (of size D)
 * @param cov_X_U	[C,U] covariance matrix (of size (D+K)x(D+K))
 * @param mean_cov_X_U	mean of [C,U] covariance matrix (of size (D+K)x(D+K))
 */
void free_all(double *m_beta_V, double *inv_cov_beta_V, double *m_X_U,
                  double *inv_cov_X_U, double *mean_U, double *mean_beta_V,
                  double *sum2_beta_V, double *bb, double *cov_X_U, double *mean_cov_X_U);

#endif // lfmm_algo_H
