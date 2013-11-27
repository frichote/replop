# generate main
N = 10; M = 1000;
name = paste("files/N",N,"_M",M,".geno",sep="");
R = matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N);
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="")

