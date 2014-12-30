\name{env}
\alias{env}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Environmental input file format for \code{\link{LFMM}}}
\description{

Description of the \code{env} format. The \code{env} format 
can be used as an input format for the environmental variables 
in the \code{\link{LFMM}} function. 
}
\details{
The \code{env} format has one row for each individual. Each row contains one 
value for each environmental variable (separated by spaces or tabulations).

Here is an example of an environmental file using the \code{env} format with 
3 individuals and 2 variable:
\preformatted{
0.252477 0.95250639
0.216618 0.10902647
-0.47509 0.07626694
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{LFMM}}
\code{\link{read.env}}
\code{\link{write.env}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
