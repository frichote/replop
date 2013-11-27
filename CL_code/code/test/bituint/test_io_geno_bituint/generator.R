
N = 10; M = 100; nc=2
name = paste("files/N",N,"_M",M,"_nc",nc,".geno",sep="");
write.table(matrix(sample(0:(nc-1),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 10; M = 100; nc=3
name = paste("files/N",N,"_M",M,"_nc",nc,".geno",sep="");
write.table(matrix(sample(0:(nc-1),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 10; M = 100; nc=4
name = paste("files/N",N,"_M",M,"_nc",nc,".geno",sep="");
write.table(matrix(sample(0:(nc-1),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 10; M = 1;nc=3; 
name = paste("files/N",N,"_M",M,"_nc",nc,".geno",sep="");
write.table(matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 1; M = 1000; nc=3;
name = paste("files/N",N,"_M",M,"_nc",nc,".geno",sep="");
write.table(matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 1; M = 1; nc=3;
name = paste("files/N",N,"_M",M,"_nc",nc,".geno",sep="");
write.table(matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

name = paste("files/6.geno",sep="");
write.table(matrix(6),name,col.names=FALSE,row.names=FALSE,sep="")
