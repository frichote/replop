/*
    LFMM, file: read.c
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
#include "read.h"
#include "../matrix/error.h"

// load_char

void load_char(char *file, int N, int M, char *out)
{
	int i, j;

	FILE *m_File = NULL;
	char tmp1, tmp2;

	m_File = fopen(file, "r");
	if (!m_File)
		printf("Error: open prout\n");

	for (j = 0; j < M; j++) {
		for (i = 0; i < N; i++) {
			fscanf(m_File, "%c%c ", &tmp1, &tmp2);
			out[i * M + j] = (int)(tmp1 - '0') + (int)(tmp2 - '0');
		}
	}
	fclose(m_File);
}

// load_char_optim

void load_char_optim(char *file, int N, int M, unsigned char *out)
{

	int i, j;

	FILE *m_File = NULL;
	unsigned int tmp;
	char tmp1, tmp2;
	int ip, ipp;

	m_File = fopen(file, "r");
	if (!m_File)
		printf("Error: open prout\n");

	for (j = 0; j < M; j++) {
		for (i = 0; i < N; i++) {
			ip = i / 4;
			ipp = i % 4;
			fscanf(m_File, "%c%c ", &tmp1, &tmp2);
			tmp =
			    (unsigned int)(tmp1 - '0') + (unsigned int)(tmp2 -
									'0');
			out[ip * M + j] |= tmp << (2 * ipp);
		}
	}
	fclose(m_File);
}

// load_char_optim

void load_char_optim2(char *file, int N, int M, unsigned char *out)
{

	int i, j;

	FILE *m_File = NULL;
	unsigned int tmp;
	//int tmp1, tmp2;
	int ip, ipp, fres;

	m_File = fopen(file, "r");
	if (!m_File)
		printf("Error: open %s.\n",file);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			ip = i / 4;
			ipp = i % 4;
			fres = fscanf(m_File, "%u ", &tmp);
			if (!fres)
				printf("Error open %s.\n",file);
			//tmp = (unsigned int)(tmp1)+(unsigned int)(tmp2);
			if (tmp == 9)
				tmp = 0;

			out[ip * M + j] |= tmp << (2 * ipp);
		}
	}
	fclose(m_File);
}

// read_data_float

void read_data_float(char *file_data, int N, int M, float *dat)
{
	FILE *file = NULL;
	int i, j, tmp = 1;
	char st;

	file = fopen(file_data, "r");
	if (!file)
		print_error_global("open", file_data, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp *= fscanf(file, "%g ", &dat[i * M + j]);
		}
		tmp *= fscanf(file, "%g", &dat[i * M + (M - 1)]);
		tmp *= fscanf(file, "%c", &st);
		if (!strcmp(&st, "\n")) {
			tmp = 1;
		} else if (!strcmp(&st, " ")) {
			tmp *= fscanf(file, "%c", &st);
			if (!strcmp(&st, "\n"))
				tmp = 1;
			else
				tmp = 0;
		} else {
			tmp = 0;
		}

	}
	tmp *= fscanf(file, "EOF");

	fclose(file);

	if (!tmp)
		print_error_global("read", file_data, 0);
}

// read_data_float2

void read_data_float2(char *file_data, int N, int M, float *dat)
{
	FILE *m_File = NULL;
	int i = 0;
	int j = 0;
	int max_char_per_line = 30 * M;

	char szbuff[max_char_per_line];
	char *token;
	int lmax = N;
	int cmax = M;

	i = 0;
	m_File = fopen(file_data, "r");
	//m_File = fopen(file_data,"r");

	if (!m_File)
		print_error_global("open", file_data, 0);

	// On récupere la ligne courante du fichier
	token = fgets(szbuff, max_char_per_line, m_File);

	while (!feof(m_File) & (i < lmax)) {
		j = 0;
		// On decoupe la ligne selon le charactere de séparation 
		// SEP (" ")
		token = strtok(szbuff, SEP);
		// On lit les éléments découpés un à un et on les stocke
		// dans le tableau Tab
		while (token && j < cmax) {
			dat[i * M + j] = (float)atof(token);
			//printf("%d\n",i);
			// On lit l'element suivant retourner par strtok
			token = strtok(NULL, SEP);
			j++;
		}
		i++;
		if (j != cmax) {
			printf("Error: unable to read file %s. It seems that"
			       " line %d contains %d columns instead of %d."
			       "\n\n", file_data, i, j, cmax);
			fclose(m_File);
			exit(1);
		}
		if (token) {
			printf("Error: unable to read file %s. It seems that"
			       " line %d contains more than %d columns.\n\n",
			       file_data, i, cmax);
			fclose(m_File);
			exit(1);
		}
		// On récupere la ligne courante du fichier
		token = fgets(szbuff, max_char_per_line, m_File);
	}
	if (i != lmax) {
		printf("Error: unable to read file %s. It seems that it "
		       "contains %d lines instead of %d.\n\n", file_data,
		       i, lmax);
		fclose(m_File);
		exit(1);
	}

	if (!feof(m_File)) {
		printf("Error: unable to read file %s. It seems that it "
		       "contains more than %d lines.\n\n", file_data, lmax);
		fclose(m_File);
		exit(1);
	}

	fclose(m_File);
}

// read_data_int

void read_data_int2(char *file_data, int N, int M, int *dat)
{
	FILE *m_File = NULL;
	int i = 0;
	int j = 0;
	int max_char_per_line = 30 * M;

	char szbuff[max_char_per_line];
	char *token;
	int lmax = N;
	int cmax = M;

	i = 0;
	m_File = fopen(file_data, "r");
	//m_File = fopen(file_data,"r");

	if (!m_File)
		print_error_global("open", file_data, 0);

	// On récupere la ligne courante du fichier
	token = fgets(szbuff, max_char_per_line, m_File);

	while (!feof(m_File) & (i < lmax)) {
		j = 0;
		// On decoupe la ligne selon le charactere de séparation 
		// SEP (" ")
		token = strtok(szbuff, SEP);
		// On lit les éléments découpés un à un et on les stocke
		// dans le tableau Tab
		while (token && j < cmax) {
			dat[i * M + j] = (int)atof(token);
			//printf("%d\n",i);
			// On lit l'element suivant retourner par strtok
			token = strtok(NULL, SEP);
			j++;
		}
		i++;
		if (j != cmax) {
			printf("Error: unable to read file %s. It seems that"
			       " line %d contains %d columns instead of %d."
			       "\n\n", file_data, i, j, cmax);
			fclose(m_File);
			exit(1);
		}
		if (token) {
			printf("Error: unable to read file %s. It seems that"
			       " line %d contains more than %d columns.\n\n",
			       file_data, i, cmax);
			fclose(m_File);
			exit(1);
		}
		// On récupere la ligne courante du fichier
		token = fgets(szbuff, max_char_per_line, m_File);
	}
	if (i != lmax) {
		printf("Error: unable to read file %s. It seems that it "
		       "contains %d lines instead of %d.\n\n", file_data,
		       i, lmax);
		fclose(m_File);
		exit(1);
	}

	if (!feof(m_File)) {
		printf("Error: unable to read file %s. It seems that it "
		       "contains more than %d lines.\n\n", file_data, lmax);
		fclose(m_File);
		exit(1);
	}

	fclose(m_File);
}

// read_data_double2

void read_data_double2(char *file_data, int N, int M, double *dat)
{
	FILE *m_File = NULL;
	int i = 0;
	int j = 0;
	int max_char_per_line = 30 * M; // ((M < N) ? N : M);

	char szbuff[max_char_per_line];
	char *token;
	int lmax = N;
	int cmax = M;

	i = 0;
	m_File = fopen(file_data, "r");
	//m_File = fopen(file_data,"r");

	if (!m_File)
		print_error_global("open", file_data, 0);

	// On récupere la ligne courante du fichier
	token = fgets(szbuff, max_char_per_line, m_File);

	while (!feof(m_File) & (i < lmax)) {
		j = 0;
		// On decoupe la ligne selon le charactere de séparation SEP 
		// (" ")
		token = strtok(szbuff, SEP);
		// On lit les éléments découpés un à un et on les stocke dans
		//  le tableau Tab
		while (token && j < cmax) {
			dat[i * M + j] = (double)atof(token);
			// On lit l'element suivant retourner par strtok
			token = strtok(NULL, SEP);
			j++;
		}
		i++;
		if (j != cmax) {
			printf("Error: unable to read file %s. It seems that"
			       " line %d contains %d columns instead of %d."
			       "\n\n", file_data, i, j, cmax);
			fclose(m_File);
			exit(1);
		}
		if (token) {
			printf("Error: unable to read file %s. It seems that"
			       " line %d contains more than %d columns.\n\n",
			       file_data, i, cmax);
			fclose(m_File);
			exit(1);
		}
		// On récupere la ligne courante du fichier
		token = fgets(szbuff, max_char_per_line, m_File);
	}
	if (i != lmax) {
		printf("Error: unable to read file %s. It seems that it "
		       "contains %d lines instead of %d.\n\n", file_data,
		       i, lmax);
		fclose(m_File);
		exit(1);
	}

	if (!feof(m_File)) {
		printf("Error: unable to read file %s. It seems that it "
		       "contains more than %d lines.\n\n", file_data, lmax);
		fclose(m_File);
		exit(1);
	}

	fclose(m_File);

}

// read_data_double

void read_data_double(char *file_data, int N, int M, double *dat)
{
	FILE *file = NULL;
	int i, j, tmp = 1;
	float tmp2;
	char st;

	file = fopen(file_data, "r");
	if (!file)
		print_error_global("open", file_data, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp *= fscanf(file, "%g ", &tmp2);
			dat[i * M + j] = (double)tmp2;
		}
		tmp *= fscanf(file, "%g", &tmp2);
		dat[i * M + (M - 1)] = (double)tmp2;

		tmp *= fscanf(file, "%c", &st);
		if (!strcmp(&st, "\n")) {
			tmp *= 1;
		} else if (!strcmp(&st, " ")) {
			tmp *= fscanf(file, "%c", &st);
			if (!strcmp(&st, "\n"))
				tmp *= 1;
			else
				tmp *= 0;
		} else {
			tmp *= 0;
		}

	}
	tmp *= fscanf(file, "EOF");
	fclose(file);

	if (!tmp)
		print_error_global("read", file_data, 0);
}

// read_data_int

void read_data_int(char *file_data, int N, int M, int *dat)
{

	FILE *file = NULL;
	int i, j, tmp = 1;
	char st;

	file = fopen(file_data, "r");
	if (!file)
		print_error_global("open", file_data, 0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			tmp *= fscanf(file, "%d ", &dat[i * M + j]);
		}
		tmp *= fscanf(file, "%d", &dat[i * M + (M - 1)]);
		tmp *= fscanf(file, "%c", &st);
		if (!strcmp(&st, "\n"))
			tmp *= 1;
		else if (!strcmp(&st, " ")) {
			tmp *= fscanf(file, "%c", &st);
			if (!strcmp(&st, "\n"))
				tmp *= 1;
			else
				tmp *= 0;
		} else {
			tmp *= 0;
		}

	}
	tmp *= fscanf(file, "EOF");
	fclose(file);

	if (!tmp)
		print_error_global("read", file_data, 0);
}
