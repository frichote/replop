LFMM <- function(input_file, 
		variable_file, 
		K,
		nd = 0,
		all = FALSE,
		output_file,
		missing_data = FALSE,
		num_CPU = 1,
		num_iterations = 1000,
		num_burnin = 100,
		seed = -1, 
		DIC_file) 
{
        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# cov file
	variable_file = test_character("variable_file", variable_file, NULL)
	# K
	for (k in 1:length(K)) {
		K[k] = test_integer("K", K[k], NULL)
 		if (K[k] < 0)
			stop("'K' argument has to be not negative.")
	}
	# nd
	if (nd) {
		for (ndd in 1:length(nd)) {
			nd[ndd] = test_integer("nd", nd[ndd], 0)
			if(nd[ndd] <= 0)
				nd[ndd] = 0;
		}
	} else {
		nd = test_integer("nd", nd, 0)
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
	# DIC_file
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1",input_file)
	DIC_file = test_character("DIC_file", DIC_file, tmp)

	# creation of the res file
	res = new("lfmmClass");
	res@directory = getwd();
	res@K = as.integer(K);
	res@input_file = input_file; 
	res@variable_file = variable_file; 
	res@d = as.integer(nd);
	res@Niter = as.integer(num_iterations);
	res@burn = as.integer(num_burnin);
	res@CPU = as.integer(num_CPU);
	res@seed = as.integer(seed);
	res@missing_data = missing_data;
	res@all = all;

	v = read.env(variable_file);
	D = dim(v)[2];
	rm(v)
	

	colNames = paste("K=", K, sep="")
	if (all) {
		rowNames = paste("d=",1:D,sep="")
		res@zscore_file = matrix(NA, ncol=length(K), nrow=D, dimnames=list(rowNames, colNames));
		res@dic_file = matrix(NA, ncol=length(K), nrow=D, dimnames=list(rowNames, colNames));
		for (i in 1:length(K)) {
			res@zscore_file[,i] = paste(output_file,"_a",1:D,".",K[i],".zscore",sep="");
			res@dic_file[,i] = paste(output_file,"_a",1:D,".",K[i],".dic",sep="");
		}
	} else if (!nd) {
		rowNames = paste("d=",1:D,sep="")
		res@zscore_file = matrix(NA, ncol=length(K), nrow=D, dimnames=list(rowNames, colNames));
		res@dic_file = matrix(NA, ncol=length(K), nrow=D, dimnames=list(rowNames, colNames));
		for (i in 1:length(K)) {
			res@zscore_file[,i] = paste(output_file,"_s",1:D,".",K[i],".zscore",sep="");
			res@dic_file[,i] = paste(output_file,"_s",1:D,".",K[i],".dic",sep="");
		}
	} else {
		rowNames = paste("d=",nd,sep="")
		res@zscore_file = matrix(NA, ncol=length(K), nrow=length(nd), dimnames=list(rowNames, colNames));
		res@dic_file = matrix(NA, ncol=length(K), nrow=length(nd), dimnames=list(rowNames, colNames));
		for (i in 1:length(K)) {
			res@zscore_file[,i] = paste(output_file,"_s",nd,".",K[i],".zscore",sep="");
			res@dic_file[,i] = paste(output_file,"_s",nd,".",K[i],".dic",sep="");
		}
	}

	dic = 0
	dev = 0
	L = 0
	n = 0
	D = 0
	seed = -1
	for (k in K) {
		for (ndd in nd) {
			resC = 	.C("R_LFMM", 
				as.character(input_file),
				as.character(output_file),
				as.character(variable_file),
				as.character(DIC_file),
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
				dev = as.double(dev)
			);
			res@n = as.integer(resC$n);
			res@L = as.integer(resC$L);
			res@D = as.integer(resC$D);
			res@seed = resC$seed
			seed = resC$seed
		}
	}


	tmp = paste(output_file, ".lfmmClass", sep="")
	res@lfmmClass_file = tmp;
	write(res, tmp);

	res
} 
