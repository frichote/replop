[1;34m ###### file: test_als_F ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_als_F
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_als_F.o test_als_F.c
test_als_F.c: In function ‘main’:
test_als_F.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_als_F.o -o test_als_F ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_cl() ./test_als_F files/R.txt files/Q.txt 10 100 files/K.txt 3 files/out_F1.txt files/out_F2.txt files/out_normalize_F.txt
[1;32m [OK] [0;39m ok_matrix() ./test_als_F
[1;32m [OK] [0;39m ok_matrix() ./test_als_F
[1;32m [OK] [0;39m ok_matrix() ./test_als_F

[1;34m ###### file: test_als_Q ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_als_Q
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_als_Q.o test_als_Q.c
test_als_Q.c: In function ‘main’:
test_als_Q.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_als_Q.o -o test_als_Q ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_cl() ./test_als_Q files/R.txt files/F.txt 10 100 files/K.txt files/alpha.txt 3 files/out_temp1_1.txt files/out_temp1_2.txt files/out_temp3_1.txt files/out_temp3_2.txt
[1;32m [OK] [0;39m ok_matrix() ./test_als_Q
[1;32m [OK] [0;39m ok_matrix() ./test_als_Q
[1;32m [OK] [0;39m ok_matrix() ./test_als_Q
[1;32m [OK] [0;39m ok_matrix() ./test_als_Q

[1;34m ###### file: test_criteria ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_criteria
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_criteria.o test_criteria.c
test_criteria.c: In function ‘main’:
test_criteria.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_criteria.o -o test_criteria ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_cl() ./test_criteria files/R.txt files/Q.txt files/F.txt 10 100 files/K.txt 3 files/alpha.txt files/out_LS.txt
[1;32m [OK] [0;39m ok_matrix() ./test_criteria

[1;34m ###### file: test_error_nmf ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_nmf
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_nmf.o test_error_nmf.c
test_error_nmf.c: In function ‘main’:
test_error_nmf.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_nmf.o -o test_error_nmf ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_error_nmf cmd test.txt 0
[1;32m [OK] [0;39m ok_log() ./test_error_nmf option '-g (...)' 0
[1;32m [OK] [0;39m ok_log() ./test_error_nmf missing test.txt 0
[1;32m [OK] [0;39m ok_log() ./test_error_nmf basic test.txt 0
[1;32m [OK] [0;39m ok_log() ./test_error_nmf specific 'Specific message \!' 0
[1;32m [OK] [0;39m ok_log() ./test_error_nmf autre test.txt 0

[1;34m ###### file: test_register_snmf ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_snmf
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_snmf.o test_register_snmf.c
colorgcc test_register_snmf.o -o test_register_snmf ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -h
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -l
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -a 100 -c 0.01 -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -f output.F
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -a 100 -c -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -f output.F
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -m 1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -m 2
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -m 3
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -a 
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -a -1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -c -1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -c 0
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -c 
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -c 1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -e 
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -e 0
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -e -1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -i 0
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -i 
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -i -1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -s
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -s -1
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -m
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -m 0
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -p
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -p 0
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -q 
[1;32m [OK] [0;39m ok_log() ./test_register_snmf -g input_file.txt -K 10 -f 

[1;34m ###### file: test_print_snmf ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_print_snmf
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_print_snmf.o test_print_snmf.c
colorgcc test_print_snmf.o -o test_print_snmf ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_print_snmf
[1;32m [OK] [0;39m ok_log() ./test_print_snmf prout1 
[1;32m [OK] [0;39m ok_log() ./test_print_snmf prout1 prout2

