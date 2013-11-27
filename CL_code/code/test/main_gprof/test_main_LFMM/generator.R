# generate main
N = 100; M = 10000;
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=M),name,col.names=FALSE,row.names=FALSE,sep=" ")

name = paste("files/N",N,"_M",M,".env",sep="");
write.table(matrix(runif(N),ncol=1,nrow=N),name,col.names=FALSE,row.names=FALSE,sep=" ")

