/*
 *     vcf2geno, file: vcf2geno.c
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
#include "vcf2geno.h"
#define SEP	"\t"

void vcf2geno (char *input_file, char* output_file, int *N, int *M, char* snp_bp_file, 
	char* removed_bp_file)
{
	// temporary variables
	int Np;
	int i,j, ip, jp;
	char **tmp = (char **)malloc(9*sizeof(char *));

	// file management
	FILE* vcf_File=NULL;
	FILE *snp_bp_File = NULL;
	FILE* removed_bp_File=NULL;
	FILE* genotype_File=NULL;
	int max_char_per_line;
	char    *szbuff;
	char* token;

	// register output
	int *allele;

	// init tmp mem
	for (i = 0; i < 9; i++)
		tmp[i] = (char *)calloc(512,sizeof(char));

	max_char_per_line = 200*(*M);//3*((M<N)?N:M);
	szbuff = (char*)calloc(max_char_per_line,sizeof(char));
	allele = (int *)calloc((*M),sizeof(int));

	strcpy(snp_bp_file,"snp.info");
	strcpy(removed_bp_file,"removed_lines.info");
	strcpy(output_file,"genotype.geno");

	// open input file
	vcf_File = fopen(input_file,"r");
	if (!vcf_File)
		printf("Error: open %s.\n",input_file);

	// open output SNP info file
	snp_bp_File = fopen(snp_bp_file,"w");
	removed_bp_File = fopen(removed_bp_file,"w");

	// open output geno file
	genotype_File = fopen(output_file,"w");

	i = 0;
	jp = 0;
	fgets(szbuff,max_char_per_line,vcf_File);

	// for each line
	while(!feof(vcf_File))
	{
		// look for informations to check if it is not a comment line
		if (szbuff[0] != '#') {
			token = strtok(szbuff,SEP);
			// look for informations to check if it is a SNP
			// and print SNP info in its file
			for (ip=0;ip<9;ip++) { 
				strcpy(tmp[ip],token);
				token = strtok(NULL,SEP);
			}

			//token = strtok(szbuff,SEP);
			// if not a SNP.
			if (strlen(tmp[4]) > 1) {
				// print it in removed lines info file as REMOVED
				for (ip=0;ip<9;ip++) { 
					fprintf(removed_bp_File, "%s ", tmp[ip]);
				}
				fprintf(removed_bp_File, "REMOVED\n", token);
				jp ++;
				i++;

				// if it is a SNP
			} else {
				// print it in SNP info file
				for (ip=0;ip<9;ip++) { 
					fprintf(snp_bp_File, "%s ", tmp[ip]);
				}
				fprintf(snp_bp_File, "\n");

				j = 0;
				//token = strtok(NULL,SEP);

				// for each token
				while(token)
				{
					// if length 1
					if (strlen(token) == 1) {
						// and just a dot
						if (token[0] == '.') {
							allele[j] = 9;
							// and not a dot
						} else {
							printf("%c9 ",token[0]);
							printf("EError %d line %d colum not 0/1 %c %c\n",
									i,j,token[0],token[2]);
							fclose(vcf_File);
							fclose(snp_bp_File);
							fclose(removed_bp_File);
							exit(1);
						}
						// if just a dot and a EOL
					} else if (strlen(token) == 2 && token[0] == '.' && token[1] == '\n') {
						allele[j] = 9;
						// if not [01]/[01]
					} else if (token[1] == ':') {
						printf("%c9 ",token[0]);
						printf("Error %d line %d colum not 0/1 %c %c\n",i,j,token[0],token[2]);
						fclose(vcf_File);
						fclose(snp_bp_File);
						fclose(removed_bp_File);
						exit(1);
					} else {
						// if error
						if ((token[0] != '0' && token[0] != '1' && token[0] != '.') 
								|| (token[2] != '0' && token[2] != '1' && 
									token[2] != '.')) {
							printf("Error %d line %d colum not 0/1 %c %c\n",
									i,j,token[0],token[1]);
							fclose(vcf_File);
							fclose(snp_bp_File);
							fclose(removed_bp_File);
							exit(1);
						}
						// if missing data
						if (token[0] == '.' || token[2] == '.') 
							allele[j] = 9;
						// else everything is fine
						else { 
							allele[j] = (int)token[0] - (int)'0' + (int)token[2] - (int)'0';
						}
					}
					// next token
					token = strtok(NULL,SEP);
					j++;

				}
				i++;

				// if not the correct number of columns
				if (j != (*M)) {
					printf("Error: unable to read file %s. It seems that line %d "
							"contains %d columns instead of %d\n",input_file,i,j,(*M));
					fclose(vcf_File);
					fclose(snp_bp_File);
					fclose(removed_bp_File);
					exit(1);
				}

				// print in LFMM format
				j = 0;
				for (j = 0; j < (*M); j++) {
					fprintf(genotype_File,"%d",allele[j]);
				}
				fprintf(genotype_File,"\n");
			}
		}
		// next line
		fgets(szbuff, max_char_per_line, vcf_File);
	}
	// if not the correct number of lines 
	if (i != (*N)) {
		printf("Error: unable to read file %s. It seems that it contains "
				"%d lines instead of %d\n\n",input_file,i,(*N));
		fclose(vcf_File);
		fclose(snp_bp_File);
		fclose(removed_bp_File);
		exit(1);
	}
	// close files
	fclose(vcf_File);
	fclose(snp_bp_File);
	fclose(removed_bp_File);
	fclose(genotype_File);	

	printf("%d line(s) were removed.\n",jp);
	printf("Please, check %s file, for more informations.\n",removed_bp_file);
	printf("For SNP info, please check %s.\n",snp_bp_file);
	printf("Genotypes in LFMM format are in %s file.\n",output_file);

	for (i = 0; i < 9; i++)
		free(tmp[i]);
	free(tmp);
	free(szbuff);
	free(allele);
}

