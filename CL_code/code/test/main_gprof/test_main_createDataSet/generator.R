# generate main

N=100;M=10000;
s = sample(c(0, 1, 2, 9), N * M, replace = TRUE)
Rp = matrix(s, ncol = M, byrow = FALSE)
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(t(Rp),name,col.names=FALSE,row.names=FALSE,sep="")

