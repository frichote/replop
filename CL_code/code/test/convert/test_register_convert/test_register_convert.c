// by E. Frichot

// file: register_convert

// functions:
// 	analyse_param_convert

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/convert/register_convert.h"

int main (int argc, char *argv[])
{
	// parameters
	char input[512];
	char output[512];

	// test analyse_param_convert
	analyse_param_convert(argc, argv, input, output, "geno");
	printf("%s %s\n",input, output);

	return 0;
}
