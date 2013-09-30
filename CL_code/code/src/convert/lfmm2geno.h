/**
 * @file lfmm2geno.h
 *
 * @brief functions to convert a file from geno to lfmm format.
 */

#ifndef LFMM2GENO_H
#define LFMM2GENO_H

#include <stdint.h>

void lfmm2geno (char *input_file, char* output_file, int *N, int *M);

#endif // LFMM2GENO_H
