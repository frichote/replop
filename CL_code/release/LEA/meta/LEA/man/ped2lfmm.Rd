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
A character string containing a path to the input file,
a genotypic matrix in the \code{\link{ped}} format. 
}
  \item{output_file}{
A character string containing a path for the output file,
a genotypic matricx in the \code{\link{lfmm}} format. 
By default, the name of the output file is the same name 
as the input file with a .lfmm extension.
}
}
\value{
\item{output_file}{
A character string containing a path for the output file,
a genotypic matricx in the \code{\link{lfmm}} format. 
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
# Creation of a file called "example.ped"
# with 4 SNPs for 3 individuals.
data("example_ped")
write.table(example_ped,"example.ped",
	col.names = FALSE, row.names = FALSE, quote = FALSE)

# Conversion 	from the ped format ("example.ped") 
#		to the lfmm format ("example.lfmm").
# By default, 	the name of the output file is the same name 
#		as the input file with a .lfmm extension.
# Create file:	"example.lfmm".
output = ped2lfmm("example.ped")

# Conversion 	from the ped format ("example.ped") 
#		to the geno format with the output file called "plop.lfmm".
# Create file:	"plop.lfmm".
output = ped2lfmm("example.ped", "plop.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{LFMM}
