/**
 * @file data.h
 *
 * @brief set of functions to manage data
 */

#ifndef DATA_H
#define DATA_H

#define SEP " "			// Séparateur utilisé dans le fichier

/**
 * set A to 0
 *
 * @param A	the matrix A (of size n)
 * @param n	the size of A
 */
void zeros(double *A, int n);

/**
 * check if column nd of A contains NaN elements
 * 
 * @param A	the matrix A (of size nxnD)
 * @param n	the number of lines of A
 * @param nd	the column of A to check
 * @param nD	the number of columns of A
 *
 * @return true if the column nd of A contains Nan element
 */
int check_mat(double *A, int n, int nd, int nD);

/**
 * divide all elements of beta by nb
 *
 * @param beta	the matrix to divide (of size n)
 * @param n	the size of beta
 * @param nb	the divisor
 */
void update_m(double *beta, int n, int nb);

/**
 * create I the missing matrix from dat
 *
 * @param dat	the data matrix (of size NxM)
 * @param I	the missing matrix (of size NxM), equals 0 if dat equals -9, 0 otherwise
 * @param N	the number of lines of dat
 * @param M	the number of columns of dat
 */
void create_I(float *dat, int *I, int N, int M);

/**
 * write dat into file_data with %G separated by spaces
 *
 * @param file_data	the file where to write
 * @param N	the number of lines of dat
 * @param M	the number of columns of dat
 * @param dat	the matrix to write
 */
void write_data_float(char *file_data, int N, int M, float *dat);

/**
 * write dat into file_data with %G separated by spaces
 *
 * @param file_data	the file where to write
 * @param N	the number of lines of dat
 * @param M	the number of columns of dat
 * @param dat	the matrix to write
 */
void write_data_int(char *file_data, int N, int M, int *dat);

/**
 * write dat into file_data with %G separated by spaces
 *
 * @param file_data	the file where to write
 * @param N	the number of lines of dat
 * @param M	the number of columns of dat
 * @param dat	the matrix to write
 */
void write_data_double(char *file_data, int N, int M, double *dat);

/**
 * print dat
 *
 * @param dat	the matrix to write
 * @param N	the number of lines of dat
 * @param M	the number of columns of dat
 */
void print_data(float *dat, int N, int M);

/**
 * remove constant columns from dat
 *
 * @param dat	the data matrix (of size NxM)
 * @param col	the list of constant columns (of size M)
 * @param N	the number of lines of dat
 * @param M	the number of columns of dat
 * @param nM	true if dat contains missing data 
 */
void clean_data(float *dat, int *col, int N, int M, int n);

#endif // DATA_H
