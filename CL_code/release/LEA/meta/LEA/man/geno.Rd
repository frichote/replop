\name{geno}
\alias{geno}
\alias{example_geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Input file for \code{\link{sNMF}}}
\description{
description of the \code{geno} format.
}
\details{
The \code{geno} format has one row for each SNP.
Each row contains 1 character per individual:
  	0 means zero copy of the reference allele.
  	1 means one copy of the reference allele.
  	2 means two copies of the reference allele.
  	9 means missing data.

Here is an example with 3 individuals and 4 SNPs:
\preformatted{
112
010
091
121
}
}

\author{
    Eric Frichot
}
\seealso{
\code{\link{geno2lfmm}}
\code{\link{lfmm2geno}}
\code{\link{ancestrymap2geno}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
\code{\link{sNMF}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
