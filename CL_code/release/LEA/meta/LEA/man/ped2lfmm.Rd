\name{ped2lfmm}
\alias{ped2lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{ped}} to \code{\link{lfmm}} format}
\description{
A function that converts from the \code{\link{ped}} format to the \code{\link{lfmm}} format.
}
\usage{
ped2lfmm(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input_file}{
the path for the input file (in \code{\link{ped}} format). 
}
  \item{output_file}{
the path for the output file (in \code{\link{lfmm}} format). 
By default, the name of the output file is the name of the input_file with .lfmm extension.
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
\code{\link{ped}}
\code{\link{lfmm}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ancestrymap2geno}}
\code{\link{geno2lfmm}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
\code{\link{lfmm2geno}}
}
\examples{
# creation of example.ped
data("example_ped")
write.table(example_ped,"example.ped",col.names = FALSE, row.names = FALSE, quote = FALSE)

# conversion from the ped (example.ped) to the lfmm (example.lfmm) format
output = ped2lfmm("example.ped")

# read of the output file
read.lfmm("example.lfmm")

}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{LFMM}
