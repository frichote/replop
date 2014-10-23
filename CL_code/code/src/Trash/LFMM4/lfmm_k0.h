/**
 * @file lfmm_k0.h
 *
 * @brief functions to compute lfmm parameters (zscores) in case of K=0
 */

#ifndef lfmm_K0_H
#define lfmm_K0_H

/**
 * calculate LFMM parameters
 *
 * @param dat   the data matrix (of size NxM)
 * @param I	missing data matrix
 * @param C     The covariable matrix (of size NxD)
 * @param zscore	the output zscore matrix
 * @param beta  the beta matrix (of size DxM)
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param D     the number of covariables
 * @param missing_data	true if missing data
 * @param perc_var	percentage of variance
 */
void lfmm_k0(float *dat, int *I, double *C, double *zscore, double *beta,
		int N, int M, int D, int missing_data, double *perc_var);

#endif // lfmm_K0_H
