/**
 * @file register_cds.h
 *
 * @brief functions to read data matrices
 */

#ifndef REGISTER_CDS_H
#define REGISTER_CDS_H

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc  the number of arguments
 * @param argv  the set of arguments
 * @param m     the number of alleles
 * @param s     seed
 * @param e	percentage of genotypes to remove
 * @param input	the input file
 */
void analyse_param_cds(	int argc, char *argv[], int *m, long long *s,
			double *e, char *input) ;

#endif // REGISTER_CDS_H
