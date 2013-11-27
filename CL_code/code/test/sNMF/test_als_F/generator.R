# generate update_F

# generate normalize_F

N = 10; M=100;
K=sample(1:N,1)
write.table(K,"files/K.txt",col.names = FALSE, row.names = FALSE)

R = matrix(sample(c(0,1,2),N*M,replace=TRUE),ncol=N)
write.table(R,"files/R.txt", col.names=FALSE, row.names=FALSE, sep="")

Q = matrix(runif(N*K), ncol = K)
write.table(Q,"files/Q.txt", col.names=FALSE, row.names=FALSE)

Rf = matrix(0,ncol=3*M,nrow=N)

for(j in 1:M) {
        Rf[which(R[j,] == 0),3*(j-1)+1] = 1
        Rf[which(R[j,] == 1),3*(j-1)+2] = 1
        Rf[which(R[j,] == 2),3*(j-1)+3] = 1
}


Fp = t(Rf) %*% Q %*% solve (t(Q) %*% Q);

zmax <- function(x) {
	return (max(0,x))
}

for (k in 1:K) {
	Fp[,k] = sapply(Fp[,k],zmax);
}

write.table(Fp,"files/ref_Fp.txt",col.names = FALSE, row.names = FALSE)


for (l in 1:M) {
	for (k in 1:K) {
		sum = sum(Fp[(3*(l-1)+(1:3)),k]);
		if (sum != 0) { 
			Fp[(3*(l-1)+(1:3)),k] = Fp[(3*(l-1)+(1:3)),k] / sum;
		}
	}
}

write.table(Fp,"files/ref_normalize_Fp.txt",col.names = FALSE, row.names = FALSE)
