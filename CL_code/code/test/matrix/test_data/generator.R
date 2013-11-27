# generate zeros
N=10;M=10;
R = matrix(0,ncol=N,nrow=M)
write.table(R,"files/ref_zeros.txt",col.names=FALSE, row.names=FALSE);


# generate check_mat

# generate update_m
N=10;M=10;
R = matrix(runif(N*M),ncol=N);
write.table(R,"files/data_N10_M10.txt",col.names=FALSE, row.names=FALSE);
write.table(R/2,"files/update_N10_M10.txt",col.names=FALSE, row.names=FALSE);

# generate create_I
N=10;M=10;
R = matrix(sample(c(1:10,-9), N*M, replace = TRUE),ncol=N);
R[,1] = 0
R[,10] = 10
write.table(R, "files/create_I_N10_M10.txt", col.names=FALSE, row.names=FALSE);
Rp = matrix(1,ncol=N, nrow=M);
Rp[which(R == -9 | R == 9)] = 0
write.table(Rp, "files/I_N10_M10.txt", col.names=FALSE, row.names=FALSE);

# generate clean_data

