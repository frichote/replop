/**
 * @file LFMM.h
 *
 * @brief function for LFMM parameter calculation
 */


#ifndef LFMM_H
#define LFMM_H

/**
 * run LFMM
 *
 * @param input_file 	input file name
 * @param output_file	output file name
 * @param cov_file	covariable file name
 * @param dev_fiel	dev file name
 * @param n		number of individuals
 * @param L		number of loci
 * @param RD		number of env variables
 * @param nd		nd-th covariable to use 
 * @param K		number of latent factors
 * @param Niter		number of iterations in the GS
 * @param burn		number of burn-in iterations in the GS
 * @param num_thrd	number of process to use 
 * @param seed		seed value to init random
 * @param missing_data	true if missing data
 * @param all		true if run LFMM with all variables at once
 * @param dic		dic criterion
 * @param deviance 	deviance criterion
 */
void LFMM(char* input_file, char* output_file, char* cov_file, char* dev_file,
        int *n, int *L, int *RD, int nd, int K, int Niter, int burn, int num_thrd,
        long long *seed, int missing_data, int all, double *dic, double *deviance);

#endif // LFMM_H

