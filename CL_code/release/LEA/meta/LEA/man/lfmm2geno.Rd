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
A character string containing a path to the input file,
a genotypic matrix in the \code{\link{lfmm}} format. 
}
  \item{output_file}{
A character string containing a path to the output file,
a genotypic matrix in the \code{\link{geno}} format. 
By default, the name of the output file is the same name 
of the input file with a .geno extension.
}
}
\value{
\item{output_file}{
A character string containing a path to the output file,
a genotypic matrix in the \code{\link{geno}} format. 
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
library(LEA)
# Creation of a file called "tuto.lfmm" in the working directory,
# with 1000 SNPs for 100 individuals.
G = matrix(sample(c(0,1,2),replace=TRUE, size=1000*100), ncol=1000, nrow=100)
write.lfmm(G, "tuto.lfmm")

# Conversion   from the lfmm format ("tuto.lfmm") 
#              to the geno format ("tuto.geno").
# By default,  the name of the output file is the same name 
#              as the input file with a .geno extension.
# Create file: "tuto.geno".
output = lfmm2geno("tuto.lfmm")

# Conversion   from the lfmm format ("tuto.lfmm") 
#              to the geno format with the output file called "plop.geno".
# Create file: "plop.geno".
output = lfmm2geno("tuto.lfmm", "plop.geno")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
\keyword{LFMM}
