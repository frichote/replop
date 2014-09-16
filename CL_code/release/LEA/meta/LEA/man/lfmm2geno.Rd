\name{lfmm2geno}
\alias{lfmm2geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{lfmm}} to \code{\link{geno}} format}
\description{
A function that converts from the \code{\link{lfmm}} format to the \code{\link{geno}} format.
}
\usage{
lfmm2geno(input.file, output.file = NULL, force = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input.file}{
A character string containing a path to the input file,
a genotypic matrix in the \code{\link{lfmm}} format. 
}
  \item{output.file}{
A character string containing a path to the output file,
a genotypic matrix in the \code{\link{geno}} format. 
By default, the name of the output file is the same name 
of the input file with a .geno extension.
}
\item{force}{
        A boolean option. If FALSE, the input file is converted only if the output
        file does not exist. If TRUE, convert the file anyway.
}
}
\value{
\item{output.file}{
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
# Creation of a file called "genotypes.lfmm" in the working directory,
# with 1000 SNPs for 165 individuals.
data("tutorial")
write.lfmm(R, "genotypes.lfmm")

# Conversion   from the lfmm format ("genotypes.lfmm") 
#              to the geno format ("genotypes.geno").
# By default,  the name of the output file is the same name 
#              as the input file with a .geno extension.
# Create file: "genotypes.geno".
output = lfmm2geno("genotypes.lfmm")

# Conversion   from the lfmm format ("genotypes.lfmm") 
#              to the geno format with the output file called "plop.geno".
# Create file: "plop.geno".
output = lfmm2geno("genotypes.lfmm", "plop.geno")

# As force = false and the file "genotypes.geno" already exists,
# nothing happens.
output = lfmm2geno("genotypes.lfmm", force = FALSE)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{conversion}
