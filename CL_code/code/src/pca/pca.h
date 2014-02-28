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
 * @param input_file		input file name
 * @param output_eva_file       the output file for eigenvalues
 * @param output_eve_file       the output file for eigenvectors
 * @param output_sdev_file      the output file for standard deviation
 * @param output_x_file         the output file for x
 * @param K			number of PCs
 * @param s			boolean: center
 * @param s			boolean: scale and center
 */
void pca(char* input_file, char *output_eva_file, char *output_eve_file,
	char *output_sdev_file, char *output_x_file,
        int K, int c, int s);

#endif // PCA_H
