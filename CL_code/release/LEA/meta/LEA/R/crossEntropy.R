crossEntropy <- function(input_file, K, masked_file, file.Q, 
	file.G, ploidy = 2) {

	# test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# K
	K = test_integer("K", K, NULL)
	if (K <= 0)
		stop("'K' argument has to be positive.")
	# masked data file
	tmp = gsub("(.*)\\.geno","\\1_I.geno",input_file,perl=TRUE);
	masked_file = test_character("masked_file", masked_file, tmp)
	# Q file	
	tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1_I.",input_file)
	tmp = paste(tmp,K,".Q",sep="")
	file.Q = test_character("file.Q", file.Q, tmp) 
	# G file
	tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1_I.",input_file)
	tmp = paste(tmp,K,".G",sep="")
	file.G = test_character("file.G", file.G, tmp) 
	# ploidy
	ploidy = test_integer("ploidy", ploidy, 2)
	if (ploidy <= 0)
		stop("'ploidy' argument has to be positive.")

	# run method
	all_ce = 0;
	masked_ce = 0;
    	res = .C("R_crossEntropy", 
		as.character(input_file),
		as.character(masked_file),
		as.character(file.Q),
		as.character(file.G),
		as.integer(K),
		as.integer(ploidy),
		all_ce = as.double(all_ce),
		masked_ce = as.double(masked_ce)
	)

	return(list(masked_ce=res$masked_ce, all_ce=res$all_ce))
}
