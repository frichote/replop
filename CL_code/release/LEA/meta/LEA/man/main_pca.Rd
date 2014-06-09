\name{pca}
\alias{pca}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Principal Component Analysis}
\description{
The function \code{pca} performs a Principal Component Analysis 
of a genotypic matrix using the \code{\link{lfmm}}, \code{\link{geno}}, 
\code{\link{ancestrymap}}, \code{\link{ped}} or \code{\link{vcf}} format. 
The function computes eigenvalue, eigenvector, and standard deviation 
for each principal component and the projection of each individual 
on each component. The function pca returns an object of class 
"pca-class" containing the output data and the input parameters. 
}
\usage{
pca  (	input_file, K, 
        center = TRUE, scale = FALSE, 
        eigenvalue_file, 
        eigenvector_file, 
        sdev_file, 
        projection_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
A character string containg the path to the genotype input file,
a genotypic matrix in the \code{\link{lfmm}} format.
}
\item{K}{
	An integer corresponding to the number of principal components
	calculated. By default, all principal components are calculated.
}
\item{center}{
	A boolean option. If true, the data matrix is centered.
}
\item{scale}{
	A boolean option. If true, the data matrix is centered and scaled.
}
\item{eigenvalue_file}{
A character string containing the output eigenvalues.
By default, the name of the output file is the same name 
as the input file with a .eigenvalues extension.
}
\item{eigenvector_file}{
A character string containing the output eigenvectors.
By default, the name of the output file is the same name 
as the input file with a .eigenvectors extension.
}
\item{sdev_file}{
A character string containing the output standard deviations.
By default, the name of the output file is the same name 
as the input file with a .sdev extension.
}
\item{projection_file}{
A character string containing the output principal components.
By default, the name of the output file is the same name 
as the input file with a .projections extension.
}
}
\value{
\code{pca} returns an object of class pcaClass containing the following components:
\item{eigenvalues}{
        the vector of eigenvalues.
}
\item{eigenvectors}{
        the matrix of eigenvectors (one column for each eigenvector). 
}
\item{sdev}{
        the vector of standard deviations. 
}
\item{projections}{
       	the matrix of projections (one column for each projection).
}
The following methods can be applied to the object of class pcaClass returned by \code{pca}: 
\item{plot}{ 
	plot eigenvalues.
}
\item{show}{
	display information about the analysis.
}
\item{summary}{
	summarize the analysis.
}
\item{tracyWidom}{
	perform Tracy-Widom tests on the eigenvalues.
}
\item{write.pcaClass}{\code{signature(x = "pcaClass", file = "character")}}{
	write a pcaClass object into a file.
}
\item{read.pcaClass}{\code{signature(file = "character")}}{
	read the file containing a pcaClass object and return the pcaClass object.
}
}
\author{
	Eric Frichot
}
\seealso{
\code{\link{geno}}
\code{\link{sNMF}}
\code{\link{LFMM}}
\code{\link{createDataSet}}
\code{\link{crossEntropy}}
}
\examples{
# Creation of the genotype file "tuto.lfmm"
# with 10000 SNPs for 50 individuals.
data("tuto")
write.lfmm(R, "tuto.lfmm")

# run of PCA
# Available options, 	K (the number of PCs calculated), 
#			center and scale. 
# Create files: tuto.eigenvalues - eigenvalues,	
#		 tuto.eigenvectors - eigenvectors,
#		 tuto.sdev - standard deviations,
#		 tuto.projections - projections,
#		 tuto.pcaClass - the pcaClass object.
# Create a pca-class object: pc.
pc = pca("tuto.lfmm", scale = TRUE)

### display information ###

# Display informations about the analysis.
show(pc)

# Summarize the analysis.
summary(pc)

### graphical outputs ###
par(mfrow=c(2,2))

# Plot eigenvalues.
plot(pc, lwd=5, col="red",xlab=("PCs"),ylab="eigen")

# PC1-PC2 plot.
plot(pc$projections)
# PC3-PC4 plot.
plot(pc$projections[,3:4])

# Plot standard deviations.
plot(pc$sdev)

### Tracy-Widom tests ####
# Perfom Tracy-Widom tests on all eigenvalues.
# create file: tuto.tracyWidom - tracy-widom test information.	
tw = tracyWidom(pc)

# plot the percentage of variance explained by each component
plot(tw$percentage)

# display the p-values for the Tracy-Widom tests. 
tw$pvalues
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{pca}
