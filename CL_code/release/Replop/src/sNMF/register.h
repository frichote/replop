/**
 * @file register.h
 *
 * @brief functions to read data matrices
 */

#ifndef REGISTER_H
#define REGISTER_H

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc  the number of arguments
 * @param argv  the set of arguments
 * @param m     the number of alleles
 * @param K     the number of clusters
 * @param alpha	the value of parameter alpha
 * @param tol	tolerance 
 * @param iter the number of iterations
 * @param input	the input file
 * @param num_thrd      the number of processes used
 */
void analyse_param(	int argc, char *argv[], int *m, long long *s,
			int* K, double* alpha, double* tol,
			int *iter, char *input, int* num_thrd) ;

#endif // REGISTER_H
