[1;34m ###### file: test_io_geno_bituint ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_geno_bituint
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_geno_bituint.o test_io_geno_bituint.c
colorgcc test_io_geno_bituint.o -o test_io_geno_bituint ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_io_geno_bituint files/N10\_M100\_nc1.geno 10 100 1 files/out_N10\_M100\_nc1.geno
[1;32m [OK] [0;39m ./test_io_geno_bituint files/N10\_M100\_nc2.geno 10 100 2 files/out_N10\_M100\_nc2.geno
[1;32m [OK] [0;39m ./test_io_geno_bituint files/N10\_M100\_nc3.geno 10 100 3 files/out_N10\_M100\_nc3.geno
[1;32m [OK] [0;39m ./test_io_geno_bituint files/N10\_M1\_nc2.geno 10 1 2 files/out_N10\_M1\_nc2.geno
[1;32m [OK] [0;39m ./test_io_geno_bituint files/N1\_M1000\_nc2.geno 1 1000 2 files/out_N1\_M1000\_nc2.geno
[1;32m [OK] [0;39m ./test_io_geno_bituint files/N1\_M1\_nc2.geno 1 1 2 files/out_N1\_M1\_nc2.geno
[1;32m [OK] [0;39m ./test_io_geno_bituint files/6.geno 1 1 2 files/out_6.geno

[1;34m ###### file: test_ancestrymap ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_ancestrymap
colorgcc -lm -lpthread   -c -o test_ancestrymap.o test_ancestrymap.c
colorgcc test_ancestrymap.o -o test_ancestrymap ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m ./test_ancestrymap files/6.ancestrymap 1 1 files/out2_6.lfmm files/out_6.geno files/out_6.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/donotexist.ancestrymap 1 1 files/out2.lfmm files/out.geno files/out.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10_M100_l1-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10_M100_l1-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10_M100_l50-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10_M100_l50-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
[1;31m [FAILED] [0;39m ./test_ancestrymap files/N10_M100_l100-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
[1;31m [FAILED] [0;39m ./test_ancestrymap files/N10_M100_l100-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
[1;32m [OK] [0;39m ./test_ancestrymap files/N10_M100.ancestrymap 10 99 files/out2.lfmm files/out.geno files/out.lfmm
[1;31m [FAILED] [0;39m ./test_ancestrymap files/N10_M100.ancestrymap 10 101 files/out2.lfmm files/out.geno files/out.lfmm

[1;34m ###### file: test_geno ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_geno
colorgcc -lm -lpthread   -c -o test_geno.o test_geno.c
colorgcc test_geno.o -o test_geno ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_geno files/N10\_M100.geno 10 100 files/out_N10\_M100.geno
[1;32m [OK] [0;39m ./test_geno files/N10\_M1.geno 10 1 files/out_N10\_M1.geno
[1;32m [OK] [0;39m ./test_geno files/N1\_M1000.geno 1 1000 files/out_N1\_M1000.geno
[1;32m [OK] [0;39m ./test_geno files/N1\_M1.geno 1 1 files/out_N1\_M1.geno
[1;32m [OK] [0;39m ./test_geno files/6.geno 1 1 files/out_6.geno
[1;32m [OK] [0;39m ./test_geno donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100_l1-9.geno 10 100 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100_l1-11.geno 10 100 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100_l50-9.geno 10 100 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100_l50-11.geno 10 100 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100_l100-9.geno 10 100 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100_l100-11.geno 10 100 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100.geno 10 99 output.geno
[1;32m [OK] [0;39m ./test_geno files/N10_M100.geno 10 101 output.geno

[1;34m ###### file: test_geno2lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_geno2lfmm
colorgcc -lm -lpthread   -c -o test_geno2lfmm.o test_geno2lfmm.c
colorgcc test_geno2lfmm.o -o test_geno2lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_geno2lfmm files/N10\_M100.geno 10 100 files/out_N10\_M100.lfmm
[1;32m [OK] [0;39m ./test_geno2lfmm files/N10\_M1.geno 10 1 files/out_N10\_M1.lfmm
[1;32m [OK] [0;39m ./test_geno2lfmm files/N1\_M1000.geno 1 1000 files/out_N1\_M1000.lfmm
[1;32m [OK] [0;39m ./test_geno2lfmm files/N1\_M1.geno 1 1 files/out_N1\_M1.lfmm

[1;34m ###### file: test_lfmm2geno ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_lfmm2geno
colorgcc -lm -lpthread   -c -o test_lfmm2geno.o test_lfmm2geno.c
colorgcc test_lfmm2geno.o -o test_lfmm2geno ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_lfmm2geno files/N10\_M100.lfmm 10 100 files/out_N10\_M100.geno
[1;32m [OK] [0;39m ./test_lfmm2geno files/N10\_M1.lfmm 10 1 files/out_N10\_M1.geno
Error: unable to read file files/N1_M1000.lfmm. It seems that it contains 1 lines instead of 3.

[1;31m [FAILED] [0;39m ./test_lfmm2geno files/N1\_M1000.lfmm 1 1000 files/out_N1\_M1000.geno
[1;32m [OK] [0;39m ./test_lfmm2geno files/N1\_M1.lfmm 1 1 files/out_N1\_M1.geno

[1;34m ###### file: test_ped ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_ped
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_ped.o test_ped.c
colorgcc test_ped.o -o test_ped ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7-2.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1-9.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m ./test_ped files/6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/donotexist.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l1-6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l1-7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l1-8.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l3-6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l3-7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l3-8.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l5-6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l5-7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5_M7_l5-8.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 4 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m ./test_ped files/N5\_M7.ped 6 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm

[1;34m ###### file: test_register_convert ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_convert
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_convert.o test_register_convert.c
colorgcc test_register_convert.o -o test_register_convert ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_register_convert
[1;32m [OK] [0;39m ./test_register_convert input.log
[1;32m [OK] [0;39m ./test_register_convert input.log output.log
[1;32m [OK] [0;39m ./test_register_convert input.log output.log tmp.log

[1;34m ###### file: test_error_cds ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_cds
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_cds.o test_error_cds.c
colorgcc test_error_cds.o -o test_error_cds ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_error_cds cmd test.txt
[1;32m [OK] [0;39m ./test_error_cds option "-g (genotype_file)" 
[1;32m [OK] [0;39m ./test_error_cds missing test.txt
[1;32m [OK] [0;39m ./test_error_cds basic test.txt
[1;32m [OK] [0;39m ./test_error_cds specific "specific message \!"
[1;32m [OK] [0;39m ./test_error_cds autre test.txt

[1;34m ###### file: test_register_cds ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_cds
colorgcc -lm -lpthread   -c -o test_register_cds.o test_register_cds.c
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt
[1;31m [FAILED] [0;39m ./test_register_cds -h
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m 1 -s 10 -r 0.05
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m 2 -s 10 -r 0.05
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m 3 -s 10 -r 0.05
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -o output.txt
[1;31m [FAILED] [0;39m ./test_register_cds 
[1;31m [FAILED] [0;39m ./test_register_cds -g 
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m 0 
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m -1
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m a
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -m
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -s -1
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -s a
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -s
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -r 0 
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -r 1 
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -r -1
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -r a
[1;31m [FAILED] [0;39m ./test_register_cds -g input_file.txt -r

[1;34m ###### file: test_error_ce ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_ce
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_ce.o test_error_ce.c
colorgcc test_error_ce.o -o test_error_ce ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests
[0;39m
[1;32m [OK] [0;39m ./test_error_ce cmd test.txt
[1;32m [OK] [0;39m ./test_error_ce option "-g (genotype_file)" 
[1;32m [OK] [0;39m ./test_error_ce missing test.txt
[1;32m [OK] [0;39m ./test_error_ce basic test.txt
[1;32m [OK] [0;39m ./test_error_ce specific "specific message \!"
[1;32m [OK] [0;39m ./test_error_ce autre test.txt

[1;34m ###### file: test_register_ce ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_ce
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_ce.o test_register_ce.c
colorgcc test_register_ce.o -o test_register_ce ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests
[0;39m
[1;32m [OK] [0;39m ./test_register_ce -g input_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_ce -h
[1;32m [OK] [0;39m ./test_register_ce -g input_file.txt -K 3 -m 1 -q Q_file.txt -f F_file.txt -i I_file.txt
[1;32m [OK] [0;39m ./test_register_ce 
[1;32m [OK] [0;39m ./test_register_ce -g 
[1;32m [OK] [0;39m ./test_register_ce -g input_file 
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 0
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K a
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -m 
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -m 0
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -m -1
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -m a
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -q 
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -f 
[1;32m [OK] [0;39m ./test_register_ce -g input_file -K 2 -i 

[1;34m ###### file: test_io_data_double ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_data_double
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_data_double.o test_io_data_double.c
colorgcc test_io_data_double.o -o test_io_data_double ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_io_data_double files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_double donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100.txt 9 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100.txt 11 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100_l1-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100_l1-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100_l5-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100_l5-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100_l10-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_double files/N10_M100_l10-101.txt 10 100 output.txt

[1;34m ###### file: test_io_data_float ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_data_float
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_data_float.o test_io_data_float.c
colorgcc test_io_data_float.o -o test_io_data_float ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_io_data_float files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_float donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100.txt 9 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100.txt 11 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100_l1-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100_l1-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100_l5-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100_l5-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100_l10-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_float files/N10_M100_l10-101.txt 10 100 output.txt

[1;34m ###### file: test_io_data_int ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_data_int
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_data_int.o test_io_data_int.c
colorgcc test_io_data_int.o -o test_io_data_int ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_io_data_int files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ./test_io_data_int donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100.txt 9 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100.txt 11 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100_l1-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100_l1-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100_l5-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100_l5-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100_l10-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ./test_io_data_int files/N10_M100_l10-101.txt 10 100 output.txt

[1;34m ###### file: test_io_error ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_error
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_error.o test_io_error.c
colorgcc test_io_error.o -o test_io_error ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_io_error 9 10 10 0
[1;32m [OK] [0;39m ./test_io_error 11 10 10 0
[1;32m [OK] [0;39m ./test_io_error 10 9 10
[1;32m [OK] [0;39m ./test_io_error 10 11 10 0
[1;32m [OK] [0;39m ./test_io_error 10 10 10 0
[1;32m [OK] [0;39m ./test_io_error 10 10 10 a

[1;34m ###### file: test_io_tools ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_tools
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_tools.o test_io_tools.c
colorgcc test_io_tools.o -o test_io_tools ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_io_tools "fake.geno" "fake" 10 10
[1;32m [OK] [0;39m ./test_io_tools files/N10\_M100.geno files/N10\_M100.lfmm 10 100
[1;32m [OK] [0;39m ./test_io_tools files/N10\_M1.geno files/N10\_M1.lfmm 10 1
[1;31m [FAILED] [0;39m ./test_io_tools files/N1\_M1000.geno files/N1\_M1000.lfmm 1 1000
[1;32m [OK] [0;39m ./test_io_tools files/N1\_M1.geno files/N1\_M1.lfmm 1 1

[1;34m ###### file: test_beta ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_beta
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_beta.o test_beta.c
colorgcc test_beta.o -o test_beta ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_beta m_beta p 1
[1;31m [FAILED] [0;39m ./test_beta m_beta p 2
[1;31m [FAILED] [0;39m ./test_beta CCt
[1;31m [FAILED] [0;39m ./test_beta inv_cov_beta

[1;34m ###### file: test_error_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_lfmm.o test_error_lfmm.c
colorgcc test_error_lfmm.o -o test_error_lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ./test_error_lfmm cmd test.txt 0
[1;31m [FAILED] [0;39m ./test_error_lfmm option '-g (...)' 0
[1;31m [FAILED] [0;39m ./test_error_lfmm missing test.txt 0
[1;31m [FAILED] [0;39m ./test_error_lfmm basic test.txt 0
[1;31m [FAILED] [0;39m ./test_error_lfmm specific 'Specific message \!' 0
[1;32m [OK] [0;39m ./test_error_lfmm autre test.txt 0

[1;34m ###### file: test_register_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_lfmm.o test_register_lfmm.c
colorgcc test_register_lfmm.o -o test_register_lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10
[1;32m [OK] [0;39m ./test_register_lfmm -h
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -d 1 -C dic.txt
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -a -C dic.txt
[1;32m [OK] [0;39m ./test_register_lfmm -
[1;32m [OK] [0;39m ./test_register_lfmm -g 
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p 0
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -i
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b 1000
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -C dic.txt
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -C dic.txt
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -L -v cov_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -L 1000 -v cov_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -n -v cov_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -n 1000 -v cov_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -D -v cov_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -D 10 -v cov_file.txt -K 3
[1;32m [OK] [0;39m ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -a

[1;34m ###### file: test_U ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_U
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_U.o test_U.c
colorgcc test_U.o -o test_U ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_U
[1;32m [OK] [0;39m ./test_U
[1;32m [OK] [0;39m ./test_U
[1;32m [OK] [0;39m ./test_U

[1;34m ###### file: test_V ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_V
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_V.o test_V.c
colorgcc test_V.o -o test_V ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_V
[1;32m [OK] [0;39m ./test_V
[1;32m [OK] [0;39m ./test_V
[1;32m [OK] [0;39m ./test_V

[1;34m ###### file: test_cholesky ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_cholesky
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_cholesky.o test_cholesky.c
colorgcc test_cholesky.o -o test_cholesky ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_cholesky files/file_N10.txt 10 files/out_N10.txt
[1;32m [OK] [0;39m ./test_cholesky files/file_N1.txt 1 files/out_N1.txt

[1;34m ###### file: test_data ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_data
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_data.o test_data.c
colorgcc test_data.o -o test_data ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt
[1;32m [OK] [0;39m ./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt
[1;32m [OK] [0;39m ./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt

[1;34m ###### file: test_error ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error.o test_error.c
colorgcc test_error.o -o test_error ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ./test_error open test.txt 10 > files/out_open.txt
[1;32m [OK] [0;39m ./test_error read test.txt 10 > files/out_read.txt
[1;32m [OK] [0;39m ./test_error interne test.txt 10 > files/out_interne.txt
[1;32m [OK] [0;39m ./test_error constant test.txt 10 > files/out_constant.txt
[1;32m [OK] [0;39m ./test_error nan test.txt 10 > files/out_nan.txt
[1;32m [OK] [0;39m ./test_error autre test.txt 10 > files/out_autre.txt

[1;34m ###### file: test_inverse ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_inverse
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_inverse.o test_inverse.c
colorgcc test_inverse.o -o test_inverse ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m cmp inv_N10.txt out_inv1_N10.txt
[1;32m [OK] [0;39m cmp inv_N10.txt out_inv2_N10.txt
[1;32m [OK] [0;39m cmp det_N10.txt out_det_N10.txt
[1;32m [OK] [0;39m cmp inv_N1.txt out_inv1_N1.txt
[1;32m [OK] [0;39m cmp inv_N1.txt out_inv2_N1.txt
[1;32m [OK] [0;39m cmp det_N1.txt out_det_N1.txt

[1;34m ###### file: test_matrix ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_matrix
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_matrix.o test_matrix.c
colorgcc test_matrix.o -o test_matrix ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m cmp files/out_dble_sum2_N10\_M100.txt files/dble_sum2_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum_N10\_M100.txt files/dble_sum_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/out_cpy_N10\_M100.txt files/data_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/trans_N10\_M100.txt files/trans_double_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/trans_N10\_M100.txt files/trans_float_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/trans_N10\_M100.txt files/trans_int_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum2_N1\_M100.txt files/dble_sum2_N1\_M100.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum_N1\_M100.txt files/dble_sum_N1\_M100.txt
[1;32m [OK] [0;39m cmp files/out_cpy_N1\_M100.txt files/data_N1\_M100.txt
[1;32m [OK] [0;39m cmp files/trans_N1\_M100.txt files/trans_double_N1\_M100.txt
[1;32m [OK] [0;39m cmp files/trans_N1\_M100.txt files/trans_float_N1\_M100.txt
[1;32m [OK] [0;39m cmp files/trans_N1\_M100.txt files/trans_int_N1\_M100.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum2_N1\_M1.txt files/dble_sum2_N1\_M1.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum_N1\_M1.txt files/dble_sum_N1\_M1.txt
[1;32m [OK] [0;39m cmp files/out_cpy_N1\_M1.txt files/data_N1\_M1.txt
[1;32m [OK] [0;39m cmp files/trans_N1\_M1.txt files/trans_double_N1\_M1.txt
[1;32m [OK] [0;39m cmp files/trans_N1\_M1.txt files/trans_float_N1\_M1.txt
[1;32m [OK] [0;39m cmp files/trans_N1\_M1.txt files/trans_int_N1\_M1.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum2_N10\_M1.txt files/dble_sum2_N10\_M1.txt
[1;32m [OK] [0;39m cmp files/out_dble_sum_N10\_M1.txt files/dble_sum_N10\_M1.txt
[1;32m [OK] [0;39m cmp files/out_cpy_N10\_M1.txt files/data_N10\_M1.txt
[1;32m [OK] [0;39m cmp files/trans_N10\_M1.txt files/trans_double_N10\_M1.txt
[1;32m [OK] [0;39m cmp files/trans_N10\_M1.txt files/trans_float_N10\_M1.txt
[1;32m [OK] [0;39m cmp files/trans_N10\_M1.txt files/trans_int_N10\_M1.txt

[1;34m ###### file: test_normalize ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_normalize
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_normalize.o test_normalize.c
colorgcc test_normalize.o -o test_normalize ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m cmp files/out_cov_N10\_M100.txt files/cov_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/out_norm_N10\_M100.txt files/norm_N10\_M100.txt
[1;32m [OK] [0;39m cmp files/out_cov_N10\_M1.txt files/cov_N10\_M1.txt
[1;32m [OK] [0;39m cmp files/out_norm_N10\_M1.txt files/norm_N10\_M1.txt

