// by E. Frichot

// file: error

// functions:
// 	print_error_global

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/error_matrix.h"

int main (int argc, char *argv[])
{
	// parameters
	char msg[512];
	char in[512];
	int N;

	// command line args configuration
        strcpy(msg, argv[1]);
        strcpy(in, argv[2]);
        N = (int) atoi (argv[3]);

	// test print_error_global
	print_error_global(msg, in, N);

	return 0;
}
