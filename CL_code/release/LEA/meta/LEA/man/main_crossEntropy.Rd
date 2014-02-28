\name{crossEntropy}
\alias{crossEntropy}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{compute the cross-entropy criterion}
\description{
The cross-entropy is a technique based on the prediction of masked genotypes to evaluate the error of ancestry estimation. The criterion will help to choose the best number of ancestral population (K) and the best run among a set of runs  in \code{\link{sNMF}}. A smaller value of cross-entropy means a better run in terms of prediction capacity. The cross-entropy which is value useful to compare runs is the cross-entropy of masked data. the cross-entropy of all the genotypes is systematically lower or equal to the cross-entropy value of the masked genotypes.
}
\usage{
crossEntropy (input_file, K, masked_file, file.Q, file.G, ploidy = 2)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the input file without masked genotypes (in \code{\link{geno}} format).
}
\item{K}{
	the number of ancestral populations.
}
\item{masked_file}{
	the path for the input file with masked genotypes (probably generated with \code{\link{createDataSet}}).
 	By default, the name of the masked data file is the name of the input file with \code{_I.geno} extension (\code{input_file_I.geno}).
}
\item{file.Q}{
	the path for the input file with the ancestry coefficients. 
	By default, the name of this file is the name of the input file with \code{K.Q} extension (\code{input_file.K.Q}).
}
\item{file.G}{
	the path for the input file with the ancestral genotype frequencies. 
	By default, the name of this file is the name of the input file with \code{K.G} extension (\code{input_file.K.G}).
}
\item{ploidy}{
	1 if haploid, 2 if diploid, n if n-ploid.
}
}
\value{
\item{masked_ce}{
	the value of the cross-entropy criterion of the masked genotypes.
}
\item{all_ce}{
	the value of the cross-entropy criterion of all the genotypes.
}
}
\author{
	Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{pca}}
\code{\link{LFMM}}
\code{\link{createDataSet}}
\code{\link{sNMF}}
}
\references{
Frichot E, Mathieu F, Trouillon T, Bouchard G, Francois O. (2014). \emph{Fast and Efficient Estimation of Individual Ancestry Coefficients} Genetics, genetics.113.160572.
}
\examples{
# creation of tuto.geno
data("tuto")
#write.geno(R, "tuto.geno")

# creation of the masked data file
#output = createDataSet("tuto.geno")

# runs of sNMF and crossEntropy
#ce = NULL
#for (K in 1:5) {
#	sNMF(output, K) 
#	res = crossEntropy("tuto.geno",K)
#	ce = c(ce, res$masked_ce)	
#}

# plot of the cross-entropy
#plot(1:5, ce, ylab="Cross-entropy", xlab="number of clusters", type="l", col="blue", lwd=8)
}
\keyword{sNMF}
