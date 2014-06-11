\name{read.zscore}
\alias{read.zscore}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Read the output files of \code{\link{LFMM}}}
\description{
Read the output file from \code{\link{LFMM}}.
}
\usage{
read.zscore(input_file)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
a character string containing a path to the output of \code{\link{LFMM}}.
}
}
\value{
\item{R}{
	A matrix containing the \code{\link{LFMM}} results with one line per SNP. 
	The first column is the zscore. The second column is the -log10(p-value).
	The third column is the p-value.
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
write.lfmm(R, "tuto.lfmm")
write.env(C, "tuto.env")

# run of LFMM
res = LFMM("tuto.lfmm", "tuto.env", 2, d = 1)

# read of the zscore output file
z = read.zscore(res@runs[[1]]@zscore_file)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{LFMM}
