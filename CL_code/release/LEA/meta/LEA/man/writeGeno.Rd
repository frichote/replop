\name{write.geno}
\alias{write.geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{geno}} format}
\description{
Write a file in the \code{\link{geno}} format.
}
\usage{
write.geno(R, output.file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the genotypes with one line for each individual and one column for each SNP. 
	The missing genotypes have to be encoded with the value 9.
}
\item{output.file}{
A character string containing a path to the output file,
a genotypic matrix in the \code{geno} format.
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{read.geno}}
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
# with 1000 SNPs for 165 individuals.
data("tutorial")

# Write R in a file called "genotypes.geno".
# Create file:	"genotypes.geno".
write.geno(R, "genotypes.geno")

# Read the file "genotypes.geno".
R = read.geno("genotypes.geno")
}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{read/write}
