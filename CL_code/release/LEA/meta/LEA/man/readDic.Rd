\name{read.dic}
\alias{read.dic}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Read the statistics output files of \code{\link{LFMM}}}
\description{
read the statistics output file from \code{\link{LFMM}}.
}
\usage{
read.dic(input_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	the path for the statistics input file.
}
}
\value{
\item{K}{
	number of latent factors used.
}
\item{D}{
	number of environmental variables.
}
\item{deviance}{
	deviance criterion.
}
\item{DIC}{
	DIC criterion.
}
\item{lambda}{
	vector of lambda criterion. One per environmental variable.
}
\item{percentage_var0}{
	proportion of variance explained by the intercept (between 0 and 1).
}
\item{perc_var}{
	proportion of variance explained by each environmental variable (between 0 and 1).
}
\item{perc_factor}{
	proportion of variance explained by each factor (between 0 and 1).
}
\item{perc_residual}{
	proportion of unexplained variance (between 0 and 1).
}
}

\author{
    Eric Frichot
}
\seealso{
\code{\link{zscore}}
\code{\link{LFMM}}
}
\examples{
# creation of the data set
data(tuto)
#write.lfmm(R, "tuto.lfmm")
#write.env(C, "tuto.env")

# run of LFMM
#res = LFMM("tuto.lfmm", "tuto.env", 2, load.out = FALSE, num_iterations = 1000, num_burnin = 200, nd = 1)

# read of the zscore output file
#R = read.("tuto_s1.2.dic")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
