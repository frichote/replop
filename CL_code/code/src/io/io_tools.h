/**
 * @file io_tools.h
 *
 * @brief tools to read and write data files
 */

#ifndef IO_TOOLS_H
#define IO_TOOLS_H

/** 
 * removes the "extension" from a file spec.
 *
 * @param mystr 	is the string to process.
 * @param dot 		is the extension separator.
 * @param sep 		is the path separator (0 means to ignore).
 *
 * @return an allocated string identical to the original but
 *   with the extension removed. It must be freed when you're
 *   finished with it.
 *   If you pass in NULL or the new string can't be allocated,
 *   it returns NULL.
 */
char* remove_ext(char* mystr, char dot, char sep);

/**
 * count the number of lines of a file
 *
 * @param file 
 *
 * @return number of lines
 */
int nb_lines(char *file, int N);

/**
 * count the number of elements of the first line of a file (in geno format)
 *
 * @param file 
 *
 * @return number of columns of the first line
 */
int nb_cols_geno(char *file);

/**
 * count the number of elements of the first line of a file (in lfmm format)
 *
 * @param file 
 *
 * @return number of columns of the first line
 */
int nb_cols_lfmm(char *file);

#endif // IO_TOOLS_H
