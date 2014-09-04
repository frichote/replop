\name{tracy.widom}
\alias{tracy.widom}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Tracy-Widom test for eigenvalues}
\description{
Perform tracy-widom tests on a set of eigenvalues to determine the number of significative eigenvalues and calculate the percentage of variance explained by each principal component. For an example, see \code{\link{pca}}. 
}
\usage{
tracy.widom (object)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{object}{
a pcaProject object.
}
}
\value{
\code{tracy.widom} returns a list containing the following components:
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
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{pca}
