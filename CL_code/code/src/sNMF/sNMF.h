/**
 * @addtogroup sNMF
 * @ingroup sNMF
 * @{
 *
 * @brief function for sNMF paramater calculation
 */


#ifndef SNMF_H
#define SNMF_H

/**
 * run sNMF 
 *
 * @param input_file	input file name
 * @param K		number of ancestral populations
 * @param alpha		regularization parameter
 * @param tol		
 * @param e     cross-entropy percentage
 * @param iter the number of iterations
 * @param input the input file
 * @param num_thrd      the number of processes used
 * @param input_Q       the input file for Q
 * @param output_Q      the output file for Q
 * @param output_F      the output file for F
 * @param I		initialization of Q with I SNPs
 * @param all_ce	cross-entropy of all data
 * @param masked_ce	cross-entropy of masked data
 * @param n		number of individuals
 * @param L		number of loci
 */

void sNMF(char* input_file, int K, double alpha, double tol, double e, int maxiter, 
	long long* seed, int m, int num_thrd, char* input_file_Q, char* output_file_Q, 
	char* output_file_F, int I, double *all_ce, double *masked_ce, int *n, int *L);

#endif // SNMF_H

/** @} */