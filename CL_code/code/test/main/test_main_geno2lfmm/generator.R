# generate main

N = 10; M = 1000;
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

