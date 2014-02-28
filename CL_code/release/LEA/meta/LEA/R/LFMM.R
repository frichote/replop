LFMM <- function(input_file, 
		variable_file, 
		K,
		nd,
		all = FALSE,
		output_file,
		missing_data = FALSE,
		num_CPU = 1,
		num_iterations = 3000,
		num_burnin = 1000,
		seed = -1, 
		DIC_file) 
{
        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# cov file
	variable_file = test_character("variable_file", variable_file, NULL)
	# K
	K = test_integer("K", K, NULL)
 	if (K < 0)
		stop("'K' argument has to be not negative.")
	# nd
	nd = test_integer("nd", nd, 0)
	if(nd <= 0)
		nd = 0;
	# all
	all = test_logical("all",all, FALSE)
	# output_file
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1", input_file)
	output_file = test_character("output_file", output_file, tmp)
	# missing_data  
	missing_data = test_logical("missing_data", missing_data, FALSE)
	# CPU	
	num_CPU = test_integer("num_CPU", num_CPU, 1)
	if (num_CPU <= 0)
                num_CPU = 1;
	#ifdef windows
		num_CPU = 1;
	#endif
        # num_iterations
	num_iterations = test_integer("num_iterations", num_iterations, 3000)
	if (num_iterations <= 0)
                stop("'num_iterations' argument has to be positive.")
        # num_burnin
	num_burnin = test_integer("num_burnin", num_burnin, 1000)
	if (num_burnin <= 0)
                	stop("'num_burnin' argument has to be positive.")
	if (num_burnin >= num_iterations) {
                stop("the number of iterations for burnin (num_burnin) is greater than the number total of iterations (num_iterations)")
	}
	# seed
	seed = test_integer("seed", seed, -1)
	# DIC_file
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input_file)
	DIC_file = test_character("DIC_file", DIC_file, tmp)

	dic = 0
	dev = 0
	resC = 	.C("R_LFMM", 
		as.character(input_file),
		as.character(output_file),
		as.character(variable_file),
		as.character(DIC_file),
		as.integer(nd),
		as.integer(K),
		as.integer(num_iterations),
		as.integer(num_burnin),
		as.integer(num_CPU),
		as.integer(seed),
		as.integer(missing_data),
		as.integer(all),
		dic = as.double(dic),
		dev = as.double(dev)
	);

	v = read.table(variable_file)
	D = dim(as.matrix(v))[2]
	rm(v)

	zscore_file = NULL 
	for (i in 1:D) { 
		if (all) {
			zscore_file  = c(zscore_file, 
				paste(output_file, "_a", i, ".", K, ".zscore",sep=""));
		} else {
			zscore_file  = c(zscore_file, 
				paste(output_file, "_s", i, ".", K, ".zscore", sep=""));
		}
	}

	dic_file = NULL 
	if (all) {
		dic_file  = c(dic_file, 
				paste(DIC_file, "_a.", K, ".dic",sep=""));
	} else {
		for (i in 1:D) { 
			dic_file  = c(dic_file, 
				paste(DIC_file, "_s", i, ".", K, ".dic", sep=""));
		}
	}

	return(list(zscore_files = zscore_file, dic_files = dic_file))
} 
