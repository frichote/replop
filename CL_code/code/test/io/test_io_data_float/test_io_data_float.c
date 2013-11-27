// by E. Frichot

// file: io_data_float

// functions:
// 	read_data_float
// 	write_data_float
// 	print_data_float

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/io/io_data_float.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_file[512];
        char output_file1[512];
        int N, M;
        float *data;

        // command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);

        data = (float *)malloc(N * M * sizeof(float));

	// test read_data_float
        read_data_float(input_file, N, M, data);

	// test write_data_float
        write_data_float(output_file1, N, M, data);

	// test print_data_float
	print_data_float(data, N, M);
	
        // free memory
        free(data);

	return 0;
}
