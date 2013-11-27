[1;34m ###### file: test_io_data_double ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_data_double
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_data_double.o test_io_data_double.c
test_io_data_double.c: In function ‘main’:
test_io_data_double.c:16:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_io_data_double.o -o test_io_data_double ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/factors.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_double files/factors.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100.txt 9 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100.txt 11 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100_l1-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100_l1-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100_l5-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100_l5-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100_l10-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_double files/N10_M100_l10-101.txt 10 100 output.txt

[1;34m ###### file: test_io_data_float ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_data_float
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_data_float.o test_io_data_float.c
test_io_data_float.c: In function ‘main’:
test_io_data_float.c:16:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_io_data_float.o -o test_io_data_float ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_float files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100.txt 9 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100.txt 11 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100_l1-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100_l1-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100_l5-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100_l5-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100_l10-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_float files/N10_M100_l10-101.txt 10 100 output.txt

[1;34m ###### file: test_io_data_int ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_data_int
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_data_int.o test_io_data_int.c
test_io_data_int.c: In function ‘main’:
test_io_data_int.c:16:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_io_data_int.o -o test_io_data_int ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N10\_M100.txt 10 100 files/out_N10\_M100.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N10\_M1.txt 10 1 files/out_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N1\_M1000.txt 1 1000 files/out_N1\_M1000.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() ./test_io_data_int files/N1\_M1.txt 1 1 files/out_N1\_M1.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int donotexist.txt 1 1 output.geno
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100.txt 9 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100.txt 11 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100_l1-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100_l1-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100_l5-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100_l5-101.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100_l10-99.txt 10 100 output.txt
[1;32m [OK] [0;39m ok_log() ./test_io_data_int files/N10_M100_l10-101.txt 10 100 output.txt

[1;34m ###### file: test_io_error ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_error
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_error.o test_io_error.c
colorgcc test_io_error.o -o test_io_error ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_io_error 9 10 10 0
[1;32m [OK] [0;39m ok_log() ./test_io_error 11 10 10 0
[1;32m [OK] [0;39m ok_log() ./test_io_error 10 9 10
[1;32m [OK] [0;39m ok_log() ./test_io_error 10 11 10 0
[1;32m [OK] [0;39m ok_log() ./test_io_error 10 10 10 0
[1;32m [OK] [0;39m ok_log() ./test_io_error 10 10 10 a

[1;34m ###### file: test_io_tools ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_io_tools
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_io_tools.o test_io_tools.c
test_io_tools.c: In function ‘main’:
test_io_tools.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_io_tools.o -o test_io_tools ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_io_tools "fake.geno" "fake" 10 10
[1;32m [OK] [0;39m ok_log() ./test_io_tools files/N10\_M100.geno files/N10\_M100.lfmm 10 100
[1;32m [OK] [0;39m ok_log() ./test_io_tools files/N10\_M1.geno files/N10\_M1.lfmm 10 1
[1;32m [OK] [0;39m ok_log() ./test_io_tools files/N1\_M1000.geno files/N1\_M1000.lfmm 1 1000
[1;32m [OK] [0;39m ok_log() ./test_io_tools files/N1\_M1.geno files/N1\_M1.lfmm 1 1
[1;32m [OK] [0;39m ok_log() ./test_io_tools NULL files/factors.txt 6 21
[1;32m [OK] [0;39m ok_log() ./test_io_tools NULL files/N100_M1000.env 100 1

[1;34m ###### file: test_print_bar ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_print_bar
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_print_bar.o test_print_bar.c
test_print_bar.c: In function ‘main’:
test_print_bar.c:16:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_print_bar.o -o test_print_bar ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_print_bar 1
[1;32m [OK] [0;39m ok_log() ./test_print_bar 10
[1;32m [OK] [0;39m ok_log() ./test_print_bar 74
[1;32m [OK] [0;39m ok_log() ./test_print_bar 75
[1;32m [OK] [0;39m ok_log() ./test_print_bar 76
[1;32m [OK] [0;39m ok_log() ./test_print_bar 1000

