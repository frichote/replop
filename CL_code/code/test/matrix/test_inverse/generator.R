# generate fast_inverse
# generate detrm
# generate trans
N = 10; M = 100;
R = matrix(runif(N*M),ncol=M)
data = R %*% t(R)
inv = solve(data)
write.table(data, "data_N10.txt", col.names = FALSE, row.names = FALSE)
write.table(inv, "inv_N10.txt", col.names = FALSE, row.names = FALSE)
write.table(det(data), "det_N10.txt", col.names = FALSE, row.names = FALSE)

N = 1; M = 1;
R = matrix(runif(N*M),ncol=M)
data = R %*% t(R)
inv = solve(data)
write.table(data, "data_N1.txt", col.names = FALSE, row.names = FALSE)
write.table(inv, "inv_N1.txt", col.names = FALSE, row.names = FALSE)
write.table(det(data), "det_N1.txt", col.names = FALSE, row.names = FALSE)
