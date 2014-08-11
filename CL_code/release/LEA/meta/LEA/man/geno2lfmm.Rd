\name{geno2lfmm}
\alias{geno2lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{geno}} to \code{\link{lfmm}} format}
\description{
A function that converts from the \code{\link{geno}} format to the \code{\link{lfmm}} format.
}
\usage{
geno2lfmm(input.file, output.file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{input.file}{
A character string containing a path to the input file,
a genotypic matrix in the \code{\link{geno}} format. 
}
  \item{output.file}{
A character string containing a path to the output file,
a genotypic matrix in the \code{\link{lfmm}} format. 
By default, the name of the output file is the same name 
as the input file with a .lfmm extension.
}
}
\value{
\item{output.file}{
A character string containing a path to the output file,
a genotypic matrix in the \code{\link{lfmm}} format. 
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
\code{\link{read.geno}}
\code{\link{write.geno}}
}
\examples{
# Creation of a file called "tuto.geno" in the working directory
# with 1000 SNPs for 100 individuals.
G = matrix(sample(c(0,1,2),replace=TRUE, size=1000*100), ncol=1000, nrow=100)
write.geno(G, "tuto.geno")

# Conversion   from the geno format ("tuto.geno") 
#              to the lfmm format ("tuto.lfmm").
# By default,  the name of the output file is the same name 
#              as the input file with a .lfmm extension.
# Create file: "tuto.lfmm".
output = geno2lfmm("tuto.geno")

# Conversion   from the geno format ("tuto.geno") 
#              to the lfmm format with the output file called "plop.lfmm".
# Create file: "plop.lfmm".
output = geno2lfmm("tuto.geno", "plop.lfmm")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{sNMF}
\keyword{LFMM}
