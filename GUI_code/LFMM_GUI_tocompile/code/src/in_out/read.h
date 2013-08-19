/**
 * @file read.h
 *
 * @brief functions to read data matrices
 */

#ifndef READ_H
#define READ_H

#define SEP " "			// Séparateur utilisé dans le fichier

/**
 * read file and write it in dat (of type char)
 *
 * @param file	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void load_char(char *file, int N, int M, char *out);

/**
 * read file and write it in dat in an optimal way(of type char)
 *
 * @param file	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void load_char_optim(char *file, int N, int M, unsigned char *out);

/**
 * read file and write it in dat in an optimal way(of type char)
 *
 * @param file	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void load_char_optim2(char *file, int N, int M, unsigned char *out);

/**
 * read file_data and write it in dat
 *
 * @param file_data	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void read_data_float(char *file_data, int N, int M, float *dat);

/**
 * read file_data and write it in dat and print errors
 * if file_dat does not contain the correct number of lines/columns
 *
 * @param file_data	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void read_data_float2(char *file_data, int N, int M, float *dat);

/**
 * read file_data and write it in dat and print errors
 * if file_dat does not contain the correct number of lines/columns
 *
 * @param file_data	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void read_data_int2(char *file_data, int N, int M, int *dat);

/**
 * read file_data and write it in dat
 *
 * @param file_data	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void read_data_double(char *file_data, int N, int M, double *dat);

/**
 * read file_data and write it in dat and print errors
 * if file_dat does not contain the correct number of lines/columns
 *
 * @param file_data	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void read_data_double2(char *file_data, int N, int M, double *dat);

/**
 * read file_data and write it in dat
 *
 * @param file_data	name of the data_file
 * @param N	the number of lines
 * @param M	the number of columns
 * @param dat	the output matrix (of size NxM)
 */
void read_data_int(char *file_data, int N, int M, int *dat);

#endif // READ_H
