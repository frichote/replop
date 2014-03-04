write.env <- function(R, output_file) 
{

        if(missing(R))
                stop("'R' argument is missing.")
        else if (!(is.matrix(R) || is.data.frame(R) || is.vector(R)))
                stop("'R' argument has to be of type matrix, data.frame or vector.")
	else if (is.vector(R))
		R = matrix(R,ncol=1,nrow=length(R))
	else if (is.data.frame(R))
		R = as.matrix(R)

	output_file = test_character("output_file", output_file, NULL)

	if(is.na(R) || is.nan(R)) {
		stop("'R' matrix contains Na.")
	}

	write.table(R,output_file, col.names=FALSE,row.names=FALSE);
	
	return(output_file);
}
