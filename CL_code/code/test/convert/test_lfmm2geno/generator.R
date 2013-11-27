# generate lfmm2geno
# comments (write_geno: previously tested)

N = 10; M = 100;
R = matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N)
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(t(R),name,col.names=FALSE,row.names=FALSE,sep=" ")


N = 10; M = 1;
R = matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N)
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(t(R),name,col.names=FALSE,row.names=FALSE,sep=" ")

N = 1; M = 1000;
R = matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N)
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(t(R),name,col.names=FALSE,row.names=FALSE,sep=" ")

N = 1; M = 1;
R = matrix(sample(c(0,1,2,9),N*M,replace=TRUE),ncol=N)
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(t(R),name,col.names=FALSE,row.names=FALSE,sep=" ")

