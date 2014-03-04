pca <- function(input_file, 
		K, 
		center = TRUE, 
		scale  = FALSE, 
		output_file.eigenvalues, load.eigenvalues = TRUE, 
		output_file.eigenvectors, load.eigenvectors = TRUE, 
		output_file.sdev, load.sdev = TRUE, 
		output_file.projections, load.projections = TRUE) 
{

        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# K
	K = test_integer("K", K, 0);
        if (K < 0)
                stop("'K positive.")
	# center
	center = test_logical("center", center, 1);
	# scaled
	scale = test_logical("scale", scale, 0);
	# eigenvalues file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvalues",input_file)
	output_file.eigenvalues = test_character("output_file.eigenvalues", output_file.eigenvalues, tmp)
	# load eigenvalues
	load.eigenvalues = test_logical("load.eigenvalues", load.eigenvalues, TRUE)
	# eigenvectors file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvectors",input_file)
	output_file.eigenvectors = test_character("output_file.eigenvectors", output_file.eigenvectors, tmp)
	# load eigenvectors
	load.eigenvectors = test_logical("load.eigenvectors", load.eigenvectors, TRUE)
	# standard deviation file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.sdev",input_file)
	output_file.sdev = test_character("output_file.sdev", output_file.sdev, tmp)
	# load sdev
	load.sdev = test_logical("load.sdev", load.sdev, TRUE)
	# x file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.projections",input_file)
	output_file.projections = test_character("output_file.projections", output_file.projections, tmp)
	# load x
	load.projections = test_logical("load.projections", load.projections, TRUE)

    	.C("R_pca", 
		as.character(input_file),
		as.character(output_file.eigenvalues),
		as.character(output_file.eigenvectors),
		as.character(output_file.sdev),
		as.character(output_file.projections),
		as.integer(K),
		as.integer(center),
		as.integer(scale)
	);


	res = list();
	if (load.eigenvalues) {
		res$eigenvalues = as.matrix(read.table(output_file.eigenvalues));	
	} else {
		res$eigenvalues = output_file.eigenvalues;
	}
	if (load.eigenvectors) {
		res$eigenvectors = as.matrix(read.table(output_file.eigenvectors));	
	} else {
		res$eigenvectors = output_file.eigenvectors;
	}
	if (load.sdev) {
		res$sdev = as.matrix(read.table(output_file.sdev));	
	} else {
		res$sdev = output_file.sdev;
	}
	if (load.projections) {
		res$projections = as.matrix(read.table(output_file.projections));	
	} else {
		res$projections = output_file.projections;
	}
	res
}
