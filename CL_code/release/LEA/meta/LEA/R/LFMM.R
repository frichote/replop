LFMM <- function(input_file, 
		variable_file, 
		K,
		project,
		d = 0,
		all = FALSE,
		output_file,
		missing_data = FALSE,
		num_CPU = 1,
		num_iterations = 1000,
		num_burnin = 100,
		seed = -1, 
		repetitions = 1,
		epsilon_noise = 1e-3,
		epsilon_b = 1000,
		random_init = TRUE) 
{



        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# check extension and convert if necessary
	input_file = test_input_file(input_file, "lfmm")
	# cov file
	variable_file = test_character("variable_file", variable_file, NULL)
	# check extension
	test_extension(variable_file, "env")
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
		v = dim(read.env(variable_file))
		nD = v[2]
		d=1:nD
	}
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
	num_iterations = test_integer("num_iterations", num_iterations, 1000)
	if (num_iterations <= 0)
                stop("'num_iterations' argument has to be positive.")
        # num_burnin
	num_burnin = test_integer("num_burnin", num_burnin, 100)
	if (num_burnin <= 0)
                	stop("'num_burnin' argument has to be positive.")
	if (num_burnin >= num_iterations) {
                stop("the number of iterations for burnin (num_burnin) is greater than the number total of iterations (num_iterations)")
	}
	# seed
	seed = test_integer("seed", seed, -1)
        # repetitions
        repetitions = test_integer("repetitions", repetitions, 1)
        # epsilon_noise
        epsilon_noise = test_double("epsilon_noise", epsilon_noise, 1e-3)
        if (epsilon_noise < 0)
                epsilon_noise = 1e-3;
        # b_epsilon
        epsilon_b = test_double("epsilon_b", epsilon_b, 1000)
        if (epsilon_b < 0)
                epsilon_b = 1000;
	# random_init 
	random_init = test_logical("random_init", random_init, TRUE)

        # project
        if (missing(project)) {
                project = new("lfmmProject")
                project@input_file = input_file
                project@variable_file = variable_file
                tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.",input_file)
                tmp = paste(tmp, "lfmmProject", sep="")
                project@lfmmProject_file = paste(getwd(),"/", tmp, sep="")
                project@directory = getwd();
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
				output_prefix = paste(output_file,"_r", re, sep="")

				dic = 0
				dev = 0
				L = 0
				n = 0
				D = 0
				resC = 	.C("R_LFMM", 
					as.character(input_file),
					as.character(output_prefix),
					as.character(variable_file),
					n = as.integer(n),
					L = as.integer(L),
					D = as.integer(D),
					as.integer(d),
					as.integer(k),
					as.integer(num_iterations),
					as.integer(num_burnin),
					as.integer(num_CPU),
					seed = as.integer(seed),
					as.integer(missing_data),
					as.integer(all),
					dic = as.double(dic),
					dev = as.double(dev),
					epsilon_noise,
					epsilon_b,
					random_init
				);

				for (nd in 1:nD) { 
					# creation of the res file
					res = new("lfmmClass");
					res@zscore_file = paste(output_prefix,"_a",nd,".",k,".zscore",sep="");
					res@dic_file = paste(output_prefix,"_a.",k,".dic",sep="");
					res@lfmmClass_file = paste(output_prefix, "_a",nd,".",k,".lfmmClass",sep="");
					res@directory = getwd();
					res@K = as.integer(k);
					res@input_file = input_file; 
					res@variable_file = variable_file; 
        	                	res@d = as.integer(nd);
                	        	res@Niter = as.integer(num_iterations);
                        		res@burn = as.integer(num_burnin);
                        		res@CPU = as.integer(num_CPU);
	                        	res@seed = as.integer(seed);
        	                	res@missing_data = missing_data;
                	        	res@all = all;
					res@n = as.integer(resC$n);
					res@L = as.integer(resC$L);
					res@D = as.integer(resC$D);
					res@epsilon_noise = epsilon_noise;
					res@epsilon_b = epsilon_b;
					res@random_init = random_init;
					res@seed = resC$seed
					res@lambda = getLambda(res)
					res@deviance = resC$dev;
					res@DIC = resC$dic;
					seed = resC$seed
		                        write.lfmmClass(res, res@lfmmClass_file)

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
					output_prefix = paste(output_file,"_r", re, sep="")
	
					dic = 0
					dev = 0
					L = 0
					n = 0
					D = 0
					resC = 	.C("R_LFMM", 
						as.character(input_file),
						as.character(output_prefix),
						as.character(variable_file),
						n = as.integer(n),
						L = as.integer(L),
						D = as.integer(D),
						as.integer(nd),
						as.integer(k),
						as.integer(num_iterations),
						as.integer(num_burnin),
						as.integer(num_CPU),
						seed = as.integer(seed),
						as.integer(missing_data),
						as.integer(all),
						dic = as.double(dic),
						dev = as.double(dev),
						epsilon_noise,
						epsilon_b,
						random_init
					);

					# creation of the res file
					res = new("lfmmClass");
					res@zscore_file = paste(output_prefix,"_s",nd,".",k,".zscore",sep="");
					res@dic_file = paste(output_prefix,"_s",nd,".",k,".dic",sep="");
					res@lfmmClass_file = paste(output_prefix, "_s",nd,".",k,".lfmmClass",sep="");
					res@directory = getwd();
					res@K = as.integer(k);
					res@input_file = input_file; 
					res@variable_file = variable_file; 
        	                	res@d = as.integer(nd);
                	        	res@Niter = as.integer(num_iterations);
                        		res@burn = as.integer(num_burnin);
                        		res@CPU = as.integer(num_CPU);
	                        	res@seed = as.integer(seed);
        	                	res@missing_data = missing_data;
                	        	res@all = all;
					res@n = as.integer(resC$n);
					res@L = as.integer(resC$L);
					res@D = as.integer(resC$D);
					res@epsilon_noise = epsilon_noise;
					res@epsilon_b = epsilon_b;
					res@random_init = random_init;
					res@seed = resC$seed
					res@lambda = getLambda(res)
					res@deviance = resC$dev;
					res@DIC = resC$dic;
					seed = resC$seed
					write.lfmmClass(res, res@lfmmClass_file);

					project = addRun.lfmmProject(project, res);
				} 
			}
		}	
	}

        write.lfmmProject(project, project@lfmmProject_file)

	return(project);
} 
