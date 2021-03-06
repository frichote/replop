/**
 * @file error_lfmm.h
 *
 * @brief function to manage error types
 */

#ifndef ERROR_LFMM_H
#define ERROR_LFMM_H

#include "matrix/error.h"

/**
 * print a specific lfmm error message
 *
 * @param msg	the string to recognize the error type
 * @param file	the name of a file (depends on the error)
 * @param n	an integer parameter (depends of the error)
 */
void print_error_lfmm(char *msg, char *file, int n);

#endif // ERROR_LFMM_H
