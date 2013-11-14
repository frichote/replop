/**
 * @file register_snmf.h
 *
 * @brief functions to read command line
 */

#ifndef REGISTER_SNMF_H
#define REGISTER_SNMF_H

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc  the number of arguments
 * @param argv  the set of arguments
 * @param m     the number of alleles
 * @param K     the number of clusters
 * @param alpha	the value of parameter alpha
 * @param tol	tolerance 
 * @param e	cross-entropy percentage
 * @param iter the number of iterations
 * @param input	the input file
 * @param num_thrd      the number of processes used
 * @param output_Q	the output file for Q
 * @param output_F	the output file for F
 */
void analyse_param_snmf(int argc, char *argv[], int *m, long long *s,
			int* K, double* alpha, double* tol, double *e,
			int *iter, char *input, int* num_thrd,
			char* output_Q, char* output_F);

#endif // REGISTER_SNMF_H
