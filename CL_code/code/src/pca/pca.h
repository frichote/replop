/**
 * @file pca.h
 *
 * @brief function for individual pca calculation
 */


#ifndef PCA_H
#define PCA_H

/**
 * run a pca 
 *
 * @param input_file	input file name
 * @param output_Q      the output file for eigenvalues
 * @param output_F      the output file for eigenvectors
 * @param K		number of ancestral populations
 * @param s		boolean: center
 * @param s		boolean: scale and center
 */
void pca(char* input_file, char *output_eva_file, char *output_eve_file,
        int K, int c, int s);

#endif // PCA_H
