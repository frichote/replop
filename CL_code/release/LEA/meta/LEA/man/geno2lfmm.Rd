\name{geno2lfmm}
\alias{geno2lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{geno}} to \code{\link{lfmm}} format}
\description{
A function that converts from the \code{\link{geno}} format to the \code{\link{lfmm}} format.
}
\usage{
geno2lfmm(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input_file}{
the path for the input file (in \code{\link{geno}} format). 
}
  \item{output_file}{
the path for the output file (in \code{\link{lfmm}} format). 
By default, the name of the output file is the name of the input file with .lfmm extension.

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
\code{\link{ped2lfmm}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
\code{\link{lfmm2geno}}
}
\examples{
# creation of example.geno
data("example_geno")
write.table(example_geno,"example.geno",col.names = FALSE, row.names = FALSE, quote = FALSE)

# conversion from the geno (example.geno) to the lfmm (example.lfmm) format
output = geno2lfmm("example.geno")

# read of the output file
R = read.lfmm("example.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
\keyword{LFMM}
