[1;34m ###### file: test_beta ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_beta
colorgcc -lm -lpthread -Wall -Wextra -g   -c -o test_beta.o test_beta.c
test_beta.c: In function ‘main’:
test_beta.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_beta.o -o test_beta ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_matrix() ./test_beta m_beta p 1
[1;32m [OK] [0;39m ok_matrix() ./test_beta m_beta p 2
[1;32m [OK] [0;39m ok_matrix() ./test_beta CCt
[1;32m [OK] [0;39m ok_matrix() ./test_beta inv_cov_beta

[1;34m ###### file: test_error_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_lfmm.o test_error_lfmm.c
test_error_lfmm.c: In function ‘main’:
test_error_lfmm.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_lfmm.o -o test_error_lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm cmd test.txt 0
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm option '-g (...)' 0
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm missing test.txt 0
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm basic test.txt 0
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm specific 'Specific message \!' 0
[1;32m [OK] [0;39m ok_log() ./test_error_lfmm autre test.txt 0

[1;34m ###### file: test_register_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_lfmm.o test_register_lfmm.c
colorgcc test_register_lfmm.o -o test_register_lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -h
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -l
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -d 1 -C dic.txt -s 2
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -a -C dic.txt -s 2
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g 
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p 0
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -i
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b 1000
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -C dic.txt
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -C dic.txt
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -L -v cov_file.txt -K 3
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -L 1000 -v cov_file.txt -K 3
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -n -v cov_file.txt -K 3
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -n 1000 -v cov_file.txt -K 3
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -D -v cov_file.txt -K 3
[1;32m [OK] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -D 10 -v cov_file.txt -K 3
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -a

[1;34m ###### file: test_U ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_U
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_U.o test_U.c
test_U.c: In function ‘main’:
test_U.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_U.o -o test_U ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_matrix() ./test_U
[1;32m [OK] [0;39m ok_matrix() ./test_U
[1;32m [OK] [0;39m ok_matrix() ./test_U
[1;32m [OK] [0;39m ok_matrix() ./test_U

[1;34m ###### file: test_V ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_V
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_V.o test_V.c
test_V.c: In function ‘main’:
test_V.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_V.o -o test_V ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_matrix() ./test_V
[1;32m [OK] [0;39m ok_matrix() ./test_V
[1;32m [OK] [0;39m ok_matrix() ./test_V
[1;32m [OK] [0;39m ok_matrix() ./test_V

[1;34m ###### file: test_data_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_data_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_data_lfmm.o test_data_lfmm.c
test_data_lfmm.c: In function ‘main’:
test_data_lfmm.c:25:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_data_lfmm.o -o test_data_lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_cl() ./test_data_lfmm files/sum.txt files/sum2.txt files/mean.txt files/B.txt files/R.txt files/C.txt files/U.txt files/V.txt files/I.txt 10 3 files/DIC.txt files/out_zscore1.txt files/out_zscore2.txt files/out_R.txt files/out_sum.txt files/out_sum2.txt files/out_mean.txt > files/out_dev_dic.txt
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
[1;32m [OK] [0;39m ok_matrix() ./test_data_lfmm
Error in scan(file, what, nmax, sep, dec, quote, skip, nlines, na.strings,  : 
  line 2 did not have 8 elements
Calls: as.matrix -> read.table -> scan
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm

[1;34m ###### file: test_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_lfmm.o test_lfmm.c
test_lfmm.c:13:36: fatal error: ../../../src/LFMM/lfmm.h: No such file or directory
compilation terminated.
make: *** [test_lfmm.o] Error 1
[1;36m # Tests [0;39m

