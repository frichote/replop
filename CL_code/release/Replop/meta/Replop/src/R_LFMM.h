/**
 * @file R_LFMM.h
 *
 * @brief C wrapper for LFMM command line program
 */

#ifndef R_LFMM_H
#define R_LFMM_H

void R_LFMM(char** R_input_file, char** R_output_file, char** R_cov_file, 
	char** R_dev_file, int* R_nd, int *R_K, int* R_Niter, int* R_burn,
	int* R_num_CPU, int* R_seed, int* R_missing_data, int* R_all);


#endif // R_LFMM_H
