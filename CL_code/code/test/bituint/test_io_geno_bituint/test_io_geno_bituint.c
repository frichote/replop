// by E. Frichot

// file: io_geno_bituint

// functions:
// 	read_geno_bituint
// 	fill_line_geno_bituint
// 	print_geno_bituint
// 	write_geno_bituint

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/bituint/io_geno_bituint.h"
#include "../../../src/bituint/bituint.h"

int main (int argc, char *argv[])
{
	// parameters
        // parameters
        char input_file[512];
        char output_file1[512];
        int N, M, Mp, nc;
        bituint *data;

        // command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        nc = (int) atoi (argv[4]);
        strcpy(output_file1, argv[5]);

	// allocate memory
	init_mat_bituint(&data, N, nc*M, &Mp); 

        // test read_geno_bituint
        // test fill_line_geno_bituint
        read_geno_bituint(input_file, N, M, Mp, nc, data);

        // test print_data_bituint
        // test write_geno_bituint
	print_geno_bituint(data, N, nc, Mp, M); 
        write_geno_bituint(output_file1, N, nc, Mp, M, data);

        // free memory
        free(data);

	return 0;
}
