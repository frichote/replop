/**
 * @file geno.h
 *
 * @brief functions to read/write files with geno format.
 */

#ifndef GENO_H
#define GENO_H

void fill_line_geno(int* data, int M, int N, int j, char *file_data, FILE* m_File);

void write_geno(char* output_file, int N, int M, int *data);

void read_geno(char *input_file, int *data, int N, int M);

#endif // GENO_H
