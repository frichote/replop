// by E. Frichot

// file: print_snmf

// functions:
// 	print_licence_snmf
// 	print_head_licence_snmf
// 	print_head_snmf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/sNMF/print_snmf.h"
#include "../../../src/io/io_tools.h"

int main (int argc, char *argv[])
{
        // test print_licence_snmf
        print_licence_snmf();

        // test print_head_licence_snmf
        print_head_licence_snmf();

        // test print_head_snmf
        print_head_snmf();

        // test print_help_snmf
        print_help_snmf();

        // test print_options_snmf
        print_options(argc, argv);

	return 0;
}
