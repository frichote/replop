# generate read_data_double
# generate write_data_double
# generate print_data_double

N = 10; M = 100;
R = matrix(runif(N * M, -1, 1), ncol=M)
name = paste("files/N",N,"_M",M,".txt",sep="");
write.table(R,name, col.names=FALSE, row.names=FALSE);

N = 10; M = 1;
R = matrix(runif(N * M, -1, 1), ncol=M)
name = paste("files/N",N,"_M",M,".txt",sep="");
write.table(R,name, col.names=FALSE, row.names=FALSE);

N = 1; M = 1000;
R = matrix(runif(N * M, -1, 1), ncol=M)
name = paste("files/N",N,"_M",M,".txt",sep="");
write.table(R,name, col.names=FALSE, row.names=FALSE);

N = 1; M = 1;
R = matrix(runif(N * M, -1, 1), ncol=M)
name = paste("files/N",N,"_M",M,".txt",sep="");
write.table(R,name, col.names=FALSE, row.names=FALSE);

