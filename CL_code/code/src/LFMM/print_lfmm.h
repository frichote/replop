/**
 * @file print.h
 *
 * @brief set of printing functions
 */

#ifndef PRINT_H
#define PRINT_H

/**
 * print the complete licence
 */
void print_licence_lfmm();

/**
 * print the header for the licence
 */
void print_head_licence_lfmm();

/**
 * print my header
 */
void print_head_lfmm();

/**
 * print the help
 */
void print_help_lfmm();

/**
 * print summary of the parameters
 *
 * @param N	the number of individuals
 * @param M	the number of loci
 * @param K	the number of latent factors
 * @param D	the number of covariables 
 * @param d	the d-th covariable
 * @param Niter the number of iterations in the GS
 * @param burn	the number of burnin iterations
 * @param m	boolean param, true if missing values
 * @param output 	output file
 * @param input		genotype file
 * @param cov_file	covariable file
 * @param dev_file	DIC file
 * @param num_thrd	number of processes in parallel in the GS
 * @param s  	seed value
 * @param all 	true if all variables at the same time
 */
void print_summary_lfmm(int N, int M, int K, int D, int d, int Niter, int burn,
		   int m, char *output, char *input, char *cov_file, char *dev_file,
		   int num_thrd, long long s, int all);

/**
 * print command line options 
 *
 * @param argc	the number of options 
 * @param argv	the set of arguments
void print_options_lfmm(int argc, char *argv[]);
 */

#endif // PRINT_H
