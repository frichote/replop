// by E. Frichot

// file: error_nmf

// functions:
// 	print_error_nmf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/sNMF/error_nmf.h"

int main (int argc, char *argv[])
{
	// parameters
        char msg[512];
        char in[512];

        // command line args configuration
        strcpy(msg, argv[1]);
        strcpy(in, argv[2]);

	// test print_error_nmf
        print_error_nmf(msg, in, 0);

	return 0;
}
