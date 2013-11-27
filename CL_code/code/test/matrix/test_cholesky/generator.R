# generate cholesky

N = 10
R = matrix(runif(N*100),nrow=N);
write.table(R %*% t(R), "files/file_N10.txt",col.names=FALSE,row.names=FALSE)

write.table(t(chol(R %*% t(R))), "files/chol_file_N10.txt",col.names=FALSE,row.names=FALSE)

N = 1
R = matrix(runif(N*100),nrow=N);
write.table(R %*% t(R), "files/file_N1.txt",col.names=FALSE,row.names=FALSE)
write.table(t(chol(R %*% t(R))), "files/chol_file_N1.txt",col.names=FALSE,row.names=FALSE)
