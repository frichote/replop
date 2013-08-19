/**
 * @file error_cds.h
 *
 * @brief function to manage error types for createDataSet
 */


#ifndef ERROR_CDS_H
#define ERROR_CDS_H

#include "../matrix/error.h"

/**
 * print a specific createDataSet error message
 *
 * @param msg   the string to recognize the error type
 * @param file  the name of a file (depends on the error)
 */
void print_error_cds(char* msg, char* file);

#endif // ERROR_CDS_H
