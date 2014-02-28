\name{sNMF}
\alias{sNMF}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Fitting the admixture coefficients}
\description{
\code{\link{sNMF}} is used to fit the admixture coefficients using the sparse Non-Negative Matrix Factorization.
}
\usage{
sNMF (input_file, K, 
      alpha = 10, tol = 0.0001, entropy = FALSE, percentage, I,
      iterations = 200, ploidy = 2, seed = -1, num_CPU = 1,
      input_file.Q,
      output_file.Q, load.Q = TRUE,
      output_file.G, load.G = FALSE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the genotype input file (in \code{\link{geno}} format).
}
\item{K}{
	the number of ancestral populations.
}
\item{alpha}{
	the regularization parameter. The results can depend on the value of this parameter, especially for small data sets. Please, check the references for more informations.
}
\item{tol}{
	the tolerance error.
}
\item{entropy}{
	a boolean option. If true, the cross-entropy criterion is calculated (see \code{\link{createDataSet}} and \code{\link{crossEntropy}}).
}
\item{percentage}{
	the percentage of masked genotypes to calculate the cross-entropy criterion. This option is useful only if \code{entropy} = TRUE (see \code{\link{crossEntropy}}).
}
\item{I}{
	the number of SNPs to initialize the algorithm. It starts the algorithm with a run of sNMF using a subset of nb_SNPs random SNPs. If this option is set with nb\_SNPs, the number of randomly chosen SNPs is the minimum between 10000 and 10 \% of all SNPs. This option can considerably speeds up sNMF estimation for very large data sets.
}
\item{iterations}{
	the maximum number of iterations in algorithm. The algorithm should not go until the maximum number of iterations. The stopping criterion should depend on the tolerance error only.
}
\item{ploidy}{
	1 if haploid, 2 if diploid, n if n-ploid.
}
\item{seed}{
	the seed to initialize the randomization. By default, the seed is randomly chosen.
}
#ifndef windows
\item{num_CPU}{
	the number of CPUs that you choose to use if you run the algorithm in parrallel. Be careful,
the number of CPUs has to be lower or equal than the number of physical processes available on your
computer. By default, the number of CPUs is 1.
}
#endif
#ifdef windows
\item{num_CPU}{
	the windows version is not parallelized. By consequence, num_CPU is always set to 1.
}
#endif
\item{input_file.Q}{
	the path for an initialization file for Q, the individual admixture coefficients.
}
\item{output_file.Q}{
	the path for the output file with the ancestry coefficients. By default, the name of the output file is the name of the input file with .K.Q extension.
}
\item{load.Q}{
	the boolean option. If true, load the ancestry coefficients in R. Else, return the path for the output file with the ancestry coefficients. 
}
\item{output_file.G}{
	the path for the output file with the ancestral genotype frequencies. By default, the name of the output file is the name of the input file with .K.G extension.
}
\item{load.G}{
	a boolean option. If true, load the ancestral genotype frequencies in R. Else, return the path for the output file with the ancestral genotype frequencies. 
}
}
\value{
\item{Q}{
	if load.Q is true, the matrix of ancestry coefficients. Otherwise, the path for the output file with the ancestry coefficients.
}
\item{G}{
	if load.G is true, the matrix of ancestral genotype frequencies. Otherwise, the path for the output file with the ancestral genotype frequencies.
}
\item{masked_ce}{
	if the percentage of masked data is not zero, the value of the cross-entropy criterion of the masked genotypes.
}
\item{all_ce}{
	if the percentage of masked data is not zero, the value of the cross-entropy criterion of the all genotypes.
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
\code{\link{crossEntropy}}
}
\references{
Frichot E, Mathieu F, Trouillon T, Bouchard G, Francois O. (2014). \emph{Fast and Efficient Estimation of Indidividual Ancestry Coefficients}. Genetics, 113.160572.
}
\examples{
# creation of the example file
#data(tuto)
#write.geno(R, "tuto.geno")

# run of sNMF
#res = sNMF("tuto.geno", 3)

# display
#barplot(t(res$Q),col=c("red", "green", "blue"))
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
