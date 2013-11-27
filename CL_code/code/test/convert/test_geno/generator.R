
# generate fill_line_geno
# generate read_geno
# generate write_geno

N = 10; M = 100; 
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 10; M = 1; 
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 1; M = 1000; 
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

N = 1; M = 1; 
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N),name,col.names=FALSE,row.names=FALSE,sep="")

name = paste("files/6.geno",sep="");
write.table(matrix(6),name,col.names=FALSE,row.names=FALSE,sep="")
