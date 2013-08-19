/**
 * @file normalize.h
 *
 * @brief functions to normalize data and covariance matrices
 */

#ifndef NORMALIZE_H
#define NORMALIZE_H

/**
 * normalize data (means equal 0 and variances equal 1)
 *
 * @param data	the data matrix (of size, NxM)
 * @param N	the number of lines of data
 * @param M	the number of columns of data
 * @param I	the missing data matrix (of size, NxM)
 * @param missing_data	true if data contains missing data
 */
void normalize_data(float *data, int N, int M, int *I, int missing_data);

/**
 * normalize C (means equal 0)
 *
 * @param C	the covariable matrix (of size, NxK)
 * @param N	the number of lines of C
 * @param K	the number of columns of C
 */
void normalize_cov(double *C, int N, int K);

/**
 * divide each line of A by the sum of the elements of this line
 *
 * @param A	the matrix to normalize (of size, NxM)
 * @param N	the number of lines of A
 * @param M	the number of columns of A
 */
void normalize_lines(double *A, int N, int M);

/**
 * divide each column of F by the sum of the elements of this line
 *
 * @param F	the matrix to normalize (of size, KxM)
 * @param K	the number of lines of F
 * @param M	the number of columns of F
 */
void normalize_cols(double *F, int K, int M);

#endif // NORMALIZE_H
