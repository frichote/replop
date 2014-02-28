\name{read.lfmm}
\alias{read.lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Read files in the \code{\link{lfmm}} format}
\description{
read a file in the \code{\link{lfmm}} format.
}
\usage{
read.lfmm(input_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the input file (in \code{lfmm} format).
}
}
\value{
\item{R}{
	A matrix containing the genotypes with one line per individual and one column per SNP.
}
}

\author{
    Eric Frichot
}
\seealso{
\code{\link{write.lfmm}}
\code{\link{lfmm}}
\code{\link{LFMM}}
\code{\link{geno2lfmm}}
\code{\link{lfmm2geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ped2lfmm}}
}
\examples{
# creation of example.geno
data("example_lfmm")
write.table(example_lfmm,"example.lfmm",col.names = FALSE, row.names = FALSE, quote = FALSE)

# read of the geno file
R = read.geno("example.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}

