/**
 * @file createDataSet.h
 *
 * @brief function to create a data set with masked genotypes
 */


#ifndef CREATEDATASET_H
#define CREATEDATASET_H

/**
 * create a data set with masked genotypes 
 *
 * @param input_file	input file name
 * @param m		ploidy
 * @param seed		seed for randomization
 * @param e 		percentage of masked data
 * @param output_file	output file name
 */
void createDataSet(char* input_file, int m, long long seed, double e,
	char* output_file); 

#endif // CREATEDATASET_H
