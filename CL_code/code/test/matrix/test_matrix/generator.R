# generate dble_sum2
# generate dble_sum
# generate copy_vect
# generate trans_double
# generate trans_float
# generate trans_int
N = 10; M = 100;
R = matrix(sample(M, N * M, replace=TRUE), ncol=M);
write.table(R, "files/data_N10_M100.txt", col.name = FALSE, row.names = FALSE) 
res = NULL
for (i in 1:N) {
	res = c(res, (sum((R[i,])^2))/2 + 0.01)
}
write.table(res,"files/dble_sum2_N10_M100.txt", col.name = FALSE, row.names = FALSE) 
res = sum(R^2)
write.table(res,"files/dble_sum_N10_M100.txt", col.name = FALSE, row.names = FALSE) 
write.table(t(R),"files/trans_N10_M100.txt", col.name = FALSE, row.names = FALSE) 

N = 1; M = 100;
R = matrix(sample(M, N * M, replace=TRUE), ncol=M);
write.table(R, "files/data_N1_M100.txt", col.name = FALSE, row.names = FALSE) 
res = NULL
for (i in 1:N) {
	res = c(res, (sum((R[i,])^2))/2 + 0.01)
}
write.table(res,"files/dble_sum2_N1_M100.txt", col.name = FALSE, row.names = FALSE) 
res = sum(R^2)
write.table(res,"files/dble_sum_N1_M100.txt", col.name = FALSE, row.names = FALSE) 
write.table(t(R),"files/trans_N1_M100.txt", col.name = FALSE, row.names = FALSE) 

N = 1; M = 1;
R = matrix(sample(M, N * M, replace=TRUE), ncol=M);
write.table(R, "files/data_N1_M1.txt", col.name = FALSE, row.names = FALSE) 
res = NULL
for (i in 1:N) {
	res = c(res, sum(R[i,])^2/2 + 0.01)
}
write.table(res,"files/dble_sum2_N1_M1.txt", col.name = FALSE, row.names = FALSE) 
res = sum(R^2)
write.table(res,"files/dble_sum_N1_M1.txt", col.name = FALSE, row.names = FALSE) 
write.table(t(R),"files/trans_N1_M1.txt", col.name = FALSE, row.names = FALSE) 

N = 10; M = 1;
R = matrix(sample(M, N * M, replace=TRUE), ncol=M);
write.table(R, "files/data_N10_M1.txt", col.name = FALSE, row.names = FALSE) 
res = NULL
for (i in 1:N) {
	res = c(res, sum(R[i,])^2/2 + 0.01)
}
write.table(res,"files/dble_sum2_N10_M1.txt", col.name = FALSE, row.names = FALSE) 
res = sum(R^2)
write.table(res,"files/dble_sum_N10_M1.txt", col.name = FALSE, row.names = FALSE) 
write.table(t(R),"files/trans_N10_M1.txt", col.name = FALSE, row.names = FALSE) 
