read.lfmm <- function(input_file) {

        # test arguments
        if(missing(input_file))
                stop("'input_file' argument is missing.")
        else if (!is.character(input_file))
                stop("'input_file' argument has to be of type character.")

	return(as.matrix(read.table(input_file)))
}
