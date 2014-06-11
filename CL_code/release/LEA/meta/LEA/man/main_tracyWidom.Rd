\name{tracyWidom}
\alias{tracyWidom}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Tracy-Widom test for eigenvalues}
\description{
Perform tracy-widom tests on a set of eigenvalues to determine the number of significative eigenvalues and calculate the percentage of variance explained by each principal component. 
}
\usage{
tracyWidom  (object)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{object}{
a pcaClass object.
}
}
\value{
\code{tracyWidom} returns a list containing the following components:
\item{eigenvalues}{
        The sorted input vector of eigenvalues (by descreasing order).
}
\item{twstats}{
        The vector of tracy-widom statistics.
}
\item{pvalues}{
        The vector of p-values associated with each eigenvalue. 
}
\item{effecn}{
        The vector of effective sizes.
}
\item{percentage}{
        The vector containing the percentage of variance 
        explained by each principal component.
}
}
\author{
        Eric Frichot
}
\seealso{
\code{\link{pca}}
\code{\link{lfmm}}
\code{\link{LFMM}}
}
\examples{
# Creation of the genotype file "tuto.lfmm"
# with 10000 SNPs for 50 individuals.
data("tuto")
write.lfmm(R, "tuto.lfmm")

# run of PCA
# Available options, K (the number of PCs calculated), 
#                    center and scale. 
# Create files: tuto.eigenvalues - eigenvalues,        
#               tuto.eigenvectors - eigenvectors,
#               tuto.sdev - standard deviations,
#               tuto.projections - projections,
#               tuto.pcaClass - the pcaClass object.
# Create a pca-class object: pc.
pc = pca("tuto.lfmm", scale = TRUE)

# Perfom Tracy-Widom tests on all eigenvalues.
# create file: tuto.tracyWidom - tracy-widom test information.        
tw = tracyWidom(pc)

# Plot the percentage of variance explained by each component
plot(tw$percentage)

# Display the p-values for the Tracy-Widom tests. 
tw$pvalues
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{pca}
