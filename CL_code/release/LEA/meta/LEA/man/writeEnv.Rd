\name{write.env}
\alias{write.env}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{env}} format}
\description{
Write a file in the \code{\link{env}} format.
}
\usage{
write.env(R, output_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the environmental variables with one line for each individual
        and one column for each environmental variable. The missing genotypes have to be
	encoded with the value 9.
}
\item{output_file}{
a character string containing a path to the output file,
an environmental data matrix in the \code{env} formt.
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
# Creation of an environmental matrix C 
# containing 2 environmental variables for 3 individuals.
# C contains one line for each individual and one column for each variable.
C = matrix(runif(6), ncol=2, nrow=3)

# Write C in a file called "tuto.env".
# Create file:	"tuto.env".
write.env(C,"tuto.env")

# Read the file "tuto.env".
C = read.env("tuto.env")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
