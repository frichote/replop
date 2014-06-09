\name{write.geno}
\alias{write.geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{geno}} format}
\description{
Write a file in the \code{\link{geno}} format.
}
\usage{
write.geno(R, output_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the genotypes with one line per individuals and one column per SNPs. The missing genotypes have to be encoded with the value 9.
}
\item{output_file}{
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
