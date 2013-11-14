/*
   bituint, file: io_geno_bituint.c
   Copyright (C) 2013 François Mathieu, Eric Frichot

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
#include "io_geno_bituint.h"
#include "bituint.h"
#include "../io/io_error.h"
#include "../io/io_tools.h"
#include "../matrix/error.h"
#include "../matrix/rand.h"
 #include <errno.h>

// read_geno_bituint

void read_geno_bituint(char *file_data, int N, int M, int Mp, int nc, bituint* dat)
{
	FILE *m_File=NULL;
	int j = 0;
	int max_char_per_line = 10*N;
	char *szbuff = (char *) calloc(max_char_per_line, sizeof(char));
	int *I = (int *)calloc(N,sizeof(int));

	// open file
	m_File = fopen_read(file_data);

	// for each line
	while(fgets(szbuff, max_char_per_line, m_File) && (j<M)) {
		// fill current line
		fill_line_geno_bituint(dat, Mp, N, j, nc, file_data, szbuff, m_File, I);
		j ++;
	}

	// check the number of lines
	test_line(file_data, m_File, j, M);

	// close file
	fclose(m_File);

	// free memory
	free(szbuff);
	free(I);
}

// fill_line_geno_bituint

void fill_line_geno_bituint(bituint* dat, int Mp, int N, 
	int j, int nc, char *file_data, char* szbuff, FILE *m_File, int* I)
{
	int i = 0, value;
	char token;
	int jd, jm, jc, c; 
	double freq = 0.0; // frequency estimation
	int count = 0; // missing data counter

	// get first token
	token = (char)szbuff[i];

	// for all token
	while(token != EOF && token != '\n' && i<N) {
		I[i] = 0;

		// fill current column
		value = (int)(token - '0');

		// if missing data
		if (value == 9) {
			if (I) {
				count++;
				I[i] = 1;
			} else {
				printf("Internal Error: your data file contains missing"
				" data.\n");
				exit(1);
			}
		} else { 
			c = 0;
			while (value != c && c < nc)
				c++;
			// if known element (in 0,..,nc-1)
			if (c < nc) {
				jc = nc * j + c;
				freq += value;
			// if unknown element >= nc
			} else {
				printf("Error: Unknown element '%d' in data file: %s.\n",value,file_data);
				exit(1);
			}
			jd = jc / SIZEUINT; // column in dat
			jm = jc % SIZEUINT; // mask element
			dat[i*Mp+jd] |= mask[jm];
		}
		i++;
		// next column
		token = (char)szbuff[i];
	}
	// check the number of columns
	test_column(file_data, m_File, i, j+1, N, &token);

	// missing data inputation
	if (count) {
		freq /= (nc-1)*(N-count); 	// estimated frequency
		for (i = 0; i < N; i++) {
			if(I[i]) {
				I[i] = 0;
				jc = nc*j;
				for (c = 1; c < nc; c++) {
					if (frand() > freq)
						jc++; 
				}
				jd = jc / SIZEUINT; // column in dat
				jm = jc % SIZEUINT; // mask element
				dat[i * Mp + jd] |= mask[jm];
			}
		} 
	}
}

// print_data_bituint 

void print_geno_bituint(bituint* dat, int N, int nc, int Mp, int M)
{
	int i, j, jd, jm, jc, c;

	// for all SNPs
	for (j = 0; j < M; j++) {
		// for all individuals
		for (i = 0; i < N; i++) {
			for (c = 0; c < nc; c++) {
                		jc = nc * j + c;
                		jd = jc / SIZEUINT; // column in dat
                		jm = jc % SIZEUINT; // mask element
				if (dat[i * Mp + jd] & mask[jm]) {
					printf("%d",c);
				}
			}
		}
		printf("\n");
	}
}

// write_geno_bituint 

void write_geno_bituint(char *file_data, int N, int nc, int Mp, int M, bituint *dat)
{
	int i, j, jd, jm, jc, c;
        FILE *file = NULL;

	// open file
	file = fopen_write(file_data);

	// write data
	// for all SNPs
        for (j = 0; j < M; j++) {
		// for all individuals
                for (i = 0; i < N; i++) {
                	for (c = 0; c < nc; c++) {
                        	jc = nc*j + c;
                        	jd = jc / SIZEUINT; // column in dat
                        	jm = jc % SIZEUINT; // mask element
                                if (dat[i * Mp + jd] & mask[jm]) {
                                        fprintf(file, "%d", c);
                                }
                        }
                }
                fprintf(file, "\n");
        }

	// close file
	fclose(file);
}

