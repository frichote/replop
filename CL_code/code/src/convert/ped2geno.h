/**
 * @file ped2geno.h
 *
 * @brief functions to convert a file from ped to geno format.
 */

#ifndef PED2GENO_H
#define PED2GENO_H

#include <stdint.h>

void ped2geno (char *input_file, char* output_file, int *N, int *M);

#endif // PED2GENO_H
