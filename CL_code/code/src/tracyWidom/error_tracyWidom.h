/**
 * @addtogroup error_tracyWidom
 * @ingroup tracyWidom
 * @{
 *
 * @brief function to manage error types
 */


#ifndef ERROR_TRACYWIDOM_H
#define ERROR_TRACYWIDOM_H

/**
 * print a specific lfmm error message
 *
 * @param msg   the string to recognize the error type
 * @param file  the name of a file (depends on the error)
 */
void print_error_tracyWidom(char* msg, char* file);

#endif // ERROR_TRACYWIDOM_H

/** @} */