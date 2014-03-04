lambda <- function(p) 
{
        if(missing(p))
                stop("'p' argument is missing.")
        else if (!(is.vector(p)))
                stop("'p' argument has to be of type matrix, data.frame or vector.")

       return(qchisq(.5, df = 1) / median(qchisq(p, df = 1)));
}

