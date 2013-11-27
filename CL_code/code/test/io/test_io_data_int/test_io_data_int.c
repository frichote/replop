// by E. Frichot

// file: io_data_int

// functions:
// 	read_data_int
// 	write_data_int
// 	print_data_int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/io/io_data_int.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_file[512];
        char output_file1[512];
        int N, M;
        int *data;

        // command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);

        data = (int *)malloc(N * M * sizeof(int));

	// test read_data_int
        read_data_int(input_file, N, M, data);

	// test write_data_int
        write_data_int(output_file1, N, M, data);

	// test print_data_int
	print_data_int(data, N, M);
	
        // free memory
        free(data);

	return 0;
}
