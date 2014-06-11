\name{read.env}
\alias{read.env}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Read environmental file in the \code{\link{env}}format}
\description{
Read a file in the \code{\link{env}} format.
}
\usage{
read.env(input_file)
}
\arguments{
\item{input_file}{
a character string containing a path to the input file,
an environmental data matrix in the \code{\link{env}} format.
}
}
\value{
\item{R}{
        A matrix containing the environmental variables with one line for each individual 
	and one column for each environmental variable.
}
}

\author{
    Eric Frichot
}
\seealso{
\code{\link{env}}
\code{\link{write.env}}
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
