/**
 * @file ancestrymap.h
 *
 * @brief functions to read/write files with ancestryp format.
 */

#ifndef ANCESTRYMAP_H
#define ANCESTRYMAP_H

#include <stdint.h>

void ancestrymap2geno (char *input_file, char* output_file, int *N, int *M);

void ancestrymap2lfmm (char *input_file, char* output_file, int *N, int *M);

void read_ancestrymap (char* input_file, int N, int M, int* data);

int nb_ind_ancestrymap(char *input_file);

#endif // ANCESTRYMAP_H
