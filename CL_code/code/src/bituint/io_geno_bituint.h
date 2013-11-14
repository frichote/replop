/**
 * @file io_geno_bituint.h
 *
 * @brief set of functions to read, write and print data in geno format file 
 * 	with bituint data memory format.
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
 * @param szbuff	line to read
 * @param m_file	opened file
 * @param I	missing data temporary vector
 */
void fill_line_geno_bituint(bituint* dat, int Mp, 
			int cmax, int j, int nc, char *file_data,  
			char* szbuff, FILE* m_File, int* I);

/**
 * print data from bituint format in geno format
 *
 * @param dat  	data matrix (of size NxMc)
 * @param N	number of lines of the matrix
 * @param nc	number of different elements of the matrix
 * @param Mp	number of columns of the matrix
 * @param M	number of elements per line in the data file
 */
void print_geno_bituint(bituint* dat, int N, int nc, int Mp, int M);

/**
 * write data from bituint format in geno format
 *
 * @param file_data	data file name	
 * @param N	number of lines of the matrix
 * @param nc	number of different elements of the matrix
 * @param Mp	number of columns of the matrix
 * @param M	number of elements per line in the data file
 * @param dat  	data matrix (of size NxMc)
 */
void write_geno_bituint(char *file_data, int N, int nc, int Mp, int M, bituint *dat);

#endif // IO_GENO_BITUINT_H
