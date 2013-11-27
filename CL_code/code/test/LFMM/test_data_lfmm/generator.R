# generate zscore_calc
# generate update_sum
# generate update_sum2
# generate update_mean
# generate modify_C
# generate write_DIC
# generate write_zscore_double
# generate var_data

N=10;M=100;
K=2
D=3
cur = 10

###  generate inputation_lfmm
# sum
sum = matrix(runif(D * M), ncol = M);
write.table(sum, "files/sum.txt", col.names = FALSE, row.names = FALSE)
# sum2
sum2 = sum * sum + matrix(runif(D * M), ncol = M);
write.table(sum2, "files/sum2.txt", col.names = FALSE, row.names = FALSE)
# sum2
mean = matrix(runif(D * M), ncol = M);
write.table(mean, "files/mean.txt", col.names = FALSE, row.names = FALSE)
# beta
B = matrix(runif(D * M), ncol= M)
write.table(B, "files/B.txt", col.names = FALSE, row.names = FALSE)
# R
R = matrix(runif(N * M), ncol= M)
write.table(R, "files/R.txt", col.names = FALSE, row.names = FALSE)
# C
C = matrix(runif((D-1) * N), ncol= D-1)
write.table(C, "files/C.txt", col.names = FALSE, row.names = FALSE)
# U
U = matrix(runif(K * N), ncol= N)
write.table(U, "files/U.txt", col.names = FALSE, row.names = FALSE)
# V
V = matrix(runif(K * M), ncol= M)
write.table(V, "files/V.txt", col.names = FALSE, row.names = FALSE)
# I
I = matrix(sample(0:1, N * M, replace = TRUE), ncol = M);
write.table(I, "files/I.txt", col.names = FALSE, row.names = FALSE)

# zscore
v = (sum2 - sum*sum/cur) / (cur - 1);
z = sum / (sqrt(v) * cur);
res = matrix(NA, ncol=3, nrow = M)
res[,1] = z[2,];
res[,3] = 2*pnorm(-abs(z[2,]))
res[,2] = -log10(res[,2])
write.table(res, "files/ref_zscore1-1.txt", col.names = FALSE, row.names = FALSE)
res = matrix(NA, ncol=3, nrow = M)
res[,1] = z[3,];
res[,3] = 2*pnorm(-abs(z[3,]))
res[,2] = -log10(res[,2])
write.table(res, "files/ref_zscore1-2.txt", col.names = FALSE, row.names = FALSE)

# sum
sum = sum + B;
write.table(sum, "files/ref_sum.txt", col.names = FALSE, row.names = FALSE)
# sum2
sum2 = sum2 + B * B;
write.table(sum2, "files/ref_sum2.txt", col.names = FALSE, row.names = FALSE)
# mean
mean = ((cur - 1) * mean + B) / cur;
write.table(mean, "files/ref_mean.txt", col.names = FALSE, row.names = FALSE)

CC = matrix(1,ncol=D, nrow = N)
CC[,2:D] = C[,1:(D-1)]
d = R - t(U) %*% V - CC %*% B
# var
v = var(as.vector(d));

thrd_m = sum(d^2)
res2 = c(v, thrd_m)
write.table(res2, "files/ref_var_thrd_m.txt", col.names = FALSE, row.names = FALSE);

# deviance 
# DIC
deviance = 2.1;
deviance = ((cur -1) * deviance + thrd_m / v) / cur;
res3 = c(deviance, 1.0)
write.table(res3, "files/ref_dev_dic.txt", col.names = FALSE, row.names = FALSE);

# inputation
R = I * R + (matrix(rep(1, N * M), ncol = M) - I) * (t(U) %*% V + CC %*% B) 
write.table(R, "files/ref_R.txt", col.names = FALSE, row.names = FALSE)

