[1;34m ###### file: test_error_cds ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_cds
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_cds.o test_error_cds.c
test_error_cds.c: In function ‘main’:
test_error_cds.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_cds.o -o test_error_cds ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_error_cds cmd test.txt
[1;32m [OK] [0;39m ok_log() ./test_error_cds option "-g (genotype_file)" 
[1;32m [OK] [0;39m ok_log() ./test_error_cds missing test.txt
[1;32m [OK] [0;39m ok_log() ./test_error_cds basic test.txt
[1;32m [OK] [0;39m ok_log() ./test_error_cds specific "specific message \!"
[1;32m [OK] [0;39m ok_log() ./test_error_cds autre test.txt

[1;34m ###### file: test_register_cds ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_cds
colorgcc -lm -lpthread   -c -o test_register_cds.o test_register_cds.c
colorgcc test_register_cds.o -o test_register_cds ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt
[1;32m [OK] [0;39m ok_log() ./test_register_cds -h
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m 1 -s 10 -r 0.05
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m 2 -s 10 -r 0.05
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m 3 -s 10 -r 0.05
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -o output.txt
[1;32m [OK] [0;39m ok_log() ./test_register_cds 
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g 
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m 0 
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m -1
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m a
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -m
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -s -1
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -s
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -r 0 
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -r 1 
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -r -1
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -r a
[1;32m [OK] [0;39m ok_log() ./test_register_cds -g input_file.txt -r

