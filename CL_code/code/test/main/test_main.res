[1;34m ###### file: test_main_ancestrymap2geno ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ../../../bin/ancestrymap2geno files/N10_M1000.ancestrymap
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/ancestrymap2geno files/N10_M1000.ancestrymap

[1;34m ###### file: test_main_ancestrymap2lfmm ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ../../../bin/ancestrymap2lfmm files/N10_M1000.ancestrymap
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/ancestrymap2lfmm files/N10_M1000.ancestrymap

[1;34m ###### file: test_main_createDataSet ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ../../../bin/createDataSet -g files/N10_M1000.geno -s 1
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/createDataSet -g files/N10_M1000.geno -s 1

[1;34m ###### file: test_main_crossEntropy ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_cl() ../../../bin/createDataSet -g files/N10_M1000.geno -s 1
[1;32m [OK] [0;39m ok_cl() ../../../bin/sNMF -g files/N10_M1000_I.geno -s 1 -K 4
[1;32m [OK] [0;39m ok_cl() ../../../bin/crossEntropy -g files/N10_M1000.geno -K 4
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/crossEntropy -g files/N10_M1000.geno -K 4

[1;34m ###### file: test_main_geno2lfmm ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ../../../bin/geno2lfmm files/N10_M1000.geno
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/geno2lfmm files/N10_M1000.geno

[1;34m ###### file: test_main_lfmm2geno ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ../../../bin/lfmm2geno files/N10_M1000.lfmm
[1;32m [OK] [0;39m ok_valgrind() ../../../bin/lfmm2geno files/N10_M1000.lfmm

[1;34m ###### file: test_main_LFMM ######
[1;36m # Test files creation
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_cl() ../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -a -K 4
