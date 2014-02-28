\name{lfmm}
\alias{lfmm}
\alias{example_lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Input file for \code{\link{LFMM}}}
\description{
description of the \code{lfmm} format.
}
\details{
The \code{lfmm} format has one row for each individual. Each row contains 
one value per SNP (separated by spaces or tabulations): the number of alleles.
The number of alleles can be the number of reference alleles or the number 
of derived alleles as long as it is the same choice for an entire SNP. The missing
genotypes are encoded with the value -9 or 9.

Here is an example with 3 individuals and 4 SNPs:
\preformatted{
1 0 0 1
1 1 9 2
2 0 1 1
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{LFMM}}
\code{\link{geno2lfmm}}
\code{\link{lfmm2geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ped2lfmm}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{LFMM}
