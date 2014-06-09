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
a character string containing a path to the input file,
a genotypic matrix in the \code{\link{ped}} format. 
}
  \item{output_file}{
a character string containing a path to the output file,
a genotypic matrix in the \code{\link{geno}} format. 
By default, the name of the output file is the same name 
as the input file with a .geno extension.
}
}
\value{
\item{output_file}{
a character string containing a path to the output file,
a genotypic matrix in the \code{\link{geno}} format. 
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
# Creation of a file called "example.ped"
# with 4 SNPs for 3 individuals.
data("example_ped")
write.table(example_ped,"example.ped",
	col.names = FALSE, row.names = FALSE, quote = FALSE)

# Conversion 	from the ped format ("example.ped") 
#		to the geno format ("example.geno").
# By default, 	the name of the output file is the same name 
#		as the input file with a .geno extension.
# Create file:	"example.geno".
output = ped2geno("example.ped")

# Conversion 	from the ped format ("example.ped") 
#		to the geno format with the output file called "plop.geno".
# Create file:	"plop.geno".
output = ped2geno("example.ped", "plop.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
