// by E. Frichot

// file: error_lfmm

// functions:
// 	print_error_lfmm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/error_lfmm.h"

int main (int argc, char *argv[])
{
	// parameters
        char msg[512];
        char in[512];
	int n;

        // command line args configuration
        strcpy(msg, argv[1]);
        strcpy(in, argv[2]);
	n = (int) atoi(argv[3]);

        // test print_error_global
        print_error_lfmm(msg, in, n);

	return 0;
}
