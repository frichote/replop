# generate create_m_beta
# generate create_CCt
# generate create_inv_cov_beta

N=10;M=100;
K=sample(1:N,1)
D=sample(1:(N-K+1),1);

write.table(D,"files/D.txt",col.names = FALSE, row.names = FALSE)
write.table(K,"files/K.txt",col.names = FALSE, row.names = FALSE)

R = matrix(runif(N * M), ncol= M)
#name = paste("files/R_N", N, "_M", M, ".txt", sep="")
write.table(R, "files/R.txt", col.names = FALSE, row.names = FALSE)

U = matrix(runif(K * N), ncol= N)
#name = paste("files/U_N",N,"_K",K,".txt",sep="")
write.table(U, "files/U.txt", col.names = FALSE, row.names = FALSE)

V = matrix(runif(K * M), ncol= M)
#name = paste("files/V_M",M,"_K",K,".txt",sep="")
write.table(V, "files/V.txt", col.names = FALSE, row.names = FALSE)

C = matrix(runif(D * N), ncol= D)
#name = paste("files/C_N",N,"_D",D,".txt",sep="")
write.table(C, "files/C.txt", col.names = FALSE, row.names = FALSE)

CCt = t(C) %*% C;
#name = paste("files/ref_CCt_D",D,".txt",sep="")
write.table(CCt, "files/ref_CCt.txt", col.names = FALSE, row.names = FALSE)

m_beta = t(C) %*% (R - t(U) %*% V);
#name = paste("files/ref_m_beta_D",D,"_M",M,".txt",sep="")
write.table(m_beta, "files/ref_m_beta.txt", col.names = FALSE, row.names = FALSE)

alpha_beta = matrix(runif(D), nrow=D)
write.table(alpha_beta, "files/alpha_beta.txt", col.names = FALSE, row.names = FALSE)

inv_cov_beta = solve(2.5 * CCt + diag(as.vector(alpha_beta), nrow=D))
write.table(inv_cov_beta, "files/ref_inv_cov_beta.txt", col.names = FALSE, row.names = FALSE)
