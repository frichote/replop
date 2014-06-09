\name{tracyWidom}
\alias{tracyWidom}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Tracy-Widom test for eigenvalues}
\description{
Perform tracy-widom tests on a set of eigenvalues to determine the number of significative eigenvalues and calculate the percentage of variance explained by each principal component. 
}
\usage{
tracyWidom  (eigenvalue_input_file, tracywidom_output_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{eigenvalue_input_file}{
a character string containing a path to the input file,
a vector of eigenvalues in the .eigenvalues format.
}
\item{tracywidom_output_file}{
a character string containing a path to the output.
By default, the name of the output file is the same name 
as the input file with a .tracywidom extension.
}
}
\value{
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

# Creation of the genotype file, tuto.lfmm.
# It contains 10000 SNPs for 50 individuals.
data("tuto")
write.lfmm(R, "tuto.lfmm")

# run of PCA
# available options, 	K (the number of PCs calculated), 
#			center and scale. 
# Created files: tuto.eigenvalues - eigenvalues,	
#		 tuto.eigenvectors - eigenvectors,
#		 tuto.sdev - standard deviations,
#		 tuto.projections - projections,
#		 tuto.pcaClass - the pcaClass object.
# All informations of the analysis are available 
#		in a pca-class object, res.
res = pca("tuto.lfmm", scale = TRUE)

# Perfom Tracy-Widom tests on the eigenvalues.
# Created file: tuto.tracyWidom - tracy-widom test informations.	
tw = tracyWidom(res$eigenvalue_file)

# Plot the percentage of variance explained by each component.
plot(tw$percentage)

# Display the p-values (for Tracy-Widom test) associated with each PC. 
tw$pvalues

# run of PCA
res = pca("tuto.lfmm", scale = TRUE)

# tracy-widom tests of eigenvalues
tw = tracyWidom("tuto.eigenvalues")

# results
tw$pvalues
plot(tw$percentage)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{pca}
