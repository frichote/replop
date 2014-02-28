sNMF <- function(input_file, 
		K, 
		alpha = 10, 
		tol = 0.0001, 
		entropy = FALSE,
		percentage = 0.05,
		I, 
		iterations = 200, 
		ploidy = 2, 
		seed = -1, 
		num_CPU = 1, 
		input_file.Q,
		output_file.Q, load.Q = TRUE, 
		output_file.G, load.G = FALSE)
{

        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# K
	K = test_integer("K", K, NULL)
	if (K <= 0)
               	stop("'K' argument has to be positive.")
	# alpha
	alpha = test_double("alpha", alpha, 10)
	if (alpha < 0)
                alpha = 0
	# tolerance
	tol = test_double("tol", tol, 0.0001)
	if (tol <= 0)
		tol = 0.0001
	# entropy
	entropy = test_logical("entropy", entropy, FALSE)
	# percentage
	percentage = test_double("percentage", percentage, 0)
        if (entropy && (percentage < 0 || percentage >= 1))
                percentage = 0.05
	else if (!entropy)
		percentage = 0
	# iterations
	iterations = test_integer("iterations", iterations, 200)
        if (iterations <= 0)
                iterations = 200;
	# ploidy
	ploidy = test_integer("ploidy", ploidy, 2)
        if (ploidy <= 0)
                ploidy = 2;
	# seed
	seed = test_integer("seed", seed, -1)
	# CPU	
	num_CPU = test_integer("num_CPU", num_CPU, 1)
        if (num_CPU <= 0)
                num_CPU = 1;
	#ifdef windows
		num_CPU = 1;
	#endif
	# Q file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.",input_file)
        tmp = paste(tmp, K, ".Q", sep="")
	output_file.Q = test_character("output_file.Q", output_file.Q, tmp)
	# F file
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.",input_file)
        tmp = paste(tmp, K, ".G", sep="")
	output_file.G = test_character("output_file.G", output_file.G, tmp)
	# load Q
	load.Q = test_logical("load.Q", load.Q, TRUE)
	# load F
	load.G = test_logical("load.G", load.G, FALSE)
	# input Q
	input_file.Q = test_character("input_file.Q", input_file.Q, "")
	# I	
	I = test_integer("I", I, 0)
        if (I < 0)
                stop("'I' argument has to be of type positive.")

	all_ce = 0;
	masked_ce = 0;
    	resC = .C("R_sNMF", 
		as.character(input_file),
		as.integer(K),
		as.double(alpha),
		as.double(tol),
		as.double(percentage),
		as.integer(iterations),
		as.integer(seed),
		as.integer(ploidy),
		as.integer(num_CPU),
		as.character(input_file.Q),
		as.character(output_file.Q),
		as.character(output_file.G),
		as.integer(I),
		all_ce = as.double(all_ce),
		masked_ce = as.double(masked_ce)
	);

	res = list()
	if (load.Q) {
		res$Q = as.matrix(read.table(output_file.Q));
	} else {
		res$Q = output_file.Q;
	}
	if (load.G) {
		res$G = as.matrix(read.table(output_file.G));
	} else {
		res$G = output_file.G;
	}
	if(percentage) {
		res$all_ce = resC$all_ce;
		res$masked_ce = resC$masked_ce;
	}

	res
}
