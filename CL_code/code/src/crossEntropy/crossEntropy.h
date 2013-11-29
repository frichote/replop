/**
 * @file crossEntropy.h
 *
 * @brief function for crossEntropy calculation
 */


#ifndef CROSSENTROPY_H
#define CROSSENTROPY_H

/**
 * compute cross Entropy criterion
 *  
 * @param input_file	input file name
 * @param input_file_I	file with masked genotypes used to calculate Q and F
 * @param input_file_Q	file with Q matrix
 * @param input_file_F	file with F matrix
 * @param K		number of ancestral populations
 * @param m		ploidy
 * @param all_ce	output all data cross-entropy
 * @param missing_ce	output masked data cross-entropy
 */
void crossEntropy(char* input_file, char* input_file_I, char* input_file_Q, char* input_file_F,
        int K, int m, double *all_ce, double *missing_ce);

#endif // CROSSENTROPY_H
