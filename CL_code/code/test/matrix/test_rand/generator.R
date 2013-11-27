# generate zscore2pvalue

zscore = 0:3000/100
pvalue = -log10(2*pnorm(-abs(zscore)))
write.table(zscore, "files/ref_zscore.txt", col.names=FALSE, row.names=FALSE);
write.table(pvalue, "files/ref_mlpvalue.txt", col.names=FALSE, row.names=FALSE);
