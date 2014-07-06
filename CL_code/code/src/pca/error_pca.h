/**
 * @addtogroup error_pca
 * @ingroup pca
 * @{
 *
 * @brief function to manage error types
 */


#ifndef ERROR_PCA_H
#define ERROR_PCA_H

/**
 * print a specific lfmm error message
 *
 * @param msg   the string to recognize the error type
 * @param file  the name of a file (depends on the error)
 */
void print_error_pca(char* msg, char* file);

#endif // ERROR_PCA_H

/** @} */