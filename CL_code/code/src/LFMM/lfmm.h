/**
 * @file lfmm.h
 *
 * @brief functions to compute lfmm parameters (zscores)
 */

#ifndef LFMM_H
#define LFMM_H

/**
 * calculate LFMM parameters
 *
 * @param dat   the data matrix (of size NxM)
 * @param I	missing data matrix
 * @param C     The covariable matrix (of size NxD)
 * @param zscore	the output zscore matrix
 * @param beta  the beta matrix (of size DxM)
 * @param U     the U matrix (of size KxN)
 * @param V     the V matrix (of size KxM)
 * @param alpha_beta    the vector of hyperparameters for beta (of size D)
 * @param alpha_R       the inverse of the residual variance
 * @param alpha_U       the hyperparameter for U
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 * @param epsilon       epsilon constant
 * @param Niter the number of iterations
 * @param burn  the number of burnin
 * @param missing_data	true if missing data
 * @param num_thrd      the number of processes used
 * @param output_file	the name of the output zscore file
 * @param dev_file	the name of the output DIC file
 */
void lfmm_emcmc(float *dat, int *I, double *C, double *zscore, double *beta,
		double *U, double *V, double *alpha_beta, double *alpha_R,
		double *alpha_U, int N, int M, int K, int D,
		double epsilon, int Niter, int burn, int missing_data,
		int num_thrd, char *output_file, char *dev_file);

/**
 * update different sums
 *
 * @param beta	posterior beta mean (of size DxM)
 * @param U	posterior U mean (of size KxN)
 * @param V	posterior V mean (of size KxM)
 * @param sum2	temporary vector (of size DxM)
 * @param sum	temporary vector (of size DxM)
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_V	posterior V mean (of size KxM)
 * @param deviance	deviance 
 * @param thrd_m2	??
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 * @param alpha_R       the inverse of the residual variance
 */
void update_sums(double *beta, double *U, double *V, double *sum, double *sum2,
		 double *mean_U, double *mean_V, double *deviance,
		 double thrd_m2, int N, int M, int K, int D, double alpha_R);

/**
 * update dp and deviance
 *
 * @param dat     the data matrix (of size NxM)
 * @param sum	posterior beta mean (of size DxM)
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_V	posterior V mean (of size KxM)
 * @param C     The covariable matrix (of size NxD)
 * @param deviance	deviance
 * @param dp	???
 * @param size	numbre of iterations after burnin
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 */
void calc_dp_deviance(float *dat, double *sum, double *mean_U, double *mean_V,
		      double *C, double *deviance, double *dp, int size, int N,
		      int M, int K, int D, int num_thrd);

/**
 * allocate all temporary memory
 *
 * @param m_beta	conditional beta mean (of size DxM)
 * @param inv_cov_beta	inverse conditional beta covariance (of size DxD)
 * @param m_U	conditional U mean (of size KxN)
 * @param inv_cov_U	inverse conditional U covariance (of size KxK)
 * @param m_V	conditional V mean (of size KxM)
 * @param inv_cov_V	inverse conditional V covariance (of size KxK)
 * @param mean	posterior beta mean (of size DxM)
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_V	posterior V mean (of size KxM)
 * @param sum2	temporary vector ??? (of size DxM)
 * @param sum	temporary vector ??? (of size DxM)
 * @param bb	temporary vector ??? (of size D)
 * @param CCt	C covariance matrix (of size DxD)
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param D     the number of covariables
 */
void allocate_all(double **m_beta, double **inv_cov_beta, double **m_U,
		  double **inv_cov_U, double **m_V, double **inv_cov_V,
		  double **mean, double **mean_U, double **mean_V,
		  double **sum2, double **sum, double **bb, double **CCt, int N,
		  int M, int K, int D);

/**
 * free all temporary memory
 *
 * @param m_beta	conditional beta mean (of size DxM)
 * @param inv_cov_beta	inverse conditional beta covariance (of size DxD)
 * @param m_U	conditional U mean (of size KxN)
 * @param inv_cov_U	inverse conditional U covariance (of size KxK)
 * @param m_V	conditional V mean (of size KxM)
 * @param inv_cov_V	inverse conditional V covariance (of size KxK)
 * @param mean	posterior beta mean (of size DxM)
 * @param mean_U	posterior U mean (of size KxN)
 * @param mean_V	posterior V mean (of size KxM)
 * @param sum2	temporary vector ??? (of size DxM)
 * @param sum	temporary vector ??? (of size DxM)
 * @param bb	temporary vector ??? (of size D)
 * @param CCt	C covariance matrix (of size DxD)
 */
void free_all(double *m_beta, double *inv_cov_beta, double *m_U,
	      double *inv_cov_U, double *m_V, double *inv_cov_V, double *mean,
	      double *mean_U, double *mean_V, double *sum2, double *sum,
	      double *bb, double *CCt);

#endif // LFMM_H
