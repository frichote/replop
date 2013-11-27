// by E. Frichot

// file: print_lfmm

// functions:
// 	print_licence_lfmm
// 	print_head_licence_lfmm
// 	print_head_lfmm
// 	print_help_lfmm
// 	print_options_lfmm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/print_lfmm.h"
#include "../../../src/io/io_tools.h"

int main (int argc, char *argv[])
{
	// test print_licence_lfmm
	print_licence_lfmm();

	// test print_head_licence_lfmm
	print_head_licence_lfmm();

	// test print_head_lfmm
	print_head_lfmm();

	// test print_help_lfmm
	print_help_lfmm();

	// test print_options_lfmm
	print_options(argc, argv);

	return 0;
}
