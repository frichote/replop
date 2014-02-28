\name{read.env}
\alias{read.env}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Read environmental file in the \code{\link{env}}format}
\description{
read a file in the \code{\link{env}} format.
}
\usage{
read.env(input_file)
}
\arguments{
\item{input_file}{
	the path for the environmental input file (in \code{\link{env}} format).
}
}
\value{
\item{R}{
        A matrix containing the environmental variables with one line per individual 
	and one column per environmental variable.
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
# creation of example.geno
#data("tuto")
#write.env(C,"tuto.env")

# read of the geno file
#C2 = read.env("tuto.env")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
