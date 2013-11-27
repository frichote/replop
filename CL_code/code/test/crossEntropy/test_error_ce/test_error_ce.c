// by E. Frichot

// file: error_ce

// functions:
// 	error_ce

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/crossEntropy/error_ce.h"

int main (int argc, char *argv[])
{
	// parameters
        char msg[512];
        char in[512];

        // command line args configuration
        strcpy(msg, argv[1]);
        strcpy(in, argv[2]);

        // test print_error_global
        print_error_ce(msg, in);

	return 0;
}
