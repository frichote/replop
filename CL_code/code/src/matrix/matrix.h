/**
 * @file matrix.h
 *
 * @brief set of matrix operations
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <math.h>

/**
 * comparaison function of two elements (for qsort)
 *
 * @param a	first element
 * @param b	second element
 *
 * return a - b;
 */
int compare (const void* a, const void* b);

/**
 * return the indexes of data sorted (increasing order) (using qsort) 
 *
 * @param data	matrix to sort
 * @param index	indices 
 * @param n	size of data, index
 */
 void sort_index(long double *data, int *index, int n);

/**
 * comput min(a, b)
 * 
 * @param a 	first int
 * @param b	second int
 * 
 * @return min(a, b)
 */
int imin(int a, int b);

/**
 * comput max(a, b)
 * 
 * @param a 	first int
 * @param b	second int
 * 
 * @return max(a, b)
 */
int imax(int a, int b);

/**
 * calculate for each line k of A the squared sum (divided by 2) plus epsilon
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
 * transpose m (double) of size h x w (from Rosetta code)
 *
 * @param m	the matrix (hxw)
 * @param w	number of columns
 * @param h	number of lines
 */
void transpose_double (double *m, int w, int h);

/**
 * transpose m (float) of size h x w (from Rosetta code)
 *
 * @param m	the matrix (hxw)
 * @param w	number of columns
 * @param h	number of lines
 */
void transpose_float (float *m, int w, int h);

/**
 * transpose m (float) of size h x w (from Rosetta code)
 *
 * @param m	the matrix (hxw)
 * @param w	number of columns
 * @param h	number of lines
 */
void transpose_int (int *m, int w, int h);

#endif // MATRIX_H
