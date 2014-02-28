\name{lfmm2geno}
\alias{lfmm2geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{lfmm}} to \code{\link{geno}} format}
\description{
A function that converts from the \code{\link{lfmm}} format to the \code{\link{geno}} format.
}
\usage{
lfmm2geno(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input_file}{
the path for the input file (in \code{\link{lfmm}} format). 
}
  \item{output_file}{
the path for the output file (in \code{\link{geno}} format). 
By default, the name of the output file is the name of the input_file with .geno extension.

}
}
\value{
\item{output_file}{
the path for the output file.
}
}
\author{
    Eric Frichot
}
\seealso{
\code{\link{lfmm}}
\code{\link{geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ancestrymap2geno}}
\code{\link{geno2lfmm}}
\code{\link{ped2lfmm}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
}
\examples{
# creation of example.lfmm
data("example_lfmm")
write.table(example_lfmm,"example.lfmm",col.names = FALSE, row.names = FALSE, quote = FALSE)

# conversion from the lfmm (example.lfmm) to the geno (example.geno) format
output = lfmm2geno("example.lfmm")

# read of the output file
R = read.geno("example.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
\keyword{LFMM}
