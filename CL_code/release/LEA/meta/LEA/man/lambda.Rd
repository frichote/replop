\name{lambda}
\alias{lambda}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{calculate lambda criterion}
\description{
calculate lambda criterion from a p-value distribution.
}
\usage{
lambda(p)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{p}{
        a vector of p-values.
}
}
\value{
\item{lambda}{
	lambda criterion.
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{read.zscore}}
\code{\link{LFMM}}
}
\examples{
# creation of the example.geno file
data("tuto")

# write of the tuto zscore file
#z = read.zscore("tuto.zscore")

# calculate lambda
#l = lambda(z[,3])
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
