\name{read.lfmm}
\alias{read.lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Read files in the \code{\link{lfmm}} format}
\description{
Read a file in the \code{\link{lfmm}} format.
}
\usage{
read.lfmm(input.file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input.file}{
A character string containing a path to the input file,
a genotypic matrix in the \code{lfmm} format.
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
# Creation of a file called "genotypes.lfmm" in the working directory,
# with 5000 SNPs for 165 individuals.
data("tutorial")
write.lfmm(R, "genotypes.lfmm")

# write G in a file called "genotypes.lfmm"
# Create file:	"genotypes.lfmm".
write.lfmm(G, "genotypes.lfmm")

# read the file "genotypes.lfmm".
G = read.lfmm("genotypes.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{read/write}

