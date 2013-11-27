// by E. Frichot

// file: io_data_double

// functions:
// 	read_data_double
// 	write_data_double
// 	print_data_double

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/io/io_data_double.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_file[512];
        char output_file1[512];
        int N, M;
        double *data;

        // command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);

        data = (double *)malloc(N * M * sizeof(double));

	// test read_data_double
        read_data_double(input_file, N, M, data);

	// test write_data_double
        write_data_double(output_file1, N, M, data);

	// test print_data_double
	print_data_double(data, N, M);
	
        // free memory
        free(data);

	return 0;
}
