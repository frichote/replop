/**
 * @file print_pca.h
 *
 * @brief set of printing functions
 */


#ifndef PRINT_PCA_H
#define PRINT_PCA_H

/**
 * print help
 */
void print_help_pca();


/**
 * print summary of the parameters
 *
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of latent factors
 * @param s	data scaled (boolean)
 * @param input         genotype file
 * @param input_values  eigenvalues file
 * @param input_vectors eigenvectors file
 */
void print_summary_pca( int N, int M, int K, int s,
                        char *input, char *output_values,
                        char *output_vectors);    

#endif // PRINT_PCA_H
