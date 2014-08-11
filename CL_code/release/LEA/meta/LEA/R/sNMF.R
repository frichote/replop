sNMF <- function(input.file, 
		K, 
		alpha = 10, 
		tolerance = 0.00001, 
		entropy = FALSE,
		percentage = 0.05,
		I, 
		iterations = 200, 
		ploidy = 2, 
		seed = -1, 
		CPU = 1, 
		Q.input.file,
	#	output.files, 
		repetitions = 1)
{

        # test arguments and init
	# input file
	input.file = test_character("input.file", input.file, NULL)
	# check extension and convert if necessary 
	input.file = test_input_file(input.file, "geno")
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
	CPU = test_integer("CPU", CPU, 1)
        if (CPU <= 0)
                CPU = 1;
	#ifdef windows
		CPU = 1;
	#endif
	# input Q
	Q.input.file = test_character("Q.input.file", Q.input.file, "")
	# test extension
	if (Q.input.file != "")
		test_extension(Q.input.file, "Q")
	# I	
	I = test_integer("I", I, 0)
        if (I < 0)
                stop("'I' argument has to be of type positive.")
	# repetitions
	repetitions = test_integer("repetitions", repetitions, 1)
	
	# project
	tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.",input.file)	
	projectName = paste(tmp, "snmfProject", sep="")
	# creation of the project if it does not exist
	if (!file.exists(projectName)) {
		project = new("snmfProject")
		project@input.file = input.file
		project@snmfProject.file = paste(getwd(),"/", projectName, sep="")
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
		        base = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input.file)
			# test si un run du meme nom n existe pas ?
		        Q.output.file = paste(base,"_r", re ,".",k, ".Q", sep="")
#			Q_output_file = test_character("Q_output_file", Q_output_file, tmp)
			# G file
		        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input.file)
		        G.output.file = paste(tmp,"_r", re ,".",k, ".G", sep="")
			# G_output_file = test_character("G_output_file", G_output_file, tmp)

			# TODO on peut aussi tester que le fichier n est pas déjà existant 
		        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input.file)
		        snmfClass.file = paste(tmp,"_r", re ,".",k, ".snmfClass", sep="")

			# creation of the res file
			res = new("snmfClass")

			all.ce = 0;
			masked.ce = 0;
			seed = 0;
			n = 0;
			L = 0;
		    	resC = .C("R_sNMF", 
				as.character(input.file),
				as.integer(k),
				as.double(alpha),
				as.double(tolerance),
				as.double(percentage),
				as.integer(iterations),
				seed = as.integer(seed),
				as.integer(ploidy),
				as.integer(CPU),
				as.character(Q.input.file),
				as.character(Q.output.file),
				as.character(G.output.file),
				as.integer(I),
				all.ce = as.double(all.ce),
				masked.ce = as.double(masked.ce),
				n = as.integer(n),
				L = as.integer(L)
			);
		
			res@directory = getwd();
			res@input.file = input.file;
			res@snmfClass.file  = snmfClass.file;
			res@n = resC$n;
			res@L = resC$L;
			res@K = as.integer(k);
			res@CPU = as.integer(CPU);
			res@seed = as.integer(resC$seed);
			res@alpha = alpha;
			res@percentage = percentage;
			res@I = as.integer(I);
			res@iterations = as.integer(iterations);
			res@entropy = entropy;
			res@tolerance = tolerance;
			res@crossEntropy = resC$masked.ce;
			res@ploidy = as.integer(ploidy);
			res@Q.input.file = Q.input.file;
			res@Q.output.file = Q.output.file;
			res@G.output.file = G.output.file;
			save.snmfClass(res, res@snmfClass.file)

			project = addRun.snmfProject(project, res);
		}
	}
	save.snmfProject(project)

	return(project);
}
