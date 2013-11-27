# generate create_m_U
# generate create_inv_cov_U

N=10;M=100;
K=sample(1:N,1)
D=sample(1:(N-K+1),1);

write.table(D,"files/D.txt",col.names = FALSE, row.names = FALSE)
write.table(K,"files/K.txt",col.names = FALSE, row.names = FALSE)

R = matrix(runif(N * M), ncol= M)
#name = paste("files/R_N", N, "_M", M, ".txt", sep="")
write.table(R, "files/R.txt", col.names = FALSE, row.names = FALSE)

B = matrix(runif(D * M), ncol= M)
#name = paste("files/U_N",N,"_K",K,".txt",sep="")
write.table(B, "files/B.txt", col.names = FALSE, row.names = FALSE)

V = matrix(runif(K * M), ncol= M)
#name = paste("files/V_M",M,"_K",K,".txt",sep="")
write.table(V, "files/V.txt", col.names = FALSE, row.names = FALSE)

C = matrix(runif(D * N), ncol= D)
#name = paste("files/C_N",N,"_D",D,".txt",sep="")
write.table(C, "files/C.txt", col.names = FALSE, row.names = FALSE)

m_U = (R - C %*% B) %*% t(V);
#name = paste("files/ref_m_beta_D",D,"_M",M,".txt",sep="")
write.table(m_U, "files/ref_m_U.txt", col.names = FALSE, row.names = FALSE)

inv_cov_U = solve(2.5 * V %*% t(V) + diag(rep(1.3, K)));
write.table(inv_cov_U, "files/ref_inv_cov_U.txt", col.names = FALSE, row.names = FALSE)

