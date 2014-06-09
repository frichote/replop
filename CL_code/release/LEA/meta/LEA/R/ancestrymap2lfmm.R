
ancestrymap2lfmm <- function(	input_file,
				output_file = NULL) 
{
	# test arguments and init
	# input file
    	if(missing(input_file)) 
		stop("'input_file' argument is missing.")
	else if (!is.character(input_file))
		stop("'input_file' argument has to be of type character.")
	# check the extension
	test_extension(input_file, "ancestrymap");
	# output file	
	if (!missing(output_file) && !is.character(output_file))
		stop("'output_file' argument has to be of type character.")
	else if (missing(output_file))
                output_file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.lfmm", input_file)

	N = 0;
 	M = 0;

	# run method
    .C("R_ancestrymap2lfmm", 
	as.character(input_file),
	as.character(output_file),
	as.integer(N),
	as.integer(M)
	);

	# create output 
	output_file;
}
