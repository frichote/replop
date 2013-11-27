// by E. Frichot

// file: io_error

// functions:
// 	test_column
// 	test_line

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/io/io_error.h"

int main (int argc, char *argv[])
{
	// parameters
	int i1, i2, N;
	char *token = NULL;
	FILE *m_File;

	// command line args configuration
	i1 = (int) atoi(argv[1]);
	i2 = (int) atoi(argv[2]);
	N = (int) atoi(argv[3]);
	if (argc > 4) {
		token = (char *) calloc(4, sizeof(char));
		token = "tmp";
	}

	// test test_column
	m_File = fopen("files/test.txt","r");
	test_column("files/test.txt",m_File, i1, 10, N, token); 

	// test test_line
	test_line("files/test.txt", m_File, i2, N);

	return 0;
}
