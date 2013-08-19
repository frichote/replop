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
 * @param K     the number of latent factors
 * @param Niter the number of iterations in the GS
 * @param epsilon	the number of burnin iterations
 * @param m     boolean param, true if missing values
 * @param num_thrd      number of processes in parallel in the GS
 * @param output        output file
 * @param input         genotype file
 * @param g_data	????
 * @param gen_data	????
 */
void print_summary_snmf (     int N, int M, int m, long long seed, int K, double alpha,
                        double tol, int maxiter, char *input, int num_thread);

#endif // PRINT_SNMF_H
