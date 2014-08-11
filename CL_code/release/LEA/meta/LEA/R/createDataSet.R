
createDataSet <- function(input.file, output.file, ploidy = 2, seed = -1, percentage = 0.05) 
{
	# test arguments and init
	# input file
	input.file = test_character("input.file", input.file, NULL)
	# check extension and convert if necessary
	input.file = test_input_file(input.file, "geno")
	# output file	
	tmp = sub("([^.]+)\\.[[:alnum:]]+$", "\\1_I.geno",input.file)
	output.file = test_character("output.file", output.file, tmp)
	# ploidy	
	ploidy = test_integer("ploidy", ploidy, 2)
	if (ploidy <= 0)
		stop("'ploidy' argument has to be positive.")
	# seed
	seed = test_integer("seed", seed, -1)
	# percentage
	percentage = test_double("percentage", percentage, 0.05)
	if (percentage <= 0 || percentage >= 1)
			stop("'percentage' argument has to be of type double and between 0 and 1.")

	# run method
    .C("R_createDataSet", 
	as.character(input.file),
	as.integer(ploidy),
	as.integer(seed),
	as.double(percentage),
	as.character(output.file)
	);

	# create output 
	return(output.file);
}
