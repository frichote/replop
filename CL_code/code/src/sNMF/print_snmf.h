/**
 * @file print_snmf.h
 *
 * @brief set of printing functions for snmf program
 */


#ifndef PRINT_SNMF_H
#define PRINT_SNMF_H

/**
 * print the complete licence
 */
void print_licence_snmf();

/**
 * print the header for the licence
 */
void print_head_licence_snmf();

/**
 * print my header
 */
void print_head_snmf();

/**
 * print help
 */
void print_help_snmf();

/**
 * print summary of the parameters
 *
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param m     boolean param, true if missing values
 * @param seed	seed random init
 * @param K     the number of latent factors
 * @param alpha	regularization parameter
 * @param tol 	tolerance parameter
 * @param maxiter	maximum number of iterations
 * @param input         genotype file
 * @param num_thread    number of processes
 * @param e	percentage of masked genotypes
 * @param output_Q	output individual admixture file
 * @param output_F	output ancestral frequencies file
 */
void print_summary_snmf (     int N, int M, int m, long long seed, int K, double alpha,
                        double tol, int maxiter, char *input, int num_thread, double e,
			char *output_Q, char *output_F);

#endif // PRINT_SNMF_H
