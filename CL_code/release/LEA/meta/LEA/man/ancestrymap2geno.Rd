\name{ancestrymap2geno}
\alias{ancestrymap2geno}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{ancestrymap}} to \code{\link{geno}} format}
\description{
A function that converts from the \code{\link{ancestrymap}} format to the \code{\link{geno}} format.
}
\usage{
ancestrymap2geno(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
	A character string containing a path to the input file,
	a genotypic matrix in the \code{\link{ancestrymap}} format. 
}
  \item{output_file}{
	A character string containing a path to the output file,
	a genotypic matrix in the \code{\link{geno}} format. 
	By default, the name of the output file is the same name 
	as the input file with a .geno extension.
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
\code{\link{ancestrymap}}
\code{\link{geno}}
\code{\link{read.geno}}
\code{\link{ancestrymap2lfmm}}
\code{\link{geno2lfmm}}
\code{\link{ped2lfmm}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
\code{\link{lfmm2geno}}
}
\examples{
# Creation of of file called "example.ancestrymap"
# a file containing 4 SNPs for 3 individuals.
data("example_ancestrymap")
write.table(example_ancestrymap,"example.ancestrymap",
col.names = FALSE, row.names = FALSE, quote = FALSE)

# Conversion 	from the ancestrymap format ("example.ancestrymap") 
#		to the geno format ("example.geno"). 
# By default,   the name of the output file is the same name
#               as the input file with a .geno extension.
# create file:	example.geno
output = ancestrymap2geno("example.ancestrymap")

# Conversion    from the ancestrymap format (example.ancestrymap) 
#               to the geno format with the output file called plop.geno.
# Create file:	plop.geno
output = ancestrymap2geno("example.ancestrymap", "plop.geno")
}
\keyword{format}
\keyword{sNMF}
