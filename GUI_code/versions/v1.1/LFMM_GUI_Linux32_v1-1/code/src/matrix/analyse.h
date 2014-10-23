/**
 * @file analyse.h
 *
 * @brief functions to tell if a row/column is constant
 */

#ifndef ANALYSE_H
#define ANALYSE_H

/**
 * compute the number of constant columns
 *
 * @param data	the data set (of size NxM)
 * @param N	the number of lines
 * @param M	the number of columns
 * @param nM	the number of constant columns (output)
 * @param missing	true if missing data
 * @param I	matrix of missing data (of size NxM)
 */
void analyse_col(float *data, int N, int M, int *nM, int missing, int *I);

/**
 * compute the number of constant lines
 *
 * @param data	the data set (of size NxM)
 * @param N	the number of lines
 * @param M	the number of columns
 * @param row	vector of boolean (of size N), true if the line is constant
 * @param nM	the number of constant columns (output)
 */
void analyse_row(float *data, int N, int M, int *row, int *nN);

#endif // ANALYSE_H
