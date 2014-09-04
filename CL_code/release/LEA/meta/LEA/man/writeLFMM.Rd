\name{write.lfmm}
\alias{write.lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{lfmm}} format}
\description{
Write a file in the \code{\link{lfmm}} format.
}
\usage{
write.lfmm(R, output.file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the genotypes with one line for each individual and one column for each SNP. 
	The missing genotypes have to be encoded with the value 9.
}
\item{output.file}{
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
# Creation of a file called "genotypes.geno" in the working directory,
# with 5000 SNPs for 165 individuals.
data("tutorial")

# write R in a file called "genotypes.lfmm"
# Create file:	"genotypes.lfmm".
write.lfmm(R, "genotypes.lfmm")

# read the file "genotypes.lfmm".
R = read.lfmm("genotypes.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{read/write}
