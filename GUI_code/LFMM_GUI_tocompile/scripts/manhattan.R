
#    LFMM GUI, file: manhattan.R
#    Copyright (C) 2012 Eric Frichot
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.



source("scripts/qqman.r")
args <- commandArgs(TRUE)

name = read.table(args[1])
name = as.matrix(name[-1,])

CHR = as.numeric(name[,2]);
SNP = as.character(name[,1]);
BP = as.numeric(name[,3]);
P = as.numeric(name[,6]);

res = data.frame(SNP=SNP,CHR=CHR,BP=BP,P=P)

snps_to_highlight = as.matrix(read.table(args[2]))

pdf(args[3], bg = "white") 
manhattan(res,limitchromosomes=F,genomewideline=F,suggestiveline=F,annotate=snps_to_highlight,pch=20,main="Manhattan Plot")
dev.off()
