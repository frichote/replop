\name{sNMF}
\alias{sNMF}
\alias{Q}
\alias{crossEntropy}
\alias{load.snmfProject}
\alias{save.snmfProject}
\alias{remove.snmfProject}
\alias{G}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Estimates individual ancestry coefficients and ancestral allele frequencies.}
\description{
\code{\link{sNMF}} estimates admixture coefficients using sparse Non-Negative 
	Matrix Factorization algorithms, and provide STRUCTURE-like outputs.
}
\usage{
sNMF (input.file, K, 
      alpha = 10, tolerance = 0.00001, entropy = FALSE, percentage = 0.05, I,
      iterations = 200, ploidy = 2, seed = -1, CPU = 1,
      Q.input.file, repetitions = 1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input.file}{
	A character string containing a the path to the input file, a genotypic 
	matrix in the \code{\link{geno}} format.
}
\item{K}{
	An integer vector corresponding to the number of ancestral populations for which
	the snmf algorithm estimates have to be calculated.
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
	the number of SNPs to initialize the algorithm. It starts the algorithm with a run of sNMF using a subset of nb.SNPs random SNPs. If this option is set with nb.SNPs, the number of randomly chosen SNPs is the minimum between 10000 and 10 \% of all SNPs. This option can considerably speeds up sNMF estimation for very large data sets.
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
\item{CPU}{
	A number of CPUs to run the parallel version of the 
	algorithm. By default, the number of CPUs is 1.
}
#endif
#ifdef windows
\item{CPU}{
	The windows version is not parallelized. By consequence, 
	CPU is always 1.
}
#endif
\item{Q.input.file}{
	A character string containing a path to an initialization file for Q, 
	the individual admixture coefficient matrix.
}
\item{repetitions}{
	an integer corresponding with the number of repetitions for each value of \code{K}.
}
}
\value{
\code{sNMF} returns an object of class \code{snmfProject}.

The following methods can be applied to the object of class {snmfProject} returned by \code{sNMF}:
\item{save.snmfProject}{\code{signature(object = "snmfProject", file = "character")}}{
        save a snmfProject object into a file.
}
\item{load.snmfProject}{\code{signature(file = "character")}}{
        load the file containing an snmfProject objet and return the snmfProject object.
}
\item{remove.snmfProject}{\code{signature(file = "character")}}{
        Erase a \code{snmfProject} object. Caution: All the files associated with the
        object will be removed.
}
\item{}{
}
\it
}
\author{
	Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{pca}}
\code{\link{LFMM}}
\code{\link{createDataSet}}
\code{\link{crossEntropyEstimation}}
}
\references{
Frichot E, Mathieu F, Trouillon T, Bouchard G, Francois O. (2014). \emph{Fast and Efficient Estimation of Individual Ancestry Coefficients}. Genetics, 194(4): 973--983.
}
\examples{
### Example of analyses using sNMF ###

# creation of the genotype file, tuto.geno.
# It contains 10000 SNPs for 50 individuals.
# It is composed of three non-admixed populations
# with respectively 20, 10, and 20 indiviuals. 
data("tuto")
write.geno(R, "tuto.geno")

################
# runs of sNMF #
################

# main options, K: (the number of ancestral populations), 
#		alpha: the regularization parameter, 
#		entropy: calculate the cross-entropy criterion, 
#		tolerance: the stopping criterion. 
#		CPU: the number of CPUs.

# Runs with K between 1 and 5 with cross-entropy and 2 repetitions.
project = sNMF("tuto.geno", K=1:5, entropy = TRUE, repetitions = 2)

# plot cross-entropy criterion of all runs of the project
plot(project, lwd = 5, col = "red", pch=1)

# get the cross-entropy of each run for K = 3
ce = crossEntropy(project, K = 3)

# select the run with the lowest cross-entropy
best = which.min(ce)

# plot the best run for K = 3 (ancestry coefficients).
barplot(t(Q(project, K = 3, run = best)), col = c("red", "blue", "yellow"))

##########################
# Manage an snmf project #
##########################

# All the runs of sNMF for a given file are 
# automatically saved into a snmf project. 
# The name of the snmfProject file is the same name as 
# the name of the input file with a .snmfProject extension ("tuto.snmfProject").
# There is only one snmf Project for each input file including all the runs.

# A snmfProject can be load in a different session.
project = load.snmfProject("tuto.snmfProject") 

# A snmfProject can be erased.
# Caution: All the files associated with the project will be removed.
project = remove.snmfProject("tuto.snmfProject")

###################
# Post-treatments #
###################

# show the project
show(project)

# plot cross-entropy criterion of all runs of the project 
plot(project, lwd = 5, col = "red", pch=1)

# summary of the project
summary(project)

# get the cross-entropy for all runs for K = 3 
ce = crossEntropy(project, K = 3)

# get the cross-entropy for the 2nd run for K = 3
ce = crossEntropy(project, K = 2, run = 1)

# get the ancestral genotype frequency matrix, G, for the 2nd run for K = 3. 
res = G(project, K = 3, run = 2)

#############################
# Advanced sNMF run options #
#############################

#Add of one run for K=1 and K=2 with cross-entropy to project
project = sNMF("tuto.geno",K = c(1,2), entropy = TRUE)
summary(project)

# Q.input.file: init a run with a given ancestry coefficient matrix Q. 
# Here, it is initialized with the Q matrix from the first run with K=3
project = sNMF("tuto.geno", K = 3, Q.input.file = "tuto_r1.3.Q")

# I: init the Q matrix of a run from a smaller run with 10% randomly chosen SNPs. 
project = sNMF("tuto.geno", 3, I)
# or 5% randomly chosen SNPs.
project = sNMF("tuto.geno", 3, I = 0.05)

# CPU: run sNMF with 2 CPUs. 
project = sNMF("tuto.geno", 3, CPU=2, project)

# percentage: run sNMF and calculate the cross-entropy criterion with 10% of masked
# genotypes, instead of 5% of masked genotypes. 
project = sNMF("tuto.geno", 3, entropy= TRUE, percentage = 0.1)

# seed: choose the seed to init the randomization.
project = sNMF("tuto.geno", 3, seed=42)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
