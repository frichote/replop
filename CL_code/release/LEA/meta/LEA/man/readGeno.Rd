\name{read.geno}
\alias{read.geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{read a file in the \code{\link{geno}} format}
\description{
Read a file in the \code{\link{geno}} format.
}
\usage{
read.geno(input.file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input.file}{
A character string containing a path to the input file,
a genotypic matrix in the \code{geno} format.
}
}
\value{
\item{R}{
A matrix containing the genotypes with one line for each individual and one column for each SNP.
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{write.geno}}
\code{\link{geno}}
\code{\link{sNMF}}
\code{\link{geno2lfmm}}
\code{\link{lfmm2geno}}
\code{\link{ancestrymap2geno}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
}
\examples{
# Creation of a genotypic matrix G with 1000 loci for 100 individuals.
# The G matrix is composed of one individual per line and one locus per column.
G = matrix(sample(c(0,1,2), replace=TRUE, size=1000*100), ncol=1000, nrow=100)

# Write G in a file called "tuto.geno".
# Create file:	"tuto.geno".
write.geno(G, "tuto.geno")

# Read the file "tuto.geno".
G = read.geno("tuto.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
