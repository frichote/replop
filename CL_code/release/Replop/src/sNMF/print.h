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
void print_licence();

/**
 * print the header for the licence
 */
void print_head_licence();

/**
 * print my header
 */
void print_head();

/**
 * print help
 */
void print_help();

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
void print_summary (     int N, int M, int m, long long seed, int K, double alpha,
                        double tol, int maxiter, char *input, int num_thread);

#endif // PRINT_H
