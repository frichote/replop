read.dic <- function(input_file) {

	# test arguments
	test_character("input_file", input_file, NULL)

	R = read.table(input_file);
	res = list();

	res$K = R$V2[1]
	res$D = R$V2[2]
	res$deviance = R$V2[3]
	res$DIC = R$V2[4]
	tmp = 5+res$D - 1
	res$lambda = R$V2[5:tmp]
	tmp = tmp + 1
	res$perc_var0 = R$V2[tmp]
	prev_tmp = tmp+1
	tmp = tmp + res$D
	res$perc_var = R$V2[prev_tmp:tmp]
	prev_tmp = tmp+1
	tmp = tmp + res$D
	res$perc_factor = R$V2[prev_tmp:tmp]
	prev_tmp = tmp+1
	res$perc_residual = R$V2[prev_tmp]

	return(res);
}
