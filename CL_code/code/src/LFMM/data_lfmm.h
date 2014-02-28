/**
 * @file data_lfmm.h
 *
 * @brief set of functions to manage data
 */

#ifndef DATA_LFMM_H
#define DATA_LFMM_H

#include "../matrix/data.h"

/** calculate lambda criterion of a p.values distribution
 *
 * @param p	p values set
 * @param n	size of p
 *
 * @return lambda
 */
double lambda(double *p, int n);

/**
 * convert pvalues into qvalues with Benjaminy-Hosberg approximation
 *
 * @param pvalues	pvalues table
 * @param qvalues	output qvalues table
 * @param n		size of the tables
 */
void pvalue_qvalue(double *pvalues, double *qvalues, int n);

/**
 * compute zscore in the dth column of beta
 * 
 * @param zscore	the output matrix of zscores (of size nxnD)
 * @param sum	the sum along the GS chain along for each individual (of size 2n)
 * @param sum2	the squared sum along the GS chain along for each individual (of size 2n)
 * @param n	the number of loci
 * @param cur	the length of the GS chain (without burnin)
 * @param D	number of lines of sum or sum2	
 */
void zscore_calc(double *zscore, double *sum, double *sum2, int n, int cur, int D);

/**
 * add beta to the sum, called sum
 *
 * @param beta	the values to add (of size n)
 * @param sum	where to add beta (of size n)
 * @param n	the size of sum and beta
 */
void update_sum(double *beta, double *sum, int n);

/**
 * add squared beta to the sum, sum
 *
 * @param beta	the values to add (of size n)
 * @param sum	where to add beta (of size n)
 * @param n	the size of sum and beta
 */
void update_sum2(double *beta, double *sum2, int n);

/**
 * update deviance parameter
 *
 * @param deviance	the parameter to update
 * @param cur	the current length of the GS chain
 * @param var	the variance
 * @param thrd_m	the current mean
 */
void update_deviance(double *deviance, int cur, double var, double thrd_m);

/**
 * update mean parameter
 *
 * @param mean	the parameter to update (of size n)
 * @param beta	the beta parameter to update the mean (of size n)
 * @param n	the length of mean and beta
 * @param cur	the current length of the GS chain
 */
void update_mean(double *beta, double *mean, int n, int cur);

/**
 * from column d of C (of size NxnD), create Cpp (of size Nx2) with 1 in first column and
 * the column d of C in second column
 *
 * @param C	the covariable parameter (of size NxnD)
 * @param N	the number of individuals
 * @param nD	the number of covariables
 * @param Cpp	the output parameter (of size Nx2)
 * @param d	the column of C to copy (from 0)
 * @param all	if all, copy all columns of C into Cpp
 */
void modify_C(double *C, int N, int nD, double *Cpp, int d, int all);

/**
 * write deviance and DIC in file_data file
 *
 * @param file_data	the file where to register
 * @param deviance	the deviance parameter
 * @param DIC	the DIC parameter
 */
void write_DIC(char *file_data, double deviance, double DIC);

/**
 * compute and write absolute zscore, -log10(pvalue) and pvalue into file_data with %G 
 * separated by spaces
 *
 * @param file_data	the file where to write
 * @param M		the number of snps (of lines of dat) 
 * @param zscore	zscore matrix
 * @param D		D number of environmental variables
 * @param all		if all variables together
 * @param nd		number of the current env variable
 * @param K		number of latent factors
 * @param N		number of individuals
 * @param dev		deviance
 * @param DIC		DIC
 */
void write_zscore_double(char *output_file, int M, double *zscore, int D, int all, 
	int nd, int K, int N, double dev, double DIC, double *perc_var);

/**
 * compute the current residual variance
 *
 * @param R	the data matrix (of size NxM)
 * @param U	the U matrix (of size KxN)
 * @param V	the V matrix (of size KxM)
 * @param C	the C matrix (of size NxD)
 * @param beta	the beta parameter (of size DxM)
 * @param N	the number of individuals
 * @param M	the number of loci
 * @param D	the number of covariables
 * @param K	the number of latent factors
 * @param thrd_m2	the output value of the mean
 * @param num_thrd	the number of thread used
 */
double var_data(float *R, double *U, double *V, double *C, double *beta, int N,
		int M, int K, int D, double *thrd_m2, int num_thrd);


/**
 * compute the current residual variance and input missing data
 *
 * @param R	the data matrix (of size NxM)
 * @param I     the missing data matrix
 * @param U	the U matrix (of size KxN)
 * @param V	the V matrix (of size KxM)
 * @param C	the C matrix (of size NxD)
 * @param beta	the beta parameter (of size DxM)
 * @param N	the number of individuals
 * @param M	the number of loci
 * @param D	the number of covariables
 * @param K	the number of latent factors
 * @param thrd_m2	the output value of the mean
 * @param num_thrd	the number of thread used
 */
double var_data_inputation(float *R, int *I, double *U, double *V, double *C, 
	double *beta, int N, int M, int K, int D, double *thrd_m2, int num_thrd);

/**
 * input missing values with U'*V+C*beta
 *
 * @param R     the data matrix (of size NxM)
 * @param U     the U matrix (of size DxN)
 * @param V     the V matrix (of size DxM)
 * @param C     the C matrix (of size NxK)
 * @param beta  the beta parameter (of size KxM)
 * @param I     the missing data matrix
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param D     the number of covariables
 * @param K     the number of latent factors
 */
void inputation_lfmm(float *R, double *U, double *V, double *C, double *beta, int *I,
		int N, int M, int K, int D);

/**
 * input missing values with empirical frequencies
 *
 * @param R     the data matrix (of size NxM)
 * @param I     the missing data matrix
 * @param N     the number of individuals
 * @param M     the number of loci
 */
void inputation_freq(float *R, int *I, int N, int M);

#endif // DATA_LFMM_H
