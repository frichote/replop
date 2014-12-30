\name{cross.entropy}
\alias{cross.entropy}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Cross-entropy criterion from sNMF runs}
\description{
Return the cross-entropy criterion for the chosen runs
with K ancestral populations. For an example, see \code{\link{sNMF}}.
The cross-entropy criterion is a value based on the prediction of masked 
genotypes to evaluate the error of ancestry estimation. The criterion will 
help to choose the best number of ancestral population (K) and the best run 
among a set of runs in \code{\link{sNMF}}. A smaller value of cross-entropy 
means a better run in terms of prediction capacity.
The cross-entropy criterion can be automatically calculated by the 
\code{\link{sNMF}} function with the \code{entropy} option.
}
\usage{
cross.entropy(object, K, run)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{object}{
A snmfProject object.
}
\item{K}{
The number of ancestral populations.
}
\item{run}{
A list of chosen run number.
}
}
\value{
\item{res}{
A list containing the cross-entropy criterion for the chosen runs with K 
ancestral populations. 
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{sNMF}}
\code{\link{G}}
\code{\link{Q}}
}
\examples{
### Example of analyses using sNMF ###

# creation of the genotype file, genotypes.geno.
# It contains 400 SNPs for 50 individuals.
data("tutorial")
write.geno(tutorial.R, "genotypes.geno")

################
# runs of sNMF #
################

# main options, K: (the number of ancestral populations), 
#        entropy: calculate the cross-entropy criterion, 
#        CPU: the number of CPUs.

# Runs with K = 3 with cross-entropy and 2 repetitions.
project = NULL
project = sNMF("genotypes.geno", K = 3, entropy = TRUE, repetitions = 2, 
    project = "new")

# get the cross-entropy for all runs for K = 3 
ce = cross.entropy(project, K = 3)

# get the cross-entropy for the 2nd run for K = 3
ce = cross.entropy(project, K = 3, run = 2)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
