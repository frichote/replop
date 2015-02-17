\name{G}
\alias{G}

\title{Ancestral allele frequencies from a sNMF run}
\description{
Return the \code{sNMF} output matrix of ancestral allele frequency matrix for 
the chosen run with K ancestral populations. For an example, see 
\code{\link{sNMF}}.
}
\usage{
G(object, K, run)
}

\arguments{
\item{object}{
A snmfProject object.
}
\item{K}{
The number of ancestral populations.
}
\item{run}{
A chosen run.
}
}
\value{
\item{res}{
A matrix containing the ancestral allele frequencies for the chosen run with 
K ancestral populations. 
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{sNMF}}
\code{\link{Q}}
\code{\link{cross.entropy}}
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

# Runs with K between 1 and 5 with cross-entropy and 2 repetitions.
project = NULL
project = sNMF("genotypes.geno", K = 3, repetitions = 2, project = "new")

# get the ancestral genotype frequency matrix, G, for the 2nd run for K = 3. 
res = G(project, K = 3, run = 2)
}


\keyword{sNMF}
