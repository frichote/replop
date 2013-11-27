// by E. Frichot

// file:

// functions: 	read_data_double
//		write_data_double
//		print_data_double
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{

	char input_file[512];
	char output_file[512];
	int N, M;
	double *data;

	// command line arguments configuration
	strcpy(input_file, argv[0]);
	strcpy(output_file, argv[1]);
	N = (int) atoi (argv[2]);
	M = (int) atoi (argv[3]);

	// function tests
	data = (double *) malloc (N * M, sizeof(double));
	read_data_double(input_file, N, M, data);	
	write_data_double(output_file, N, M, data);
	print_data_double(data, N, M);
}
