# generate least_square

N = 10; M=100;
K=sample(1:N,1)
write.table(K,"files/K.txt",col.names = FALSE, row.names = FALSE)

alpha = runif(1,0,1000);
write.table(alpha,"files/alpha.txt",col.names = FALSE, row.names = FALSE)

R = matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N)
write.table(R,"files/R.txt", col.names=FALSE, row.names=FALSE, sep="")

Q = matrix(runif(N*K), ncol = K)
write.table(Q,"files/Q.txt", col.names=FALSE, row.names=FALSE)

Fp = matrix(runif(K*M*3), ncol = K, nrow=3*M)
write.table(Fp,"files/F.txt", col.names=FALSE, row.names=FALSE)
Rf = matrix(0,ncol=3*M,nrow=N)

for(j in 1:M) {
	Rf[which(R[j,] == 0),3*(j-1)+1] = 1
	Rf[which(R[j,] == 1),3*(j-1)+2] = 1
	Rf[which(R[j,] == 2),3*(j-1)+3] = 1
}

res = sum(sum((Rf-Q %*% t(Fp))^2)) 
norm1 = 0
for (i in 1:N) {
	norm1 = norm1 + (sum(abs(Q[i,])))^2
}
res = res + 2*sqrt(alpha) * norm1
write.table(res,"files/ref_LS.txt",col.names = FALSE, row.names = FALSE)

