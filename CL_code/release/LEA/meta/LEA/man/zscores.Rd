\name{z.scores}
\alias{z.scores}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{z-scores from a LFMM run}
\description{
Return the \code{LFMM} output matrix of zscores for the chosen runs with K
latent factors, the d-th variable and the all option. For an example, see
\code{\link{LFMM}}.
}
\usage{
z.scores (object, K, d, all, run)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{object}{
A lfmmProject object.
}
\item{K}{
The number of latent factors.
}
\item{d}{
The d-th variable.
}
\item{all}{
A Boolean option. If true, the run with all variables at the same time. If false, the runs
with each variable separately.
}
\item{run}{
A list of chosen runs.
}
}
\value{
\item{res}{
A matrix containing a vector of z-scores for the chosen runs per column. 
}
}
\author{
        Eric Frichot
}
\seealso{
\code{\link{lfmm}}
\code{\link{LFMM}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
