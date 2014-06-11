\name{LFMM}
\alias{LFMM}
\alias{inflationFactor}
\alias{zscores}
\alias{pvalues}
\alias{mlog10pvalues}
\alias{save.lfmmProject}
\alias{load.lfmmProject}
\alias{remove.lfmmProject}
\alias{cFDR}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Fitting Latent Factor Mixed Models}
\description{
\code{\link{LFMM}} is used to fit Latent Factor Mixed Models. The goal of \code{LFMM} 
is to identify genetic polymorphisms that exhibit high correlation with some environmental 
gradient or with the variables used as proxies for ecological pressures.
}
\usage{
LFMM (        input_file, variable_file, K, d, 
        all = FALSE, missing_data = FALSE, 
        num_CPU = 1, num_iterations = 1000, num_burnin = 100, 
        seed = -1, repetitions = 1, epsilon_noise = 1e-3, 
        epsilon_b = 1000, random_init = TRUE)

}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
A character string containing a path to the input file,
a genotypic matrix in the \code{\link{lfmm}} format.
}
\item{variable_file}{
A character string containing a path to the environmental file,
an environmental data matrix in the \code{\link{env}} format.
}
\item{K}{
        an integer corresponding to the number of latent factors. 
}
\item{d}{
        an integer corresponding to the fit of \code{LFMM} model with the \code{d}-th variable only from \code{variable_file}. By default (if NULL and all is FALSE), fit \code{LFMM} with each variable from \code{variable_file} sequentially and independently.
}
\item{all}{
        a boolean option. If true, fit \code{LFMM} with all variables from \code{variable_file} at the same time. This option is not compatible with the \code{d} option. 
}
\item{missing_data}{
        a boolean option. If true, the \code{input_file} contains missing genotypes.
}
#ifndef windows
\item{num_CPU}{
	A number of CPUs to run the parallel version of the algorithm.
	By default, the number of CPUs is 1.
}
#endif
#ifdef windows
\item{num_CPU}{
        the windows version is not parallelized. By consequence, num_CPU is always set to 1.
}
#endif
\item{num_iterations}{
        the total number of iterations in the Gibbs Sampling algorithm.
}
\item{num_burnin}{
        the burnin number of iterations in the Gibbs Sampling algorithm.
}
\item{seed}{
        a seed to initialize the random number generator. By default, the seed is randomly chosen.
}
\item{repetitions}{
        the number of repetitions of each run.
}
\item{epsilon_noise}{
         prior on the different variances.
}
\item{epsilon_b}{
        prior on the variance of the correlation coefficients.
}
\item{random_init}{
        a boolean option. If true, the Gibbs Sampler is initiliazed randomly. Otherwise, it is initialized with zeros.
}
}
\value{
\code{LFMM} returns an object of class \code{lfmmProject}.

The following methods can be applied to the object of class \code{lfmmProject}:
\item{plot}{
        plot the mean inflation factor in function of K for each variable. 
}
\item{show}{
        display information about the analyses.
}
\item{summary}{
        summarize the analyses.
}
\item{zscores}{\code{signature(object = "lfmmProject", run = "integer", 
        K = "integer", d = "integer", all = "logical")}}{
        return the \code{LFMM} output vector of zscores for K
        latent factors with variable d and the all option ... 
}
\item{pvalues}{\code{signature(object = "lfmmProject", run = "integer", 
        K = "integer", d = "integer", all = "logical")}}{
        return the \code{LFMM} output vector of pvalues for K
        latent factors with variable d and the all option ... 
}
\item{mlog10pvalues}{\code{signature(object = "lfmmProject", run = "integer", 
        K = "integer", d = "integer", all = "logical")}}{
        return the \code{LFMM} output vector of -log10(pvalues) for K
        latent factors with variable d and the all option ... 
}
\item{inflationFactor}{\code{signature(object = "lfmmProjec", run = "integer", 
        K = "integer", d = "integer", all = "logical")}}{
        return the inflation factors for all runs with K
        latent factors for the variable d and the all option.
}
\item{cFDR}{\code{signature(object = "lfmmProjec", percentage = "numeric", 
        K = "integer", d = "integer", all = "logical", cutoff = "integer")}}{
        return a list of indices ... TODO

}
\item{save.lfmmProject}{\code{signature(object = "lfmmProject", file = "character")}}{
        save a lfmmProject object into a file.
}
\item{load.lfmmProject}{\code{signature(file = "character")}}{
        load the file containing an lfmmProject objet and return the lfmmProject object.
}
\item{remove.lfmmProject}{\code{signature(file = "character")}}{
        Erase a \code{lfmmProject} object. Caution: All the files associated with the
        object will be removed.
}
}
\author{
        Eric Frichot
}
\seealso{
\code{\link{lfmm}}
\code{\link{pca}}
\code{\link{sNMF}}
}
\references{
Frichot E, Schoville SD, Bouchard G, Francois O. (2013). \emph{Testing for associations between loci and environmental gradients using latent factor mixed models}. Molecular biology and evolution, 30(7), 1687-1699.
}
\examples{
# Creation of the genotype file, example_lfmm.lfmm
#          and the variable file, example_env.env.
# It contains 10000 SNPs for 50 individuals and 2 variables.
data("tuto")
write.lfmm(R, "genotypes.lfmm")
write.env(C, "variables.env")

################
# runs of LFMM #
################

# main options, K: (the number of latent factors), 
#                d: run for the d-th variable
#                num_CPU: the number of CPUs.

# Runs with K = 1 and K = 2 and 3 repetitions.
project = LFMM("tuto.lfmm", "tuto.env", K = 1:2, d = 1, repetitions = 3)

# plot the mean inflation factor of all runs of the project
plot(project, lwd = 5, col = "red", pch=1)

# return a list controlled for the False Discovery Rate for K = 2 and d = 1
res = cFDR(project, K = 2, d = 1)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
