/**
 * @file matrix.h
 *
 * @brief set of matrix operations
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <math.h>

/**
 * test if the two matrices A & B are equal (of size n)
 * 
 * @param A	the first matrix (of size n)
 * @param B	the second matrix (of size n)
 * @param n	the size of the matrices
 *
 * @return true if A == B 
 */
int diff_int(int *A, int *B, int n);

/**
 * calculate the absolute difference between the two matrices A and B
 * print the absolute difference divided by the number of elements
 * 
 * @param A	the first matrix (of size n)
 * @param B	the second matrix (of size n)
 * @param n	the size of the matrices
 *
 * @return sum of absolute differences between A and B 
 */
double diff(double *A, double *B, int n);

/**
 * set all values of matrix A to 1
 *
 * @param A	the matrix (of size n)
 * @param n	the size of A
 */
void ones(float *A, int size);

/**
 * calculate for each line k of A the squared sum divided by 2 plus epsilon
 * 
 * @param A	the matrix (of size (KxM)
 * @param K	the number of lines of A
 * @param M	the number of columns of A
 * @param res	the output vector (of size K)
 * @param epsilon	the value of epsilon
 */
void dble_sum2(double *A, int K, int M, double *res, double epsilon);

/**
 * calculate the squared sum of A
 *
 * @param A 	the matrix (of size, size)
 * @param size 	the size of A
 * 
 * @return the squared sum
 */
double dble_sum(double *A, int size);

/**
 * copy vector in into vector out
 *
 * @param in 	vector to copy (of size, size)
 * @param out	vector to copy in (of size, size)
 * @param size	size of in and out
 */
void copy_vect(double *in, double *out, int size);

/**
 * compute the product a*b in res
 *
 * @param a	the first matrix (of size, sizexsize)
 * @param b	the second matrix (of size, sizexsize)
 * @param res	the output matrix (a*b) (of size, sizexsize)
 * @param size	the number of lines/columns of all matrices
 */
void basic_prod(float *a, float *b, float *res, int size);

/**
 * compute the highest value between all values of v and max
 * 
 * @param v	the vector of possible values (of size n)
 * @param n	the size of v
 * @param max	the value to compare
 *
 * @return the maximum value
 */
int vect_max(int *v, int n, int max);

/**
 * compute the lowest value between all values of v and min
 * 
 * @param v	the vector of possible values (of size n)
 * @param n	the size of v
 * @param min	the value to compare
 *
 * @return the minimum value
 */
int vect_min(int *v, int n, int min);

/**
 * compute the maximum of a and b
 * 
 * @param a	the first integer
 * @param b	the second integer
 *
 * return the maximum
 */
int imax(int a, int b);

/**
 * compute the minimum of a and b
 * 
 * @param a	the first integer
 * @param b	the second integer
 *
 * return the minimum
 */
int imin(int a, int b);

/**
 * compute the product alpha.*(A*A) (all of sizes, nxn)
 *
 * @param A	the first matrix (of size nxn)
 * @param B	the second matrix (of size nxn)
 * @param n	the number of lines/columns of all matrices
 * @param alpha	the multiplicative constant
 * 
 * @return the output matrix
 */
float *prod(float *A, float *B, int n, float alpha);

/** compute the norm 1 of A minus B
 *
 * @param A	the first matrix (of size nxn)
 * @param B	the second matrix (of size nxn)
 * @param n	the number of lines/columns of all matrices
 *
 * @return the norm 1
 */
float norm_1(float *A, float *B, int n);

/**
 * print the char matrix out of size (N/4)xM
 *
 * @param out     the matrix ((N/4)xM)
 * @param N     number of lines
 * @param M     number of columns
 */
void print_char_optim(unsigned char *out, int N, int M);

/**
 * print the double matrix A of size NxM
 *
 * @param A     the matrix (NxM)
 * @param N     number of lines
 * @param M     number of columns
 */
void print_mat(double *A, int N, int M);

/**
 * optimized multiplication C = A*B (to use if tested)
 *
 * @param A	matrix (of size NxK)
 * @param B	matrix (of size KxM)
 * @param C	matrix (of size NxM)
 * @param M	size
 * @param N	size
 * @param K	size
 */
void optim_mult(double *A, double *B, double *C, int M, int N, int K);

void transpose_double (double *A, int K, int N);

void transpose_float (float *A, int K, int N);

void transpose_int (int *A, int K, int N);

#endif // MATRIX_H
