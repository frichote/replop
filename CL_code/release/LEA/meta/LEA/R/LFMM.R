LFMM <- function(input.file, 
		variable.file, 
		K,
		d = 0,
		all = FALSE,
		missing.data = FALSE,
		CPU = 1,
		iterations = 1000,
		burnin = 100,
		seed = -1, 
		repetitions = 1,
		epsilon.noise = 1e-3,
		epsilon.b = 1000,
		random.init = TRUE) 
{



        # test arguments and init
	# input file
	input.file = test_character("input.file", input.file, NULL)
	# check extension and convert if necessary
	input.file = test_input_file(input.file, "lfmm")
	# cov file
	variable.file = test_character("variable.file", variable.file, NULL)
	# check extension
	test_extension(variable.file, "env")
	# K
	for (k in 1:length(K)) {
		K[k] = test_integer("K", K[k], NULL)
 		if (K[k] < 0)
			stop("'K' argument has to be not negative.")
	}
	# nd
	if (!missing(d)) {
		for (ndd in 1:length(d)) {
			d[ndd] = test_integer("nd", d[ndd], 1)
			if(d[ndd] <= 0)
				d[ndd] = 1;
		}
	} else {
		v = dim(read.env(variable.file))
		nD = v[2]
		d=1:nD
	}
	# all
	all = test_logical("all",all, FALSE)
	# output.file
	output.file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1", input.file)
	# missing.data  
	missing.data = test_logical("missing.data", missing.data, FALSE)
	# CPU	
	CPU = test_integer("CPU", CPU, 1)
	if (CPU <= 0)
                CPU = 1;
	#ifdef windows
		CPU = 1;
	#endif
        # iterations
	iterations = test_integer("iterations", iterations, 1000)
	if (iterations <= 0)
                stop("'iterations' argument has to be positive.")
        # burnin
	burnin = test_integer("burnin", burnin, 100)
	if (burnin <= 0)
                	stop("'burnin' argument has to be positive.")
	if (burnin >= iterations) {
                stop("the number of iterations for burnin (burnin) is greater than the number total of iterations (iterations)")
	}
	# seed
	seed = test_integer("seed", seed, -1)
        # repetitions
        repetitions = test_integer("repetitions", repetitions, 1)
        # epsilon.noise
        epsilon.noise = test_double("epsilon.noise", epsilon.noise, 1e-3)
        if (epsilon.noise < 0)
                epsilon.noise = 1e-3;
        # b.epsilon
        epsilon.b = test_double("epsilon.b", epsilon.b, 1000)
        if (epsilon.b < 0)
                epsilon.b = 1000;
	# random.init 
	random.init = test_logical("random.init", random.init, TRUE)

        # project
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input.file)
        tmp2 = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.",variable.file)
        projectName = paste(tmp, "_", tmp2 , "lfmmProject", sep="")
        # creation of the project if it does not exist
	if (!file.exists(projectName)) {
                project = new("lfmmProject")
                project@input.file = input.file
                project@variable.file = variable.file
                project@lfmmProject.file = paste(getwd(),"/", projectName, sep="")
                project@directory = getwd();
        # or load the existing project
        } else {
                project = load.lfmmProject(projectName)
        }

	for (r in 1:repetitions) {
		for (k in K) {
			if (all) {
	                        print("*************************************");
        	                p = paste("* LFMM K =",k," repetition",r," all     *");
                	        print(p);
                        	print("*************************************");

				if (length(project@K) > 0)
	                        	re = length(which(project@K == k & project@all == all)) + 1
				else 
					re = 1
				output.prefix = paste(output.file,"_r", re, sep="")

				dic = 0
				dev = 0
				L = 0
				n = 0
				D = 0
				resC = 	.C("R_LFMM", 
					as.character(input.file),
					as.character(output.prefix),
					as.character(variable.file),
					n = as.integer(n),
					L = as.integer(L),
					D = as.integer(D),
					as.integer(d),
					as.integer(k),
					as.integer(iterations),
					as.integer(burnin),
					as.integer(CPU),
					seed = as.integer(seed),
					as.integer(missing.data),
					as.integer(all),
					dic = as.double(dic),
					dev = as.double(dev),
					epsilon.noise,
					epsilon.b,
					random.init
				);

				for (nd in 1:nD) { 
					# creation of the res file
					res = new("lfmmClass");
					res@zscore.file = paste(output.prefix,"_a",nd,".",k,".zscore",sep="");
					res@lfmmClass.file = paste(output.prefix, "_a",nd,".",k,".lfmmClass",sep="");
					res@directory = getwd();
					res@K = as.integer(k);
					res@input.file = input.file; 
					res@variable.file = variable.file; 
        	                	res@d = as.integer(nd);
                	        	res@Niter = as.integer(iterations);
                        		res@burn = as.integer(burnin);
                        		res@CPU = as.integer(CPU);
	                        	res@seed = as.integer(seed);
        	                	res@missing.data = missing.data;
                	        	res@all = all;
					res@n = as.integer(resC$n);
					res@L = as.integer(resC$L);
					res@D = as.integer(resC$D);
					res@epsilon.noise = epsilon.noise;
					res@epsilon.b = epsilon.b;
					res@random.init = random.init;
					res@seed = resC$seed
					res@inflationFactor = inflationFactor(res)
					res@deviance = resC$dev;
					res@DIC = resC$dic;
					seed = resC$seed
		                        save.lfmmClass(res, res@lfmmClass.file)

					project = addRun.lfmmProject(project, res);
				}
			} else {
				for (nd in d) {
		                        print("********************************");
        		                p = paste("* K =",k," repetition",r," d =",nd,"  *");
                		        print(p);
                        		print("********************************");
			
					if (length(project@K) > 0)
	                        		re = length(which(project@K == k & project@d == nd & project@all == all)) + 1
					else 
						re = 1
					output.prefix = paste(output.file,"_r", re, sep="")
	
					dic = 0
					dev = 0
					L = 0
					n = 0
					D = 0
					resC = 	.C("R_LFMM", 
						as.character(input.file),
						as.character(output.prefix),
						as.character(variable.file),
						n = as.integer(n),
						L = as.integer(L),
						D = as.integer(D),
						as.integer(nd),
						as.integer(k),
						as.integer(iterations),
						as.integer(burnin),
						as.integer(CPU),
						seed = as.integer(seed),
						as.integer(missing.data),
						as.integer(all),
						dic = as.double(dic),
						dev = as.double(dev),
						epsilon.noise,
						epsilon.b,
						random.init
					);

					# creation of the res file
					res = new("lfmmClass");
					res@zscore.file = paste(output.prefix,"_s",nd,".",k,".zscore",sep="");
					res@lfmmClass.file = paste(output.prefix, "_s",nd,".",k,".lfmmClass",sep="");
					res@directory = getwd();
					res@K = as.integer(k);
					res@input.file = input.file; 
					res@variable.file = variable.file; 
        	                	res@d = as.integer(nd);
                	        	res@Niter = as.integer(iterations);
                        		res@burn = as.integer(burnin);
                        		res@CPU = as.integer(CPU);
	                        	res@seed = as.integer(seed);
        	                	res@missing.data = missing.data;
                	        	res@all = all;
					res@n = as.integer(resC$n);
					res@L = as.integer(resC$L);
					res@D = as.integer(resC$D);
					res@epsilon.noise = epsilon.noise;
					res@epsilon.b = epsilon.b;
					res@random.init = random.init;
					res@seed = resC$seed
					res@inflationFactor = inflationFactor(res)
					res@deviance = resC$dev;
					res@DIC = resC$dic;
					seed = resC$seed
					save.lfmmClass(res, res@lfmmClass.file);

					project = addRun.lfmmProject(project, res);
				} 
			}
		}	
	}

        save.lfmmProject(project)

	return(project);
} 
