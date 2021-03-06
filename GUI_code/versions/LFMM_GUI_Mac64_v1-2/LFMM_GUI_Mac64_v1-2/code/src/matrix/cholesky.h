/**
 * @file cholesky.h
 *
 * @brief function to compute the upper cholesky decomposition of a matrix
 */

#ifndef CHOLESKY_H
#define CHOLESKY_H

/**
 * compute the upper cholesky decomposite L of A
 *
 * @param A	the matrix to decompose (of size nxn)
 * @param n	the size of columns/lines of A
 * @param L	the output cholesky decomposition
 */
void cholesky(double *A, int n, double *L);

#endif // CHOLESKY_H
