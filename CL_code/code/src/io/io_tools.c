/*
    LFMM, file: io_tools.c
    Copyright (C) 2012 Eric Frichot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "io_tools.h"
#include "../matrix/error.h"

// remove_ext (from stackoverflow)

char* remove_ext (char* mystr, char dot, char sep) {
        char *retstr, *lastdot, *lastsep;

        // Error checks and allocate string.
        if (mystr == NULL)
                return NULL;

        if ((retstr = malloc (strlen (mystr) + 1)) == NULL)
                return NULL;

        // Make a copy and find the relevant characters.
        strcpy (retstr, mystr);
        lastdot = strrchr (retstr, dot);
        lastsep = (sep == 0) ? NULL : strrchr (retstr, sep);

        // If it has an extension separator.
        if (lastdot != NULL) {
                // and it's before the extenstion separator.

                if (lastsep != NULL) {
                        if (lastsep < lastdot) {
                                // then remove it.
                                *lastdot = '\0';
                        }
                } else {
                        // Has extension separator with no path separator.
                        *lastdot = '\0';
                }
        }

        // Return the modified string.
        return retstr;
}

// nb_lines

int nb_cols (char *file)
{
        FILE *fp = fopen(file,"r");
        int cols = 0;
        int c;

        if (!fp) {
                print_error_global("open",file,0);
                return 0;
        }

        c = fgetc(fp);
        while ((c != EOF) && (c != 10)) {
                cols++;
                c = fgetc(fp);
        }

        fclose(fp);

        return cols;
}

// nb_lines

int nb_lines (char *file, int N)
{
        FILE *fp = fopen(file,"r");
        int lines = 0;
        int max_char_per_line = 10 * N;
        char* szbuff = (char *) calloc(max_char_per_line, sizeof(char));
        char* token;

        if (!fp) {
                print_error_global("open",file,0);
                return 0;
        }

        token = fgets(szbuff,max_char_per_line, fp);
        while (!feof(fp) && token) {
                lines++;
                token = fgets(szbuff,max_char_per_line,fp);
        }

        fclose(fp);
        free(szbuff);

        return lines;
}

