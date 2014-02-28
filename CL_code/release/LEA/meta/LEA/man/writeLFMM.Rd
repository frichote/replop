\name{write.lfmm}
\alias{write.lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{lfmm}} format}
\description{
write a file in the \code{\link{lfmm}} format.
}
\usage{
write.lfmm(R, output_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the genotypes with one line per individual and one column per SNP. The missing genotypes have to be encoded with the value 9.
}
\item{output_file}{
	the path for the output file (in \code{geno} format).
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{read.lfmm}}
\code{\link{lfmm}}
\code{\link{LFMM}}
\code{\link{geno2lfmm}}
\code{\link{lfmm2geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ped2lfmm}}
}
\examples{
# creation of the example.geno file
data("example_lfmm")
write.table(example_lfmm,"example.lfmm",col.names = FALSE, row.names = FALSE, quote = FALSE)

# read of the lfmm file
R = read.lfmm("example.lfmm")

# wite of the lfmm file 
write.lfmm(R, "example2.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
