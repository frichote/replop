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
	A character string containing a path to the input file,
	a genotypic matrix in the \code{\link{geno}} format.
}
\item{output_file}{
	A character string containing a path to the output file,
	a genotypic matrix in the \code{\link{geno}} format. 
	The output file is the input file with masked genotypes. 
	By default, the name of the output file is the sane name as 
	the input file with a _I.geno extension.
}
\item{ploidy}{
	1 if haploid, 2 if diploid, n if n-ploid.
}
\item{seed}{
	A seed to initialize the random number generator. 
	By default, the seed is randomly chosen.
}
\item{percentage}{
	A numeric value between 0 and 1 containing the percentage of masked genotypes.  
}
}
\value{
\item{output_file}{
	A character string containing a path to the output file,
	a genotypic matrix in the \code{\link{geno}} format. 
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
# A file containing 10000 SNPs for 50 individuals.
# Individuals are clustered in 3 non-admixed populations.
data("tuto")
write.geno(R, "tuto.geno")

# creation of the masked data file
output = createDataSet("tuto.geno")
}
% R documentation directory.
\keyword{sNMF}
