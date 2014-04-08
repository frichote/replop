pca <- function(input_file, 
		K, 
		center = TRUE, 
		scale  = FALSE, 
		eigenvalue_file, load_eigenvalues = TRUE, 
		eigenvector_file, load_eigenvectors = TRUE, 
		sdev_file, load_sdev = TRUE, 
		projection_file, load_projections = TRUE) 
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
	eigenvalue_file = test_character("eigenvalue_file", eigenvalue_file, tmp)
	# load eigenvalues
	load_eigenvalues = test_logical("load_eigenvalues", load_eigenvalues, TRUE)
	# eigenvectors file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvectors",input_file)
	eigenvector_file = test_character("eigenvector_file", eigenvector_file, tmp)
	# load eigenvectors
	load_eigenvectors = test_logical("load_eigenvectors", load_eigenvectors, TRUE)
	# standard deviation file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.sdev",input_file)
	sdev_file = test_character("sdev_file", sdev_file, tmp)
	# load sdev
	load_sdev = test_logical("load_sdev", load_sdev, TRUE)
	# x file 
        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.projections",input_file)
	projection_file = test_character("projection_file", projection_file, tmp)
	# load x
	load_projections = test_logical("load_projections", load_projections, TRUE)

	L = 0;
	n = 0
    	resC = .C("R_pca", 
		as.character(input_file),
		as.character(eigenvalue_file),
		as.character(eigenvector_file),
		as.character(sdev_file),
		as.character(projection_file),
		n = as.integer(n),
		L = as.integer(L),
		K = as.integer(K),
		as.integer(center),
		as.integer(scale)
	);

	res = new("pcaClass");
	res@directory = getwd();
	res@n = as.integer(resC$n);
	res@L = as.integer(resC$L);
	res@K = as.integer(resC$K);
	res@center = center;
	res@scale = scale;
	res@input_file = input_file;
	res@eigenvalue_file = eigenvalue_file;
	res@eigenvector_file = eigenvector_file;
	res@sdev_file = sdev_file;
	res@projection_file = projection_file;

        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.pcaClass",input_file)
	write(res, tmp); 

	res
}
