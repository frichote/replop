\name{sNMF}
\alias{sNMF}
\alias{plot,snmfProject-method}
\alias{cross.entropy,snmfProject-method}
\alias{load.snmfProject}
\alias{load.snmfProject,character-method}
\alias{remove.snmfProject}
\alias{remove.snmfProject,character-method}
\alias{show,snmfProject-method}
\alias{show,snmfClass-method}
\alias{summary,snmfProject-method}
\alias{Q,snmfProject-method}
\alias{G,snmfProject-method}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Estimates individual ancestry coefficients and ancestral allele frequencies.}
\description{
\code{\link{sNMF}} estimates admixture coefficients using sparse Non-Negative 
	Matrix Factorization algorithms, and provide STRUCTURE-like outputs.
}
\usage{
sNMF (input.file, K, 
      project = "continue",
      repetitions = 1, CPU = 1, 
      alpha = 10, tolerance = 0.00001, entropy = FALSE, percentage = 0.05,
      I, iterations = 200, ploidy = 2, seed = -1, Q.input.file)
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
\item{project}{
	A character string among "continue", "new", and "force". If "continue",
	the results are stored in the current project. If "new", the current project
	is removed and a new one is created to store the result. If "force", the results
	are stored in the current project even if the input file has been modified since
	the creation of the project.
}
\item{repetitions}{
	An integer corresponding with the number of repetitions for each value of \code{K}.
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
	(see \code{\link{create.dataset}} and \code{\link{cross.entropy.estimation}}).
}
\item{percentage}{
	A numeric value between 0 and 1 containing the percentage of 
	masked genotypes when computing the cross-entropy 
	criterion. This option applies only if \code{entropy == TRUE} 
	(see \code{\link{cross.entropy}}).
}
\item{I}{
	The number of SNPs to initialize the algorithm. It starts the algorithm with a run of sNMF using a subset of nb.SNPs random SNPs. If this option is set with nb.SNPs, the number of randomly chosen SNPs is the minimum between 10000 and 10 \% of all SNPs. This option can considerably speeds up sNMF estimation for very large data sets.
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
\item{Q.input.file}{
	A character string containing a path to an initialization file for Q, 
	the individual admixture coefficient matrix.
}
}
\value{
\code{sNMF} returns an object of class \code{snmfProject}.

The following methods can be applied to the object of class {snmfProject}:
\item{plot}{
        Plot the minimal cross-entropy in function of K.
}
\item{show}{
        Display information about the analyses.
}
\item{summary}{
        Summarize the analyses.
}
\item{\code{\link{Q}}}{
        Return the admixture coefficient matrix for the chosen run with K
	ancestral populations. 
}
\item{\code{\link{G}}}{
        Return the ancestral allele frequency matrix for the chosen run with K
	ancestral populations. 
}
\item{\code{\link{cross.entropy}}}{
        Return the cross-entropy criterion for the chosen runs with K
	ancestral populations. 
}
\item{load.snmfProject(file.snmfProject)}{
        Load the file containing an snmfProject objet and return the snmfProject object.
}
\item{remove.snmfProject(file.snmfProject)}{
        Erase a \code{snmfProject} object. Caution: All the files associated with the
        object will be removed.
}
}
\author{
	Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{pca}}
\code{\link{LFMM}}
\code{\link{tutorial}}
}
\references{
Frichot E, Mathieu F, Trouillon T, Bouchard G, Francois O. (2014). \emph{Fast and Efficient Estimation of Individual Ancestry Coefficients}. Genetics, 194(4): 973--983.
}
\examples{
### Example of analyses using sNMF ###

# creation of the genotype file, genotypes.geno.
# It contains 1000 SNPs for 165 individuals.
data("example")
write.geno(example.R, "genotypes.geno")

################
# runs of sNMF #
################

# main options, K: (the number of ancestral populations), 
#		entropy: calculate the cross-entropy criterion, 
#		CPU: the number of CPUs.

# Runs with K between 1 and 5 with cross-entropy and 2 repetitions.
project = sNMF("genotypes.geno", K=1:10, entropy = TRUE, repetitions = 2)

# plot cross-entropy criterion of all runs of the project
plot(project, lwd = 5, col = "red", pch=1)

# get the cross-entropy of each run for K = 7
ce = cross.entropy(project, K = 7)

# select the run with the lowest cross-entropy
best = which.min(ce)

# plot the best run for K = 7 (ancestry coefficients).
barplot(t(Q(project, K = 7, run = best)))

###################
# Post-treatments #
###################

# show the project
show(project)

# summary of the project
summary(project)

# get the cross-entropy for all runs for K = 3 
ce = cross.entropy(project, K = 3)

# get the cross-entropy for the 2nd run for K = 3
ce = cross.entropy(project, K = 3, run = 2)

# get the ancestral genotype frequency matrix, G, for the 2nd run for K = 3. 
res = G(project, K = 3, run = 2)

#############################
# Advanced sNMF run options #
#############################

# Q.input.file: init a run with a given ancestry coefficient matrix Q. 
# Here, it is initialized with the Q matrix from the first run with K=3
project = sNMF("genotypes.geno", K = 3, Q.input.file = "./genotypes.snmf/K3/run1/genotypes_r1.3.Q")

# I: init the Q matrix of a run from a smaller run with 500 randomly chosen SNPs. 
project = sNMF("genotypes.geno", K = 3, I = 500)

# CPU: run sNMF with 2 CPUs. 
project = sNMF("genotypes.geno", K = 3, CPU=2)

# percentage: run sNMF and calculate the cross-entropy criterion with 10% of masked
# genotypes, instead of 5% of masked genotypes. 
project = sNMF("genotypes.geno", K = 3, entropy= TRUE, percentage = 0.1)

# seed: choose the seed to init the randomization.
project = sNMF("genotypes.geno", K = 3, seed=42)

# alpha: choose the regularization parameter.
project = sNMF("genotypes.geno", K = 3, alpha = 100)

# tolerance: choose the tolerance parameter.
project = sNMF("genotypes.geno", K = 3, tolerance = 0.0001)

##########################
# Manage an sNMF project #
##########################

# All the runs of sNMF for a given file are 
# automatically saved into a snmf project directory and a file.
# The name of the snmfProject file is the same name as 
# the name of the input file with a .snmfProject extension ("genotypes.snmfProject").
# The name of the snmfProject directory is the same name as
# the name of the input file with a .snmf extension ("genotypes.snmf/")
# There is only one snmf Project for each input file including all the runs.

# An snmfProject can be load in a different session.
project = load.snmfProject("genotypes.snmfProject") 

# An snmfProject can be erased.
# Caution: All the files associated with the project will be removed.
remove.snmfProject("genotypes.snmfProject")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
\keyword{tutorial}
