
createDataSet <- function(input_file, output_file, ploidy = 2, seed = -1, percentage = 0.05) 
{
	# test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# output file	
	tmp = sub("([^.]+)\\.[[:alnum:]]+$", "\\1_I.geno",input_file)
	output_file = test_character("output_file", output_file, tmp)
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
	as.character(input_file),
	as.integer(ploidy),
	as.integer(seed),
	as.double(percentage),
	as.character(output_file)
	);

	# create output 
	return(output_file);
}
