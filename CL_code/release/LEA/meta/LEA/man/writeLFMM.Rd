\name{write.lfmm}
\alias{write.lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{lfmm}} format}
\description{
Write a file in the \code{\link{lfmm}} format.
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
A character string containing a path to the output file,
a genotypic matrix in the \code{lfmm} format.
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
# Creation of a genotypic matrix G with 1000 SNPs for 100 individuals.
# The G matrix contains one individual per line and one locus per column.
G = matrix(sample(c(0,1,2),replace=TRUE, size=1000*100), ncol=1000, nrow=100)

# write G in a file called "tuto.lfmm"
# Create file:	"tuto.lfmm".
write.lfmm(G, "tuto.lfmm")

# read the file "tuto.lfmm".
G = read.lfmm("tuto.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
