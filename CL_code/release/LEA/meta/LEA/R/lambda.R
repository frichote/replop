lambda <- function(p) 
{
        if(missing(p))
                stop("'p' argument is missing.")
        else if (!(is.vector(R)))
                stop("'p' argument has to be of type matrix, R.frame or vector.")

       return(qchisq(.5, df = 1) / median(qchisq(p, df = 1)));
}

