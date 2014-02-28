\name{pca}
\alias{pca}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Principal Component Analysis}
\description{
Performs a principal components analysis. 
}
\usage{
pca  (	input_file, K, 
        center = TRUE, scale = FALSE, 
        output_file.eigenvalues, load.eigenvalues = TRUE,
        output_file.eigenvectors, load.eigenvectors = TRUE,
        output_file.sdev, load.sdev = TRUE,
        output_file.projection, load.projection = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the genotype input file (in \code{\link{geno}} format).
}
\item{K}{
	the number of calculated principal components. By default, all principal components are calculated.
}
\item{center}{
	a boolean option. If true, the data matrix is centered.
}
\item{scale}{
	a boolean option. If true, the data matrix is centered and scaled.
}
\item{output_file.eigenvalues}{
	the path for the output file with the eigenvalues. By default, the name of the output file is the name of the input file with .eigenvalues extension (input_file.eigenvalues).
}
\item{load.eigenvalues}{
	a boolean option. If true, load the eigenvalues in R. Else, return the path for the output file with the eigenvalues. 
}
\item{output_file.eigenvectors}{
	the path for the output file with the eigenvectors. By default, the name of the output file is the name of the input file with .eigenvectors extension (input_file.eigenvectors).
}
\item{load.eigenvectors}{
	a boolean option. If true, load the eigenvectors in R. Else, return the path for the output file with the eigenvectors. 
}
\item{output_file.sdev}{
	the path for the output file with the standard deviations. By default, the name of the output file is the name of the input file with .sdev extension (input_file.sdev).
}
\item{load.sdev}{
	a boolean option. If true, load the standard deviations in R. Else, return the path for the output file with the standard deviations. 
}
\item{output_file.projection}{
	the path for the output file with the projections. By default, the name of the output file is the name of the input file with .projection extension (input_file.projection).
}
\item{load.x}{
	a boolean option. If true, load the projections in R. Else, return the path for the output file with the projections. 
}
}
\value{
\item{eigenvalues}{
        if load.eigenvalues is true, the vector of eigenvalues. Otherwise, the path for the output file with the eigenvalues.
}
\item{eigenvectors}{
        if load.eigenvectors is true, the matrix of eigenvectors (one column per eigenvector). Otherwise, the path for the output file with the eigenvectors.
}
\item{sdev}{
        if load.sdev is true, the vector of standard deviations. Otherwise, the path for the output file with the standard deviations.
}
\item{projection}{
        if load.projection is true, the matrix of projections (one column per projection). Otherwise, the path for the output file with the projections.
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
# creation of tuto.lfmm
data("tuto")
#write.lfmm(R, "tuto.lfmm")

# run of PCA
#res = pca("tuto.lfmm", scale = TRUE)

# display percentage of variances, PC1-PC2 and PC3-PC4
#par(mfrow=c(3,1))
#plot(res$eigenvalues/sum(res$eigenvalues), xlab="K", ylab="percentage of variance", title="Tuto")
#plot(res$eigenvectors[,1:2], xlab="PC1", ylab="PC2", title="Tuto")
#plot(res$eigenvectors[,3:4], xlab="PC3", ylab="PC4", title="Tuto")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{pca}
