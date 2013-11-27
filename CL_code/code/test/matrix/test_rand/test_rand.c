// by E. Frichot

// file: rand

// functions:
// 	zscore2pvalue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../../src/matrix/rand.h"
#include "../../../src/io/io_data_double.h"

int main (int argc, char *argv[])
{
	// parameters
	char input_file[512];
	int N, i;
	double *data;
	double pvalue;

	// command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);

	// test zscore2pvalue
	data = (double *) malloc (N * sizeof(double));
	read_data_double(input_file, N, 1, data);

	for(i = 0; i < N; i++) {
		pvalue = (double)(-log10(zscore2pvalue((long double)data[i])));
		printf("%G\n",pvalue);
	}
	
	free(data);

	return 0;
}
