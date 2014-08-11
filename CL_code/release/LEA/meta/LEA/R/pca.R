pca <- function(input.file, 
		K, 
		center = TRUE, 
		scale  = FALSE) 
#		eigenvalue.file, 
#		eigenvector.file, 
#		sdev.file, 
#		projection.file) 
{

        # test arguments and init
	# input file
	input.file = test_character("input.file", input.file, NULL)
	# check extension and convert if necessary
	input.file = test_input_file(input.file, "lfmm")
	#K
	K = test_integer("K", K, 0);
        if (K < 0)
                stop("'K positive.")
	# center
	center = test_logical("center", center, 1);
	# scaled
	scale = test_logical("scale", scale, 0);
	# eigenvalues file 
        eigenvalue.file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvalues",input.file)
	#eigenvalue_file = test_character("eigenvalue_file", eigenvalue_file, tmp)
	# eigenvectors file 
        eigenvector.file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.eigenvectors",input.file)
	#eigenvector_file = test_character("eigenvector_file", eigenvector_file, tmp)
	# standard deviation file 
        sdev.file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.sdev",input.file)
	#sdev_file = test_character("sdev_file", sdev_file, tmp)
	# x file 
        projection.file = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.projections",input.file)
	#projection_file = test_character("projection_file", projection_file, tmp)

	print("******************************");
	print(" Principal Component Analysis ");
	print("******************************");

	L = 0;
	n = 0
    	resC = .C("R_pca", 
		as.character(input.file),
		as.character(eigenvalue.file),
		as.character(eigenvector.file),
		as.character(sdev.file),
		as.character(projection.file),
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
	res@input.file = input.file;
	res@eigenvalue.file = eigenvalue.file;
	res@eigenvector.file = eigenvector.file;
	res@sdev.file = sdev.file;
	res@projection.file = projection.file;

        tmp = gsub("([^.]+)\\.[[:alnum:]]+$", "\\1.pcaClass",input.file)
	res@pcaClass.file = tmp
	save.pcaClass(res, tmp); 

	res
}
