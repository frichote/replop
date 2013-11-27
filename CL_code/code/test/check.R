args <- commandArgs(trailingOnly = TRUE)

R1 = as.matrix(read.table(args[1]));
R2 = as.matrix(read.table(args[2]));

m0 = 0;
i1 = which(R1 != 0 & R2 == 0)
i2 = which(R1 == 0 & R2 != 0)
i = which(R1 != 0 & R2 != 0)

Rd = abs(R1-R2)

if (length(i1) != 0)
	m0 = max(Rd[i1]/R1[i1])

if (length(i2) != 0) {
	m1 = max(Rd[i2]/R2[i2])
	m0 = max(m0, m1)
}

if (length(i) != 0) {
	m1 = max(Rd[i]/R2[i])
	m0 = max(m0, m1)
}

if (m0 < 0.0001) {
	print("OK");
} else {
	print("FAILED");
} 

