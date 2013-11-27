# generate diagonalize

N = 10;
K = 10
R = matrix(runif(N*N),ncol=N)
R = R %*% t(R)
write.table(R,"files/N10_K10.txt",col.names=FALSE,row.names=FALSE)
e = eigen(R); 
write.table(e$values[1:K],"files/val_N10_K10.txt",col.names=FALSE,row.names=FALSE)
write.table(e$vectors[,1:K],"files/vect_N10_K10.txt",col.names=FALSE,row.names=FALSE)

N = 10;
K = 2
R = matrix(runif(N*N),ncol=N)
R = R %*% t(R)
write.table(R,"files/N10_K2.txt",col.names=FALSE,row.names=FALSE)
e = eigen(R);
write.table(e$values[1:K],"files/val_N10_K2.txt",col.names=FALSE,row.names=FALSE)
write.table(e$vectors[,1:K],"files/vect_N10_K2.txt",col.names=FALSE,row.names=FALSE)

