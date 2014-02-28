\name{ancestrymap}
\alias{ancestrymap}
\alias{example_ancestrymap}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{\code{ancestrymap} format description}
\description{
description of the \code{ancestrymap} format. 
}
\details{
The \code{ancestrymap} format has one row for each genotype. Each row has 3 columns: the 1st column is the SNP name, the 2nd column is the sample ID, the 3rd column is th number of alleles. It is assumed that the genotypes for a given SNP name are written in consecutive lines. It is also assumed that the genotypes for a set of individuals are given in the same order as lines. The number of alleles can be the number of reference alleles or the number of derived alleles as long as it is the same choice for an entire SNP. It is assumed that the missing genotypes are encoded with the value 9.

Here is an example with 3 individuals and 4 SNPs:
\preformatted{
rs0000	SAMPLE0	1
rs0000	SAMPLE1	1
rs0000	SAMPLE2	2
rs1111	SAMPLE0	0
rs1111	SAMPLE1	1
rs1111	SAMPLE2	0
rs2222	SAMPLE0	0
rs2222	SAMPLE1	9
rs2222	SAMPLE2	1
rs3333	SAMPLE0	1
rs3333	SAMPLE1	2
rs3333	SAMPLE2	1
}
}

\author{
    Eric Frichot
}
\seealso{
\code{\link{ancestrymap2lfmm}}
\code{\link{ancestrymap2geno}}
\code{\link{geno}}
\code{\link{lfmm}}
\code{\link{ped}}
\code{\link{vcf}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
