\name{LFMM}
\alias{LFMM}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Fitting Latent Factor Mixed Models}
\description{
\code{\link{LFMM}} is used to fit Latent Factor Mixed Models.
}
\usage{
LFMM (	input_file, variable_file, K, project, d, 
	all = FALSE, output_file, missing_data = FALSE, 
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
\item{project}{
        current project of class \code{\link{lfmmProject}}.
}
\item{d}{
	an integer corresponding to the fit \code{LFMM} with the \code{d}-th variable only from \code{variable_file}. By default (if NULL and all is FALSE), fit \code{LFMM} with each variable from \code{variable_file} sequentially and independently.
}
\item{all}{
	a boolean option. If true, fit \code{LFMM} with all variables from \code{variable_file} at the same time. This option is not compatible with \code{nd} option. 
}
\item{output_file}{
	the base of the path for the zscore output files (in \code{\link{zscore}} format). There is one output_file per environmental variable. By default, the base of the output file is the base of the name of the input file. Then it is completed with the number of the covariable (with a "a" for all and a "s" for sequentially), the number of latent factors and .zscore extension. For example, for the 3rd variable sequentially and 3 latent factors, the output file is by default input_file_s3.3.zscore.
}
\item{missing_data}{
	a boolean option. If true, the \code{input_file} contains missing genotypes.
}
#ifndef windows
\item{num_CPU}{
	the number of CPUs that you choose to use if you run the algorithm in parallel. Be careful,
the number of CPUs has to be lower or equal than the number of physical processes available on your
computer. By default, the number of CPUs is 1.
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
	the seed to initialize the randomization. By default, the seed is randomly chosen.
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
\item{zscore_files}{
	vector of zscore output files in (\code{\link{zscore}}. There is one file per environmental variable. They can be read using \code{\link{read.zscore}} function. 
}
\item{dic_files}{
	vector of statistics output files. There is one file per run. They can be read using \code{\link{read.dic}} function. 
}
}
\author{
	Eric Frichot
}
\seealso{
\code{\link{lfmm}}
\code{\link{pca}}
\code{\link{sNMF}}
\code{\link{read.zscore}}
\code{\link{read.dic}}
}
\references{
Frichot E, Schoville SD, Bouchard G, Francois O. (2013). \emph{Testing for associations between loci and environmental gradients using latent factor mixed models}. Molecular biology and evolution, 30(7), 1687-1699.
}
\examples{
# creation of an example
n = 10
L = 100
D = 2
R = matrix(sample(c(0,1,2), replace=TRUE, size=n*L), ncol=L)
X = matrix(runif(n*D), ncol=2)
write.lfmm(R, "example.lfmm")
write.env(X, "example.env")

# LFMM run
res = LFMM("example.lfmm", "example.env", K=1)
res = LFMM("example.lfmm", "example.env", K=1, res, all=TRUE)
res = LFMM("example.lfmm", "example.env", K=1, res, d = 2)
res = LFMM("example.lfmm", "example.env", K=2:3, res)

summary(res)
plot(res)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
