\name{sNMF}
\alias{sNMF}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Estimates individual ancestry coefficients and ancestral allele frequencies.}
\description{
\code{\link{sNMF}} estimates admixture coefficients using sparse Non-Negative 
	Matrix Factorization algorithms, and provide STRUCTURE-like outputs.
}
\usage{
sNMF (input_file, K, project, 
      alpha = 10, tolerance = 0.00001, entropy = FALSE, percentage = 0.05, I,
      iterations = 200, ploidy = 2, seed = -1, num_CPU = 1,
      Q_input_file, Q_output_file, G_output_file, repetitions = 1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	A character string containing a the path to the input file, a genotypic 
	matrix in the \code{\link{geno}} format.
}
\item{K}{
	An integer vector corresponding to the number of ancestral populations for which
	the snmf algorithm estimates have to be calculated.
}
\item{project}{
	current project of class \code{\link{snmfProject}}.
}
\item{alpha}{
	A numeric value corresponding to the snmf regularization parameter. 
	The results can depend on the value of this parameter, especially for 
	small data sets. 
}
\item{tolerance}{
	A numeric value for the tolerance error.
}
\item{entropy}{
	A boolean value. If true, the cross-entropy criterion is calculated 
	(see \code{\link{createDataSet}} and \code{\link{crossEntropy}}).
}
\item{percentage}{
	A numeric value between 0 and 1 containing the percentage of 
	masked genotypes when computing the cross-entropy 
	criterion. This option applies only if \code{entropy == TRUE} 
	(see \code{\link{crossEntropy}}).
}
\item{I}{
	the number of SNPs to initialize the algorithm. It starts the algorithm with a run of sNMF using a subset of nb_SNPs random SNPs. If this option is set with nb\_SNPs, the number of randomly chosen SNPs is the minimum between 10000 and 10 \% of all SNPs. This option can considerably speeds up sNMF estimation for very large data sets.
}
\item{iterations}{
	An integer for the maximum number of iterations in algorithm. 
}
\item{ploidy}{
	1 if haploid, 2 if diploid, n if n-ploid.
}
\item{seed}{
	A seed to initialize the random number generator. 
	By default, the seed is randomly chosen.
}
#ifndef windows
\item{num_CPU}{
	A number of CPUs to run the parallel version of the 
	algorithm. By default, the number of CPUs is 1.
}
#endif
#ifdef windows
\item{num_CPU}{
	The windows version is not parallelized. By consequence, 
	num_CPU is always 1.
}
#endif
\item{Q_input_file}{
	A character string containing a path to an initialization file for Q, 
	the individual admixture coefficient matrix.
}
\item{Q_output_file}{
	A character string containing a path to the output ancestry coefficient 
	matrix Q . By default, the name of the output file is the same name as the 
	input file with a .K.Q extension.
}
\item{G_output_file}{
	A character string containing a path to the output ancestral genotype 
	frequency matrix G. By default, the name of the output file is the same name 
	as the input file with a .K.G extension.
}
\item{repetitions}{
	an integer corresponding with the number of repetitions for each value of \code{K}.
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
data(tuto)
write.geno(R, "tuto.geno")

# run of sNMF
project = sNMF("tuto.geno", 3)
project = sNMF("tuto.geno",1, entropy = TRUE, project)
project = sNMF("tuto.geno",2, entropy = TRUE, project)
project = sNMF("tuto.geno",3, entropy = TRUE, project)

# Project
plot(res, lwd = 5, col = "red", pch=1)
summary(res)
p = getRuns.snmfProject(res,c(2,1))
addRun.snmfProject(res, p[[1]])
getCrossEntropy(res, 3)
show(res)
write.snmfProject(res, "tmp.snmfProject")
res = read.snmfProject("tmp.snmfProject")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
