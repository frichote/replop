/**
 * @addtogroup print_cds
 * @ingroup createDataSet
 * @{
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
 * @param[in] N     the number of individuals
 * @param[in] M     the number of loci
 * @param[in] m     ploidy (1 for haploid, 2 diploid, d d-ploid)
 * @param[in] seed	seed value
 * @param[in] e     percentage of missing data
 * @param[in] input         genotype file
 */
void print_summary_cds (int N, int M, int m, long long seed,
                        double e, char *input, char *output);

#endif // PRINT_CDS_H

/** @} */
