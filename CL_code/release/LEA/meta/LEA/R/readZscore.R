read.zscore <- function(input_file) {

	# test arguments
	test_character("input_file", input_file, NULL)
	# check extension 
	test_extension(input_file, "zscore")

	R = as.matrix(read.table(input_file));

	return(list(zscores=R[,1],mlog10pvalues=R[,2],pvalues=R[,3]))
}
