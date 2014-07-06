/**
 * @addtogroup normalize
 * @ingroup matrix
 * @{
 *
 * @brief functions to normalize data and covariance matrices
 */

#ifndef NORMALIZE_H
#define NORMALIZE_H

/**
 * normalize C (means equal 0, var = 1) for each column
 *
 * @param C	the covariable matrix (of size, NxK)
 * @param N	the number of lines of C
 * @param K	the number of columns of C
 */
void normalize_cov(double *C, int N, int K);

/**
 * normalize C (means equal 0, var = 1) for each column 
 * with missing data equal 9 or -9
 *
 * @param C	the covariable matrix (of size, NxK)
 * @param N	the number of lines of C
 * @param K	the number of columns of C
 */
void normalize_cov_I(double *C, int N, int K);

/**
 * divide each line of A by the sum of the elements of this line
 *
 * @param A	the matrix to normalize (of size, NxM)
 * @param N	the number of lines of A
 * @param M	the number of columns of A
 */
void normalize_lines (double *A, int N, int M);


/**
 * center data for each column with missing data equal 9 or -9
 *
 * @param C	the covariable matrix (of size, NxK)
 * @param N	the number of lines of C
 * @param K	the number of columns of C
 */
void normalize_mean_I(double *C, int N, int K);

/**
 * center data for each column with missing data equal 9 or -9
 *
 * @param C	the covariable matrix (of size, NxK)
 * @param N	the number of lines of C
 * @param K	the number of columns of C
 */
void normalize_mean_I_float(float *C, int N, int K);

#endif // NORMALIZE_H

/** @} */