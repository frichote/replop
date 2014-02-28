\name{tracyWidom}
\alias{tracyWidom}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Tracy-Widom test for eigenvalues}
\description{
Performs tracy-widom tests on a set of eigenvalues to determine the number of significative eigenvalues and calculate the percentage of variance explained by each principal component. 
}
\usage{
tracyWidom  (input_file.eigenvalues, output_file.tracywidom)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file.eigenvalues}{
	the path for the eigenvalues input file (with one column).
}
\item{output_file.tracywidom}{
	the path for the tracywidom output file. By default, the name of the output file is the name of the input file with .tracywidom extension (input_file.tracywidom).
}
}
\value{
\item{eigenvalues}{
	the sorted input vector of eigenvalues
}
\item{twstats}{
	the vector of tracy-widom statistics.
}
\item{pvalues}{
	the vector of p-values for each eigenvalue. 
}
\item{effecn}{
	the vector of effective sizes.
}
\item{percentage}{
	the vector of percentage of variance explained by each principal component.
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
# creation of tuto.lfmm
data("tuto")
#write.lfmm(R, "tuto.lfmm")

# run of PCA
#res = pca("tuto.lfmm", scale = TRUE)

# tracy-widom tests of eigenvalues
#tw = tracyWidom("tuto.eigenvalues")

#tw$pvalues
#plot(tw$percentage)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{pca}
