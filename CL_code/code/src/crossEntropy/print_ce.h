/**
 * @file print_ce.h
 *
 * @brief set of printing functions
 */


#ifndef PRINT_CE_H
#define PRINT_CE_H

/**
 * print my header
 */
void print_head_ce();

/**
 * print help
 */
void print_help_ce();

/**
 * print summary of the parameters
 *
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param m     boolean param, true if missing values
 * @param input         genotype file
 * @param input.Q         admixture file
 * @param input.F         frequency file
 * @param input_I         genotype file with masked genotypes
 */
void print_summary_ce ( int N, int M, int K, 
                        int m, char *input, char *input_Q, 
			char *input_F, char *input_I);

#endif // PRINT_CE_H
