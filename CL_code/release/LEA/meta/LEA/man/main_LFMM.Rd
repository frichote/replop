\name{LFMM}
\alias{LFMM}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Fitting Latent Factor Mixed Models}
\description{
\code{\link{LFMM}} is used to fit Latent Factor Mixed Models.
}
\usage{
LFMM (	input_file, variable_file, K, nd, all = FALSE, 
	output_file, missing_data = FALSE, 
	num_CPU = 1, num_iterations = 1000, num_burnin = 100, 
	seed = -1, DIC_file)

}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the genotype input file (in \code{\link{lfmm}} format).
}
\item{variable_file}{
	the path for the variable input file (in \code{\link{env}} format).
}
\item{K}{
	the number of latent factors. Several methods to choose \code{K} are described in the tutorial, \code{\link{tuto}}. Check the references for more informations.
}
\item{nd}{
	fit \code{LFMM} with the \code{nd}-th variable only from \code{variable_file}. By default (if NULL and all is FALSE), fit \code{LFMM} with each variable from \code{variable_file} sequentially and independently.
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
	the number of total iterations in the Gibbs Sampling algorithm.
}
\item{num_burnin}{
	the number of burnin iterations in the Gibbs Sampling algorithm.
}
\item{seed}{
	the seed to initialize the randomization. By default, the seed is randomly chosen.
}
\item{DIC_file}{
	the path for the file containing the DIC and the deviance criterion. By default, the name of the DIC file is the name of the input file with .dic extension.
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
# creation of the example file
#data(tuto)
#write.lfmm(R, "tuto.lfmm")
#write.env(C, "tuto.env")

#res = LFMM("tuto.lfmm", "tuto.env", 2)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
