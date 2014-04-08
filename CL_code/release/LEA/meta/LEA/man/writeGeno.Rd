\name{write.geno}
\alias{write.geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Write files in the \code{\link{geno}} format}
\description{
write a file in the \code{\link{geno}} format.
}
\usage{
write.geno(R, output_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{R}{
        A matrix containing the genotypes with one line per population and one column per allele frequency. The missing genotypes have to be encoded with the value 9.
}
\item{output_file}{
	the path for the output file (in \code{geno} format).
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
# creation of the example.geno file
data("example_geno")
write.table(example_geno,"example.geno",col.names = FALSE, row.names = FALSE, quote = FALSE)

# read of the geno file
R = read.geno("example.geno")

# wite of the geno file 
write.geno(R, "example2.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
