[1;34m ###### file: test_main_ancestrymap2geno ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ../../../bin/ancestrymap2geno files/N10_M1000.ancestrymap
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/ancestrymap2geno files/N10_M1000.ancestrymap

[1;34m ###### file: test_main_ancestrymap2lfmm ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ../../../bin/ancestrymap2lfmm files/N10_M1000.ancestrymap
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/ancestrymap2lfmm files/N10_M1000.ancestrymap

[1;34m ###### file: test_main_createDataSet ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ../../../bin/createDataSet -g files/N10_M1000.geno -s 1
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/createDataSet -g files/N10_M1000.geno -s 1

[1;34m ###### file: test_main_crossEntropy ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_cl() ../../../bin/createDataSet -g files/N10_M1000.geno -s 1
[1;31m [FAILED] [0;39m ok_cl() ../../../bin/sNMF -g files/N10_M1000_I.geno -s 1 -K 4
[1;31m [FAILED] [0;39m ok_cl() ../../../bin/crossEntropy -g files/N10_M1000.geno -K 4
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/crossEntropy -g files/N10_M1000.geno -K 4

[1;34m ###### file: test_main_geno2lfmm ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ../../../bin/geno2lfmm files/N10_M1000.geno
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/geno2lfmm files/N10_M1000.geno

[1;34m ###### file: test_main_lfmm2geno ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ../../../bin/lfmm2geno files/N10_M1000.lfmm
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/lfmm2geno files/N10_M1000.lfmm

[1;34m ###### file: test_main_LFMM ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
Aborted (core dumped)
[1;31m [FAILED] [0;39m ok_cl() ../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -a -K 4
[1;31m [FAILED] [0;39m ok_valgrind() ../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -a -K 4
Aborted (core dumped)
[1;31m [FAILED] [0;39m ok_cl() ../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -K 4
[1;31m [FAILED] [0;39m ok_valgrind() ../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -K 4

[1;34m ###### file: test_main_ped2geno ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ../../../bin/ped2geno files/N5_M7.ped
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/ped2geno files/N5_M7.ped

[1;34m ###### file: test_main_ped2lfmm ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ../../../bin/ped2lfmm files/N5_M7.ped
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/ped2lfmm files/N5_M7.ped

[1;34m ###### file: test_main_sNMF ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_valgrind() ../../../bin/sNMF -g files/N10_M1000.geno -c -K 5
[1;31m [FAILED] [0;39m ok_valgrind() ../../../bin/sNMF -g files/N10_M1000.geno -c -K 1

[1;34m ###### file: test_main_vcf2geno ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_main_vcf2geno
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_main_vcf2geno.o test_main_vcf2geno.c
test_main_vcf2geno.c:12:45: fatal error: ../../../src/main/main_vcf2geno.h: No such file or directory
compilation terminated.
make: *** [test_main_vcf2geno.o] Error 1
[1;36m # Tests [0;39m

test_dir.sh: 10: cd: can't cd to test_main_pca
[1;34m ###### file: test_main_pca ######
sh: 0: Can't open test_file.sh
