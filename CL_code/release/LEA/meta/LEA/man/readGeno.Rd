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
# Creation of a file called "genotypes.geno" in the working directory,
# with 5000 SNPs for 165 individuals.
("tutorial")
write.geno(R, "genotypes.geno")

# Write G in a file called "genotypes.geno".
# Create file:	"genotypes.geno".
write.geno(G, "genotypes.geno")

# Read the file "genotypes.geno".
G = read.geno("genotypes.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{read/write}
