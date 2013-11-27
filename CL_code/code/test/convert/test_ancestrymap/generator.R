# generate nb_ind_ancestrymap
N=10;M=100;
R = matrix(NA,ncol=3,nrow=N*M);
R[,1] = rep(10000+(1:M),each=N);
R[,2] = rep(100+(1:N),times=M);
s = sample(c(0, 1, 2, 9), N * M, replace = TRUE)
Rp = matrix(s, ncol = M, byrow = FALSE)
R[,3] = s
name = paste("files/N",N,"_M",M,".ancestrymap",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="\t \t  ")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(Rp,name,col.names=FALSE,row.names=FALSE,sep=" ")
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(t(Rp),name,col.names=FALSE,row.names=FALSE,sep="")

N=10;M=1;
R = matrix(NA,ncol=3,nrow=N*M);
R[,1] = rep(10000+(1:M),each=N);
R[,2] = rep(100+(1:N),times=M);
s = sample(c(0, 1, 2, 9), N * M, replace = TRUE)
Rp = matrix(s, ncol = M, byrow = FALSE)
R[,3] = s
name = paste("files/N",N,"_M",M,".ancestrymap",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="\t \t  ")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(Rp,name,col.names=FALSE,row.names=FALSE,sep=" ")
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(t(Rp),name,col.names=FALSE,row.names=FALSE,sep="")

N=1;M=1000;
R = matrix(NA,ncol=3,nrow=N*M);
R[,1] = rep(10000+(1:M),each=N);
R[,2] = rep(100+(1:N),times=M);
s = sample(c(0, 1, 2, 9), N * M, replace = TRUE)
Rp = matrix(s, ncol = M, byrow = FALSE)
R[,3] = s
name = paste("files/N",N,"_M",M,".ancestrymap",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="\t \t  ")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(Rp,name,col.names=FALSE,row.names=FALSE,sep=" ")
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(t(Rp),name,col.names=FALSE,row.names=FALSE,sep="")

N=1;M=1;
R = matrix(NA,ncol=3,nrow=N*M);
R[,1] = rep(10000+(1:M),each=N);
R[,2] = rep(100+(1:N),times=M);
s = sample(c(0, 1, 2, 9), N * M, replace = TRUE)
Rp = matrix(s, ncol = M, byrow = FALSE)
R[,3] = s
name = paste("files/N",N,"_M",M,".ancestrymap",sep="");
write.table(R,name,col.names=FALSE,row.names=FALSE,sep="\t \t  ")
name = paste("files/N",N,"_M",M,".lfmm",sep="");
write.table(Rp,name,col.names=FALSE,row.names=FALSE,sep=" ")
name = paste("files/N",N,"_M",M,".geno",sep="");
write.table(t(Rp),name,col.names=FALSE,row.names=FALSE,sep="")

