read.geno <- function(input_file) {

        # test arguments and init
        # input file
        if(missing(input_file))
                stop("'input_file' argument is missing.")
        else if (!is.character(input_file))
                stop("'input_file' argument has to be of type character.")

	x = scan(file = "example.geno", what = "character", skip = 0, sep ="" )

	if(length(x) > 0) {
  		M = length(x)
	} else {
  		stop("'input_file' is empty.")
	}

	line = strsplit(x[1],NULL)
	N = length(line[[1]])

	return(apply(as.matrix(x),1, function(x){as.integer((strsplit(x,NULL))[[1]])}))
}
