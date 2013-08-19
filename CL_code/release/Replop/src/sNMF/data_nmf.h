/**
 * @file data_nmf.h
 *
 * @brief set of functions to impute data
 */


#ifndef DATA_NMF_H
#define DATA_NMF_H

/**
 * input missing values with U'*V
 *
 * @param R     the data matrix (of size NxM)
 * @param U     the U matrix (of size KxN)
 * @param V     the V matrix (of size KxM)
 * @param I     the missing data matrix
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of clusters
 */
void inputation(float *R, double *U, double *V, int *I, int N, int M, int K);

/**
 * input missing values with allele frequency
 *
 * @param X     the data matrix (of size NxM)
 * @param I     the missing data matrix
 * @param N     the number of individuals
 * @param M     the number of loci
 * @param K     the number of clusters
 */
void freq_inputation(float *X, int *I, int N, int M);

#endif // DATA_NMF_H
