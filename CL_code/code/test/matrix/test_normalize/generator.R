# generate normalize_cov
# generate normalize_lines

N = 10; M = 100;
R = matrix(runif(N * M), ncol = M)
write.table(R, "files/data_N10_M100.txt", col.name = FALSE, row.names = FALSE)
R = scale(R, center = TRUE, scale = TRUE)
write.table(R, "files/cov_N10_M100.txt", col.name = FALSE, row.names = FALSE)
for (i in 1:N) {
	R[i,] = R[i,] / sum(R[i,])
}
write.table(R, "files/norm_N10_M100.txt", col.name = FALSE, row.names = FALSE)
R = scale(R, center = TRUE, scale = FALSE)
write.table(R, "files/mean_N10_M100.txt", col.name = FALSE, row.names = FALSE)

N = 10; M = 1;
R = matrix(runif(N * M), ncol = M)
write.table(R, "files/data_N10_M1.txt", col.name = FALSE, row.names = FALSE)
R = scale(R, center = TRUE, scale = TRUE)
write.table(R, "files/cov_N10_M1.txt", col.name = FALSE, row.names = FALSE)
for (i in 1:N) {
	R[i,] = R[i,] / sum(R[i,])
}
write.table(R, "files/norm_N10_M1.txt", col.name = FALSE, row.names = FALSE)
R = scale(R, center = TRUE, scale = FALSE)
write.table(R, "files/mean_N10_M1.txt", col.name = FALSE, row.names = FALSE)
