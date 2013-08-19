/**
 * @file io_geno_bituint.h
 *
 * @brief set of functions to read and print data .
 */

#ifndef IO_GENO_BITUINT_H
#define IO_GENO_BITUINT_H

#include <stdint.h>
#include "bituint.h"

/**
 * read data file with M lines, N columns and nc different elements
 * and input missing data
 *  
 * @param file_data	data file name	
 * @param N	number of lines of the matrix
 * @param M	number of elements per line in the data file
 * @param Mp	number of columns of the matrix
 * @param nc	number of different elements of the matrix
 * @param dat  	output data matrix 
 */
void read_geno_bituint(char *file_data, int N, int M, int Mp, int nc, 
			bituint* dat);

/**
 * read a line of data file with N elements and fill dat
 * 
 * @param dat  	data matrix (of size NxMc)
 * @param Mc	number of columns of dat
 * @param cmax	max number of elements of szbuff
 * @param j	current line
 * @param nc	number of different elements of the matrix
 * @param file_data	data file name	
 * @param m_file	opened file
 * @param I	missing data temporary vector
 */
void fill_line_geno_bituint(bituint* dat, int Mp, 
			int cmax, int j, int nc, char *file_data, 
			FILE* m_File, int* I);

/**
 * TO CHECK
 */
void print_data_bituint(bituint* dat, int n, int L, int Lc, int nc);

#endif // IO_GENO_BITUINT_H
