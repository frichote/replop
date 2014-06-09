/**
 * @file register_lfmm.h
 *
 * @brief functions to analyse command line
 */

#ifndef REGISTER_LFMM_H
#define REGISTER_LFMM_H

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc	the number of arguments
 * @param argv	the set of arguments
 * @param d	the numerous of the considered covariable
 * @param K	the number of latent factors
 * @param Niter	the number of iterations
 * @param burn	the number of burnin
 * @param m	true if missing data
 * @param output	the output file
 * @param input	the input file
 * @param cov_file	the covariable file
 * @param num_thrd	the number of processes used
 * @param s		seed value
 * @param all		boolean, true if all covariables at the same time
 */
void analyse_param_lfmm(int argc, char *argv[], int* d, int *K, int *Niter, int *burn,
		   int *m, char *output, char *input, char *cov_file,
		   int *num_thrd, long long *s, int *all);

#endif // REGISTER_LFMM_H
