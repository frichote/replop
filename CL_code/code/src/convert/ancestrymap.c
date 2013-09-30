/*
 *     ancestrymap, file: ancestrymap.c
 *     Copyright (C) 2013 Eric Frichot
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ancestrymap.h"
#include "geno.h"
#include "../io/io_tools.h"
#include "../io/io_error.h"
#include "../io/io_data_int.h"

// ancestrymap2geno

void ancestrymap2geno (char *input_file, char* output_file, int *N, int *M)
{
        int *data;
	int nb;
	double tmp;

        // number of lines and columns
	*N = nb_ind_ancestrymap(input_file);
        nb = nb_lines(input_file, 100);

	tmp = *N / nb;

	if (tmp != ceil(tmp)) {
		printf("Error !\n");
		exit(1);
	}

        data = (int *)malloc((*N)*(*M)*sizeof(int));

        // read in ancestrymap format
        read_ancestrymap(input_file, *N, *M, data);

        // write in geno format
        write_geno(output_file, *N, *M, data);

        free(data);
}


// ancestsrymap2lfmm

void ancestrymap2lfmm (char *input_file, char* output_file, int *N, int *M)
{
        int *data;
	int nb;
	double tmp;

        // number of lines and columns
	*N = nb_ind_ancestrymap(input_file);
        nb = nb_lines(input_file, 100);

	tmp = *N / nb;

	if (tmp != ceil(tmp)) {
		printf("Error !\n");
		exit(1);
	}

        data = (int *)malloc((*N)*(*M)*sizeof(int));

        // read in ancestrymap format
        read_ancestrymap(input_file, *N, *M, data);

        // write in lfmm format
        write_data_int(output_file, *N, *M, data);

        free(data);
}


// a revoir

void read_ancestrymap (char* input_file, int N, int M, int* data)
{
        FILE* File=NULL;
        int max_char_per_line = 1000;
	int i, j, allele;
        char szbuff[max_char_per_line];
	char *token;
	char tmp[512] = "";
	char ref[512] = "";

        // open input file
        File = fopen(input_file,"r");
        if (!File)
                printf("Error: open %s.\n",input_file);

        token = fgets(szbuff, max_char_per_line, File);

	j = -1;
	i = 0;
	while (!feof(File)) {
                token = strtok(szbuff, SEP);
		strcpy (tmp, token);
		
		token = strtok(NULL, SEP);
		token = strtok(NULL, SEP);
		allele = (int)atoi(token);
		
		// new SNP
		if (strcmp(ref, tmp) != 0) {
			if (j >= 0)	
				// test if the number indiviual for the line is ok
				test_column (input_file, File, i, j, N, token);

			i = 0;
			j++;
			strcpy(ref, tmp);
		// same SNP, new individual
		} else {
			i++;
		}
		data[i * M + j] = allele;
	}
	test_line(input_file, File, j, M);

        fclose(File);

}

int nb_ind_ancestrymap(char *input_file)
{
        FILE* File=NULL;
        int max_char_per_line = 1000;
	int nb = 0, diff = 0;
        char szbuff[max_char_per_line];
	char *token;
	char tmp[512] = "";

        // open input file
        File = fopen(input_file,"r");
        if (!File)
                printf("Error: open %s.\n",input_file);

        token = fgets(szbuff, max_char_per_line, File);

	while (!feof(File) && !diff) {
                token = strtok(szbuff, SEP);
		diff = strcmp(tmp,token) != 0;
		strcpy(tmp,token);
		nb ++;
	}

        fclose(File);
	return nb;
}
