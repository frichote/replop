[1;34m ###### file: test_ancestrymap ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_ancestrymap
colorgcc -lm -lpthread   -c -o test_ancestrymap.o test_ancestrymap.c
colorgcc test_ancestrymap.o -o test_ancestrymap ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_ancestrymap] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N10\_M100.ancestrymap 10 100 files/out2_N10\_M100.lfmm files/out_N10\_M100.geno files/out_N10\_M100.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N10\_M1.ancestrymap 10 1 files/out2_N10\_M1.lfmm files/out_N10\_M1.geno files/out_N10\_M1.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N1\_M1000.ancestrymap 1 1000 files/out2_N1\_M1000.lfmm files/out_N1\_M1000.geno files/out_N1\_M1000.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ancestrymap files/N1\_M1.ancestrymap 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/6.ancestrymap 1 1 files/out2_6.lfmm files/out_6.geno files/out_6.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/donotexist.ancestrymap 1 1 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100_l1-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100_l1-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100_l50-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100_l50-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100_l100-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100_l100-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100.ancestrymap 10 99 files/out2.lfmm files/out.geno files/out.lfmm
description.sh: 1: eval: ./test_ancestrymap: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ancestrymap files/N10_M100.ancestrymap 10 101 files/out2.lfmm files/out.geno files/out.lfmm

[1;34m ###### file: test_geno ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_geno
colorgcc -lm -lpthread   -c -o test_geno.o test_geno.c
colorgcc test_geno.o -o test_geno ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_geno] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok() ./test_geno files/N10\_M100.geno 10 100 files/out_N10\_M100.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok() ./test_geno files/N10\_M1.geno 10 1 files/out_N10\_M1.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok() ./test_geno files/N1\_M1000.geno 1 1000 files/out_N1\_M1000.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok() ./test_geno files/N1\_M1.geno 1 1 files/out_N1\_M1.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/6.geno 1 1 files/out_6.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno donotexist.txt 1 1 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100_l1-9.geno 10 100 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100_l1-11.geno 10 100 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100_l50-9.geno 10 100 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100_l50-11.geno 10 100 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100_l100-9.geno 10 100 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100_l100-11.geno 10 100 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100.geno 10 99 output.geno
description.sh: 1: eval: ./test_geno: not found
[1;31m [FAILED] [0;39m ok_log() ./test_geno files/N10_M100.geno 10 101 output.geno

[1;34m ###### file: test_geno2lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_geno2lfmm
colorgcc -lm -lpthread   -c -o test_geno2lfmm.o test_geno2lfmm.c
colorgcc test_geno2lfmm.o -o test_geno2lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_geno2lfmm] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_geno2lfmm: not found
[1;31m [FAILED] [0;39m ok() ./test_geno2lfmm files/N10\_M100.geno 10 100 files/out_N10\_M100.lfmm
description.sh: 1: eval: ./test_geno2lfmm: not found
[1;31m [FAILED] [0;39m ok() ./test_geno2lfmm files/N10\_M1.geno 10 1 files/out_N10\_M1.lfmm
description.sh: 1: eval: ./test_geno2lfmm: not found
[1;31m [FAILED] [0;39m ok() ./test_geno2lfmm files/N1\_M1000.geno 1 1000 files/out_N1\_M1000.lfmm
description.sh: 1: eval: ./test_geno2lfmm: not found
[1;31m [FAILED] [0;39m ok() ./test_geno2lfmm files/N1\_M1.geno 1 1 files/out_N1\_M1.lfmm

[1;34m ###### file: test_lfmm2geno ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_lfmm2geno
colorgcc -lm -lpthread   -c -o test_lfmm2geno.o test_lfmm2geno.c
colorgcc test_lfmm2geno.o -o test_lfmm2geno ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_lfmm2geno] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_lfmm2geno: not found
[1;31m [FAILED] [0;39m ok() ./test_lfmm2geno files/N10\_M100.lfmm 10 100 files/out_N10\_M100.geno
description.sh: 1: eval: ./test_lfmm2geno: not found
[1;31m [FAILED] [0;39m ok() ./test_lfmm2geno files/N10\_M1.lfmm 10 1 files/out_N10\_M1.geno
description.sh: 1: eval: ./test_lfmm2geno: not found
[1;31m [FAILED] [0;39m ok() ./test_lfmm2geno files/N1\_M1000.lfmm 1 1000 files/out_N1\_M1000.geno
description.sh: 1: eval: ./test_lfmm2geno: not found
[1;31m [FAILED] [0;39m ok() ./test_lfmm2geno files/N1\_M1.lfmm 1 1 files/out_N1\_M1.geno

[1;34m ###### file: test_ped ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_ped
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_ped.o test_ped.c
test_ped.c: In function ‘main’:
test_ped.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_ped.o -o test_ped ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_ped] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m log() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ped files/N5\_M7-2.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
[1;32m [OK] [0;39m log() ./test_ped files/N5\_M7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
[1;32m [OK] [0;39m log() ./test_ped files/N5\_M1.ped 5 1 files/out2_N5\_M1.lfmm files/out_N5\_M1.geno files/out_N5\_M1.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
[1;32m [OK] [0;39m log() ./test_ped files/N1\_M7.ped 1 7 files/out2_N1\_M7.lfmm files/out_N1\_M7.geno files/out_N1\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_ped files/N1\_M1-9.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;31m [FAILED] [0;39m log() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
[1;32m [OK] [0;39m log() ./test_ped files/N1\_M1.ped 1 1 files/out2_N1\_M1.lfmm files/out_N1\_M1.geno files/out_N1\_M1.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/donotexist.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l1-6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l1-7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l1-8.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l3-6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l3-7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l3-8.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l5-6.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l5-7.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5_M7_l5-8.ped 5 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5\_M7.ped 4 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm
description.sh: 1: eval: ./test_ped: not found
[1;31m [FAILED] [0;39m ok_log() ./test_ped files/N5\_M7.ped 6 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm

[1;34m ###### file: test_register_convert ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_convert
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_convert.o test_register_convert.c
colorgcc test_register_convert.o -o test_register_convert ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_register_convert] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_register_convert: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_convert
description.sh: 1: eval: ./test_register_convert: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_convert input.log
description.sh: 1: eval: ./test_register_convert: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_convert input.log output.log
description.sh: 1: eval: ./test_register_convert: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_convert input.log output.log tmp.log

