# generate F_tF_alpha
# generate F_tX

N = 10; M=100;
K=sample(1:N,1)
write.table(K,"files/K.txt",col.names = FALSE, row.names = FALSE)

alpha = runif(1,0,1000)
write.table(alpha,"files/alpha.txt",col.names = FALSE, row.names = FALSE)

R = matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N)
write.table(R,"files/R.txt", col.names=FALSE, row.names=FALSE, sep="")

Fp = matrix(runif(M*3*K), ncol = K)
write.table(Fp,"files/F.txt", col.names=FALSE, row.names=FALSE)

Rf = matrix(0,ncol=3*M,nrow=N)

for(j in 1:M) {
        Rf[which(R[j,] == 0),3*(j-1)+1] = 1
        Rf[which(R[j,] == 1),3*(j-1)+2] = 1
        Rf[which(R[j,] == 2),3*(j-1)+3] = 1
}

temp1 = t(Fp) %*% Fp + alpha
write.table(temp1,"files/ref_temp1.txt", col.names=FALSE, row.names=FALSE)

temp3 = t(Fp) %*% t(Rf)
write.table(temp3,"files/ref_temp3.txt", col.names=FALSE, row.names=FALSE)
