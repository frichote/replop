/**
 * @file register_pca.h
 *
 * @brief functions to read data matrices
 */

#ifndef REGISTER_PCA_H
#define REGISTER_PCA_H

/**
 * analyse command line set of parameters and set the parameters
 * 
 * @param argc  	the number of arguments
 * @param argv  	the set of arguments
 * @param input		the input file
 * @param output_eva	eigenvalues file	
 * @param output_eve	eigenvectors file	
 * @param K     	the number of clusters
 * @param c     	boolean: data centered
 * @param s     	boolean: data scaled
 */
void analyse_param_pca( int argc, char *argv[], char *input, char* output_eva,
                        char* output_eve, int *K, int *c, int *s);

#endif // REGISTER_PCA_H
