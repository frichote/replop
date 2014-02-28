\name{ancestrymap2lfmm}
\alias{ancestrymap2lfmm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Convert from \code{\link{ancestrymap}} to \code{\link{lfmm}} format}
\description{
A function that converts from the \code{\link{ancestrymap}} format to the \code{\link{lfmm}} format.
}
\usage{
ancestrymap2lfmm(input_file, output_file = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{input_file}{
the path for the input file (in \code{\link{ancestrymap}} format). 
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
\code{\link{ancestrymap}}
\code{\link{lfmm}}
\code{\link{ancestrymap2geno}}
\code{\link{geno2lfmm}}
\code{\link{ped2lfmm}}
\code{\link{ped2geno}}
\code{\link{vcf2geno}}
\code{\link{lfmm2geno}}
}


\examples{
# creation of example.ancestrymap
data("example_ancestrymap")
write.table(example_ancestrymap,"example.ancestrymap",col.names = FALSE, row.names = FALSE, quote = FALSE)

# conversion from the ancestrymap (example.ancestrymap) to the lfmm (example.lfmm) format
output = ancestrymap2lfmm("example.ancestrymap")

# read of the output file
R = read.lfmm("example.lfmm")
}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{format}
\keyword{LFMM}
