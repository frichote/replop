/**
 * @file register_ce.h
 *
 * @brief functions to read data matrices
 */

#ifndef REGISTER_CE_H
#define REGISTER_CE_H

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc  the number of arguments
 * @param argv  the set of arguments
 * @param m     the number of alleles
 * @param K     the number of clusters
 * @param input	the input file
 */
void analyse_param_ce(	int argc, char *argv[], int *m,
			int* K, char *input) ;

#endif // REGISTER_CE_H
