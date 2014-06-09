pca <- function(input_file, 
		K, 
		center = TRUE, 
		scale  = FALSE) 
#		eigenvalue_file, 
#		eigenvector_file, 
#		sdev_file, 
#		projection_file) 
{

        # test arguments and init
	# input file
	input_file = test_character("input_file", input_file, NULL)
	# check extension and convert if necessary
	input_file = test_input_file(input_file, "lfmm")
	#K
	K = test_integer("K", K, 0);
        if (K < 0)
                stop("'K positive.")
	# center
	center = test_logical("center", center, 1);
	# scaled
	scale = test_logical("scale", scale, 0);
	# eigenvalues file 
        eigenvalue_file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvalues",input_file)
	#eigenvalue_file = test_character("eigenvalue_file", eigenvalue_file, tmp)
	# eigenvectors file 
        eigenvector_file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvectors",input_file)
	#eigenvector_file = test_character("eigenvector_file", eigenvector_file, tmp)
	# standard deviation file 
        sdev_file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.sdev",input_file)
	#sdev_file = test_character("sdev_file", sdev_file, tmp)
	# x file 
        projection_file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.projections",input_file)
	#projection_file = test_character("projection_file", projection_file, tmp)

	print("******************************");
	print(" Principal Component Analysis ");
	print("******************************");

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
	res@pcaClass_file = tmp
	write.pcaClass(res, tmp); 

	res
}
