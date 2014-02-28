\name{ped2geno}
\alias{ped2geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{ped}} to \code{\link{geno}} format}
\description{
A function that converts from the \code{\link{ped}} format to the \code{\link{geno}} format.
}
\usage{
ped2geno(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input_file}{
the path for the input file (in \code{\link{ped}} format). 
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
\code{\link{ped}}
\code{\link{geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ancestrymap2geno}}
\code{\link{geno2lfmm}}
\code{\link{ped2lfmm}}
\code{\link{vcf2geno}}
\code{\link{lfmm2geno}}
}
\examples{
# creation of example.ancestrymap
data("example_ped")
write.table(example_ped,"example.ped",col.names = FALSE, row.names = FALSE, quote = FALSE)

# conversion from the ped (example.ped) to the geno (example.geno) format
output = ped2geno("example.ped")

# read of the output file
read.geno("example.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
