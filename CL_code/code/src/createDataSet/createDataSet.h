/**
 * @addtogroup createDataSet
 * @ingroup createDataSet
 * @{
 *
 * @brief function to create a data set with masked genotypes
 */


#ifndef CREATEDATASET_H
#define CREATEDATASET_H

/**
 * create a data set with masked genotypes 
 *
 * @param[in] input_file	input file name
 * @param[in] m			ploidy
 * @param[in] seed		seed for randomization
 * @param[in] e 		percentage of masked data
 * @param[in] output_file	output file name
 */
void createDataSet(char* input_file, int m, long long seed, double e,
	char* output_file); 

#endif // CREATEDATASET_H

/** @} */
