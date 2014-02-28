\name{write.env}
\alias{write.env}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{env}} format}
\description{
write a file in the \code{\link{env}} format.
}
\usage{
write.env(R, output_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the environmental variables with one line per individual
        and one column per environmental variable. The missing genotypes have to be
	encoded with the value 9.
}
\item{output_file}{
	the path for the output file (in \code{env} format).
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{read.env}}
\code{\link{env}}
\code{\link{LFMM}}
}
\examples{
# creation of the example.geno file
data("tuto")

# write of the tuto environmental file
#write.env(C,"tuto.env")

# read of the tuto environmental file
#C2 = read.env("tuto.env")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
