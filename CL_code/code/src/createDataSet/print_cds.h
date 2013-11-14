/**
 * @file print_cds.h
 *
 * @brief set of printing functions
 */


#ifndef PRINT_CDS_H
#define PRINT_CDS_H

/**
 * print help
 */
void print_help_cds();

/**
 * print summary of the parameters
 *
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param m     ploidy (1 for haploid, 2 diploid, d d-ploid)
 * @param seed	seed value
 * @param e     percentage of missing data
 * @param input         genotype file
 */
void print_summary_cds (int N, int M, int m, long long seed,
                        double e, char *input, char *output);

#endif // PRINT_CDS_H
