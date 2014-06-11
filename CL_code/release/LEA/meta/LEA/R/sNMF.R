sNMF <- function(input_file, 
		K, 
		alpha = 10, 
		tolerance = 0.00001, 
		entropy = FALSE,
		percentage = 0.05,
		I, 
		iterations = 200, 
		ploidy = 2, 
		seed = -1, 
		num_CPU = 1, 
		Q_input_file,
	#	output_files, 
		repetitions = 1)
{

        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# check extension and convert if necessary 
	input_file = test_input_file(input_file, "geno")
	# K
	for (k in 1:length(K)) {
		K[k] = test_integer("K", K[k], NULL)
		if (K[k] <= 0)
               		stop("'K' argument has to be positive.")
	}
	# alpha
	alpha = test_double("alpha", alpha, 10)
	if (alpha < 0)
                alpha = 0
	# tolerance
	tolerance = test_double("tolerance", tolerance, 0.00001)
	if (tolerance <= 0)
		tolerance = 0.00001
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
	# input Q
	Q_input_file = test_character("Q_input_file", Q_input_file, "")
	# test extension
	if (Q_input_file != "")
		test_extension(Q_input_file, "Q")
	# I	
	I = test_integer("I", I, 0)
        if (I < 0)
                stop("'I' argument has to be of type positive.")
	# repetitions
	repetitions = test_integer("repetitions", repetitions, 1)
	
	# project
	tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.",input_file)	
	projectName = paste(tmp, "snmfProject", sep="")
	# creation of the project if it does not exist
	if (!file.exists(projectName)) {
		project = new("snmfProject")
		project@input_file = input_file
		project@snmfProject_file = paste(getwd(),"/", projectName, sep="")
		project@directory = getwd();
	# or load the existing project
	} else {
		project = load.snmfProject(projectName)
	}
	
	for (r in 1:repetitions) {
		for (k in K) {
			print("*************************************");
			p = paste("* sNMF K =",k," repetition",r,"         *");
			print(p);
			print("*************************************");

			

			re = length(which(project@K == k)) + 1
			# Q file 
		        base = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input_file)
			# test si un run du meme nom n existe pas ?
		        Q_output_file = paste(base,"_r", re ,".",k, ".Q", sep="")
#			Q_output_file = test_character("Q_output_file", Q_output_file, tmp)
			# G file
		        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input_file)
		        G_output_file = paste(tmp,"_r", re ,".",k, ".G", sep="")
			# G_output_file = test_character("G_output_file", G_output_file, tmp)

			# TODO on peut aussi tester que le fichier n est pas déjà existant 
		        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input_file)
		        snmfClass_file = paste(tmp,"_r", re ,".",k, ".snmfClass", sep="")

			# creation of the res file
			res = new("snmfClass")

			all_ce = 0;
			masked_ce = 0;
			seed = 0;
			n = 0;
			L = 0;
		    	resC = .C("R_sNMF", 
				as.character(input_file),
				as.integer(k),
				as.double(alpha),
				as.double(tolerance),
				as.double(percentage),
				as.integer(iterations),
				seed = as.integer(seed),
				as.integer(ploidy),
				as.integer(num_CPU),
				as.character(Q_input_file),
				as.character(Q_output_file),
				as.character(G_output_file),
				as.integer(I),
				all_ce = as.double(all_ce),
				masked_ce = as.double(masked_ce),
				n = as.integer(n),
				L = as.integer(L)
			);
		
			res@directory = getwd();
			res@input_file = input_file;
			res@snmfClass_file  = snmfClass_file;
			res@n = resC$n;
			res@L = resC$L;
			res@K = as.integer(k);
			res@CPU = as.integer(num_CPU);
			res@seed = as.integer(resC$seed);
			res@alpha = alpha;
			res@percentage = percentage;
			res@I = as.integer(I);
			res@iterations = as.integer(iterations);
			res@entropy = entropy;
			res@tolerance = tolerance;
			res@crossEntropy = resC$masked_ce;
			res@ploidy = as.integer(ploidy);
			res@Q_input_file = Q_input_file;
			res@Q_output_file = Q_output_file;
			res@G_output_file = G_output_file;
			save.snmfClass(res, res@snmfClass_file)

			project = addRun.snmfProject(project, res);
		}
	}
	save.snmfProject(project)

	return(project);
}
