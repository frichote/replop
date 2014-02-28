\name{read.geno}
\alias{read.geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{read a file in the \code{\link{geno}} format}
\description{
read a file in the \code{\link{geno}} format.
}
\usage{
read.geno(input_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the input file (in \code{geno} format).
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
# creation of example.geno
data("example_geno")
write.table(example_geno,"example.geno",col.names = FALSE, row.names = FALSE, quote = FALSE)

# read of the geno file
R = read.geno("example.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
