
ped2lfmm <- function(	input.file,
				output.file = NULL) 
{
	# test arguments and init
	# input file
    	if(missing(input.file)) 
		stop("'input.file' argument is missing.")
	else if (!is.character(input.file))
		stop("'input.file' argument has to be of type character.")
	# check the extension
	test_extension(input.file, "ped");
	# output file	
	if (!missing(output.file) && !is.character(output.file))
		stop("'output.file' argument has to be of type character.")
	else if (missing(output.file))
                output.file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.lfmm", input.file)

	N = 0;
 	M = 0;

	# run method
    .C("R_ped2lfmm", 
	as.character(input.file),
	as.character(output.file),
	as.integer(N),
	as.integer(M)
	);

	# create output 
	output.file;
}
