\name{createDataSet}
\alias{createDataSet}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{create a data set with masked data}
\description{

\code{\link{createDataSet}} creates a data set with a given percentage of masked data from the original data set. It is used to calculate the \code{\link{crossEntropy}} criterion.
}
\usage{
createDataSet (input_file, output_file, ploidy = 2, seed = -1, percentage = 0.05)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the genotype input file (in \code{\link{geno}} format).
}
\item{output_file}{
	the path for the output file (in \code{\link{geno}} format). The output file is the input file with some masked genotypes. By default, the name of the output file is the name of the input file with extension _I.geno.
}
\item{ploidy}{
	1 if haploid, 2 if diploid, n if n-ploid.
}
\item{seed}{
	the seed to initialize the randomization. By default, the seed is randomly chosen.
}
\item{percentage}{
	the percentage of masked genotypes. 
}
}
\value{
\item{output_file}{
the path for the output file.
}
}
\author{
	Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{sNMF}}
\code{\link{crossEntropy}}
}
\examples{
# creation of tuto.geno
data("tuto")
#write.geno(R, "tuto.geno")

# creation of the masked data file
#output = createDataSet("tuto.geno")
}
% R documentation directory.
\keyword{sNMF}
