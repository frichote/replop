tracyWidom <- function(input_file.eigenvalues, 
		output_file.tracywidom)
{

        # test arguments and init
	# input file
	input_file.eigenvalues = test_character("input_file", input_file.eigenvalues, NULL)
	# K
	# output file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.tracywidom",input_file.eigenvalues)
	output_file.tracywidom = test_character("output_file.tracywidom", output_file.tracywidom, tmp)

	print(output_file.tracywidom)
    	.C("R_tracyWidom", 
		as.character(input_file.eigenvalues),
		as.character(output_file.tracywidom)
	);

	read.table(output_file.tracywidom, header = TRUE)
}
