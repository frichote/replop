\name{lfmm}
\alias{lfmm}
\alias{example_lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Input file for \code{\link{LFMM}}}
\description{
Description of the \code{lfmm} format.
The \code{lfmm} format can be used as an input format 
for genotypic matrices in the functions \code{\link{sNMF}},
\code{\link{LFMM}}, and \code{\link{pca}}. 
}
\details{
The \code{lfmm} format has one row for each individual. Each row contains one value 
at each loci (separated by spaces or tabulations) corresponding to the number of alleles. 
The number of alleles corresponds to the number of reference alleles or the number of 
derived alleles. Missing genotypes are encoded by the value -9 or 9. 

Here is an example of a genotypic matrix using the lfmm format with 3 individuals and 4 loci: 
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
\code{\link{read.lfmm}}
\code{\link{write.lfmm}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{LFMM}
