#!/bin/sh
#
# by E. Frichot
#
# file: vcf2geno
#
# functions:
# 	vcf2geno
#
# command line:
# ./test_vcf2geno input N M removed output snp_file removed_file
#
# exec vcf2geno
#

. ../../meta.sh

# OK
ok_cl "./test_vcf2geno files/R.vcf 7 5 2 files/R.geno files/R.snp files/R.removed"
log "./test_vcf2geno" files/R.geno files/ref.geno
log "./test_vcf2geno" files/R.snp files/ref.snp
log "./test_vcf2geno" files/R.removed files/ref.removed
ok_cl "./test_vcf2geno files/nocom.vcf 7 5 2 files/R.geno files/R.snp files/R.removed"

# error
ok_log "./test_vcf2geno files/nogenotypes.vcf 7 5 2 out.geno out.snp out.removed" files/ref_nogeno.log
ok_log "./test_vcf2geno files/noind.vcf 7 5 2 out.geno out.snp out.removed" files/ref_noind.log
ok_log "./test_vcf2geno files/doublepoint.vcf 7 5 2 out.geno out.snp out.removed" files/ref_dp.log
ok_log "./test_vcf2geno files/6-1.vcf 7 5 2 out.geno out.snp out.removed" files/ref_6-1.log
ok_log "./test_vcf2geno files/6-2.vcf 7 5 2 out.geno out.snp out.removed" files/ref_6-2.log

# error: number of columns
ok_log "./test_vcf2geno files/l1-6.vcf 7 5 2 out.geno out.snp out.removed" files/ref_l1-6.log
ok_log "./test_vcf2geno files/l1-8.vcf 7 5 2 out.geno out.snp out.removed" files/ref_l1-8.log
ok_log "./test_vcf2geno files/l3-6.vcf 7 5 2 out.geno out.snp out.removed" files/ref_l3-6.log
ok_log "./test_vcf2geno files/l3-8.vcf 7 5 2 out.geno out.snp out.removed" files/ref_l3-8.log
ok_log "./test_vcf2geno files/l5-6.vcf 7 5 2 out.geno out.snp out.removed" files/ref_l5-6.log
ok_log "./test_vcf2geno files/l5-8.vcf 7 5 2 out.geno out.snp out.removed" files/ref_l5-8.log

# error: number of lines
ok_log "./test_vcf2geno files/R.vcf 7 4 2 out.geno out.snp out.removed" files/ref_l4.log
ok_log "./test_vcf2geno files/R.vcf 7 6 2 out.geno out.snp out.removed" files/ref_l6.log
