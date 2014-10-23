\name{G}
\alias{G}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Ancestral allele frequencies from a sNMF run}
\description{
Return the \code{sNMF} output matrix of ancestral allele frequency matrix for the chosen run 
with K ancestral populations. For an example, see \code{\link{sNMF}}.
}
\usage{
G(object, K, run)
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
A chosen run.
}
}
\value{
\item{res}{
A matrix containing the ancestral allele frequencies for the chosen run with K ancestral populations. 
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
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{sNMF}
