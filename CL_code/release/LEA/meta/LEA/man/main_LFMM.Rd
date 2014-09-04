\name{LFMM}
\alias{LFMM}
\alias{load.lfmmProject}
\alias{remove.lfmmProject}
\alias{load.lfmmProject,character-method}
\alias{remove.lfmmProject,character-method}
\alias{show,lfmmProject-method}
\alias{show,lfmmClass-method}
\alias{summary,lfmmProject-method}
\alias{z.scores,lfmmProject-method}
\alias{p.values,lfmmProject-method}
\alias{mlog10p.values,lfmmProject-method}
\alias{plot,lfmmProject-method}

%- Also NEED an '\alias' for EACH other topic documented here.
\title{Fitting Latent Factor Mixed Models}
\description{
\code{\link{LFMM}} is used to fit Latent Factor Mixed Models. The goal of \code{LFMM} 
is to identify genetic polymorphisms that exhibit high correlation with some environmental 
gradient or with the variables used as proxies for ecological pressures.
}
\usage{
LFMM(input.file, environment.file, K, 
        project = "continue", 
        d = 0, all = FALSE, 
        missing.data = FALSE, CPU = 1, 
        iterations = 1000, burnin = 500, 
        seed = -1, repetitions = 1, 
        epsilon.noise = 1e-3, epsilon.b = 1000, 
        random.init = TRUE)

}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input.file}{
A character string containing a path to the input file,
a genotypic matrix in the \code{\link{lfmm}} format.
}
\item{environment.file}{
A character string containing a path to the environmental file,
an environmental data matrix in the \code{\link{env}} format.
}
\item{K}{
        An integer corresponding to the number of latent factors. 
}
\item{project}{
        A character string among "continue", "new", and "force". If "continue",
        the results are stored in the current project. If "new", the current project
        is removed and a new one is created to store the result. If "force", the results
        are stored in the current project even if the input file has been modified since
        the creation of the project.
}
\item{d}{
        An integer corresponding to the fit of \code{LFMM} model with the \code{d}-th variable only from \code{environment.file}. By default (if NULL and all is FALSE), fit \code{LFMM} with each variable from \code{environment.file} sequentially and independently.
}
\item{all}{
        A boolean option. If true, fit \code{LFMM} with all variables from \code{environment.file} at the same time. This option is not compatible with the \code{d} option. 
}
\item{missing.data}{
        A boolean option. If true, the \code{input.file} contains missing genotypes.
}
#ifndef windows
\item{CPU}{
	A number of CPUs to run the parallel version of the algorithm.
	By default, the number of CPUs is 1.
}
#endif
#ifdef windows
\item{CPU}{
        The windows version is not parallelized. By consequence, CPU is always set to 1.
}
#endif
\item{iterations}{
        The total number of iterations in the Gibbs Sampling algorithm.
}
\item{burnin}{
        The burnin number of iterations in the Gibbs Sampling algorithm.
}
\item{seed}{
        A seed to initialize the random number generator. By default, the seed is randomly chosen.
}
\item{repetitions}{
        The number of repetitions of each run.
}
\item{epsilon.noise}{
        Prior on the different variances.
}
\item{epsilon.b}{
        Prior on the variance of the correlation coefficients.
}
\item{random.init}{
        A boolean option. If true, the Gibbs Sampler is initiliazed randomly. Otherwise, it is initialized with zeros.
}
}
\value{
\code{LFMM} returns an object of class \code{lfmmProject}.

The following methods can be applied to the object of class \code{lfmmProject}:
\item{plot}{
        Plot the mean inflation factor in function of K for each variable. 
}
\item{show}{
        Display information about the analyses.
}
\item{summary}{
        Summarize the analyses.
}
\item{\code{\link{z.scores}}}{
        Return the \code{LFMM} output vector of zscores for the chosen runs with K
        latent factors, the d-th variable and the all option.
}
\item{\code{\link{p.values}}}{
        Return the \code{LFMM} output vector of p-values for the chosen runs with K
        latent factors, the d-th variable and the all option.
}
\item{\code{\link{mlog10p.values}}}{
        Return the \code{LFMM} output vector of -log10(p-values) for the chosen runs with K
        latent factors, the d-th variable and the all option.
}
%\item{inflationFactor}{\code{signature(object = "lfmmProjec", run = "integer", 
%        K = "integer", d = "integer", all = "logical")}}{
%        return the inflation factors for all runs with K
%        latent factors for the variable d and the all option.
%}
%\item{cFDR}{\code{signature(object = "lfmmProjec", percentage = "numeric", 
%        K = "integer", d = "integer", all = "logical", cutoff = "integer")}}{
%        return a list of indices ... TODO
%
%}
%\item{save.lfmmProject}{\code{signature(object = "lfmmProject", file = "character")}}{
%        save a lfmmProject object into a file.
%}
\item{load.lfmmProject (file = "character") }{
        Load the file containing an lfmmProject objet and return the lfmmProject object.
}
\item{remove.lfmmProject (file = "character")}{
        Erase a \code{lfmmProject} object. Caution: All the files associated with the
        object will be removed.
}
}
\author{
        Eric Frichot
}
\seealso{
\code{\link{lfmm}}
\code{\link{z.scores}}
\code{\link{p.values}}
\code{\link{mlog10p.values}}
\code{\link{pca}}
\code{\link{sNMF}}
\link{tutorial}
}
\references{
Frichot E, Schoville SD, Bouchard G, Francois O. (2013). \emph{Testing for associations between loci and environmental gradients using latent factor mixed models}. Molecular biology and evolution, 30(7), 1687-1699.
}
\examples{
### Example of analyses using LFMM ###

data("tutorial")
# creation of the genotype file, genotypes.lfmm.
# It contains 5000 SNPs for 165 individuals.
write.lfmm(R, "genotypes.lfmm")
# creation of the environment file, gradient.env.
# It contains 1 environmental variable for 165 individuals.
write.env(C, "gradients.env")

################
# runs of LFMM #
################

# main options, K: (the number of ancestral populations), 
#               entropy: calculate the cross-entropy criterion, 
#               CPU: the number of CPUs.

# Runs with K between 1 and 5 with cross-entropy and 2 repetitions.
project = LFMM("genotypes.lfmm", "gradients.env", K=6:10, repetitions = 10)

# get the zscores of each run for K = 5
zs = z.scores(project, K = 5)

# Combine the z-scores using the Stouffer method
zs = apply(zs, MARGIN = 1, sum)/sqrt(10)

lambda = median(zs^2)/.456

cp.values = pchisq(zs^2/lambda, df = 1, lower = FALSE)

L = length(cp.values)
q = 0.1
w = which(sort(cp.values) < q * (1:L) / L)
candidates = order(cp.values)[w]

true.FDR = length(which(candidates <= 4500))/length(candidates)
true.positive = length(which(candidates > 4500))/500
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
# Advanced LFMM run options #
#############################

# Q.input.file: init a run with a given ancestry coefficient matrix Q. 
# Here, it is initialized with the Q matrix from the first run with K=3
project = LFMM("genotypes.geno", K = 3, Q.input.file = "./genotypes.snmf/K3/run1/genotypes_r1.3.Q")

# I: init the Q matrix of a run from a smaller run with 500 randomly chosen SNPs. 
project = LFMM("genotypes.geno", K = 3, I = 500)

# CPU: run LFMM with 2 CPUs. 
project = LFMM("genotypes.geno", K = 3, CPU=2)

# percentage: run LFMM and calculate the cross-entropy criterion with 10% of masked
# genotypes, instead of 5% of masked genotypes. 
project = LFMM("genotypes.geno", K = 3, entropy= TRUE, percentage = 0.1)

# seed: choose the seed to init the randomization.
project = LFMM("genotypes.geno", K = 3, seed=42)

# alpha: choose the regularization parameter.
project = LFMM("genotypes.geno", K = 3, alpha = 100)

# tolerance: choose the tolerance parameter.
project = LFMM("genotypes.geno", K = 3, tolerance = 0.00001)

##########################
# Manage an LFMM project #
##########################

# All the runs of LFMM for a given file are 
# automatically saved into a snmf project directory and a file.
# The name of the snmfProject file is the same name as 
# the name of the input file with a .snmfProject extension ("genotypes.snmfProject").
# The name of the snmfProject file is the same name as
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
\keyword{LFMM}
\keyword{tutorial}
