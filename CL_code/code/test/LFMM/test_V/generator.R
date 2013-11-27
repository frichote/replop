# generate create_m_V
# generate create_inv_cov_V

N=10;M=100;
K=sample(2:N,1)
D=sample(1:(N-K+1),1);

write.table(D,"files/D.txt",col.names = FALSE, row.names = FALSE)
write.table(K,"files/K.txt",col.names = FALSE, row.names = FALSE)

R = matrix(runif(N * M), ncol= M)
#name = paste("files/R_N", N, "_M", M, ".txt", sep="")
write.table(R, "files/R.txt", col.names = FALSE, row.names = FALSE)

B = matrix(runif(D * M), ncol= M)
#name = paste("files/U_N",N,"_K",K,".txt",sep="")
write.table(B, "files/B.txt", col.names = FALSE, row.names = FALSE)

U = matrix(runif(K * N), ncol= N)
#name = paste("files/V_M",M,"_K",K,".txt",sep="")
write.table(U, "files/U.txt", col.names = FALSE, row.names = FALSE)

C = matrix(runif(D * N), ncol= D)
#name = paste("files/C_N",N,"_D",D,".txt",sep="")
write.table(C, "files/C.txt", col.names = FALSE, row.names = FALSE)

m_V = U %*% (R - C %*% B);
#name = paste("files/ref_m_beta_D",D,"_M",M,".txt",sep="")
write.table(m_V, "files/ref_m_V.txt", col.names = FALSE, row.names = FALSE)

inv_cov_V = solve(2.5 * U %*% t(U) + diag(rep(1.3, K)));
write.table(inv_cov_V, "files/ref_inv_cov_V.txt", col.names = FALSE, row.names = FALSE)

