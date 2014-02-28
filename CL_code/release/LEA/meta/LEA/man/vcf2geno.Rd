\name{vcf2geno}
\alias{vcf2geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{vcf}} to \code{\link{geno}} format}
\description{
A function that convert from the \code{\link{vcf}} format to the \code{\link{geno}} format.
}
\usage{
vcf2geno(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input_file}{
the path for the input file (in \code{\link{vcf}} format). 
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
\code{\link{vcf}}
\code{\link{geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{ancestrymap2geno}}
\code{\link{ped2lfmm}}
\code{\link{ped2geno}}
\code{\link{lfmm2geno}}
\code{\link{geno2lfmm}}
}
\examples{
# creation of example.vcf
data("example_vcf")
write.table(example_vcf,"example.vcf",col.names =
c("#CHROM", "POS", "ID", "REF", "ALT", "QUAL", "FILTER", "INFO", 
  "FORMAT", "SAMPLE0", "SAMPLE1", "SAMPLE2"), 
row.names = FALSE, quote = FALSE)

# conversion from the vcf (example.vcf) to the geno (example.geno) format
output = vcf2geno("example.vcf")

# read of the output file
R = read.geno("example.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
