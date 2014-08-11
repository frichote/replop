[1;34m ###### file: test_io_geno_bituint ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_geno_bituint
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_geno_bituint.o test_io_geno_bituint.c
test_io_geno_bituint.c: In function ‘main’:
test_io_geno_bituint.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_io_geno_bituint.o -o test_io_geno_bituint ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_io_geno_bituint] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_and_log() ./test_io_geno_bituint files/N10\_M100\_nc2.geno 10 100 2 files/out_N10\_M100\_nc2.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_and_log() ./test_io_geno_bituint files/N10\_M100\_nc3.geno 10 100 3 files/out_N10\_M100\_nc3.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_and_log() ./test_io_geno_bituint files/N10\_M100\_nc4.geno 10 100 4 files/out_N10\_M100\_nc4.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_and_log() ./test_io_geno_bituint files/N10\_M1\_nc3.geno 10 1 3 files/out_N10\_M1\_nc3.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_and_log() ./test_io_geno_bituint files/N1\_M1000\_nc3.geno 1 1000 3 files/out_N1\_M1000\_nc3.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_and_log() ./test_io_geno_bituint files/N1\_M1\_nc3.geno 1 1 3 files/out_N1\_M1\_nc3.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/6.geno 1 1 2 files/out_6.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint donotexist.txt 1 1 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_l1-9.geno 10 100 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_l1-11.geno 10 100 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_l50-9.geno 10 100 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_l50-11.geno 10 100 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_l100-9.geno 10 100 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_l100-11.geno 10 100 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_nc3.geno 10 99 3 output.geno
description.sh: 1: eval: ./test_io_geno_bituint: not found
[1;31m [FAILED] [0;39m ok_log() ./test_io_geno_bituint files/N10_M100_nc3.geno 10 101 3 output.geno

