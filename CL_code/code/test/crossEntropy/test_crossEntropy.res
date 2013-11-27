[1;34m ###### file: test_error_ce ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_ce
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_ce.o test_error_ce.c
test_error_ce.c: In function ‘main’:
test_error_ce.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_ce.o -o test_error_ce ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_error_ce cmd test.txt
[1;32m [OK] [0;39m ok_log() ./test_error_ce option "-g (genotype_file)" 
[1;32m [OK] [0;39m ok_log() ./test_error_ce missing test.txt
[1;32m [OK] [0;39m ok_log() ./test_error_ce basic test.txt
[1;32m [OK] [0;39m ok_log() ./test_error_ce specific "specific message \!"
[1;32m [OK] [0;39m ok_log() ./test_error_ce autre test.txt

[1;34m ###### file: test_register_ce ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_ce
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_ce.o test_register_ce.c
colorgcc test_register_ce.o -o test_register_ce ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file.txt -K 3
[1;32m [OK] [0;39m ok_log() ./test_register_ce -h
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file.txt -K 3 -m 1 -q Q_file.txt -f F_file.txt -i I_file.txt
[1;32m [OK] [0;39m ok_log() ./test_register_ce 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 0
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K a
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -m 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -m 0
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -m -1
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -m a
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -q 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -f 
[1;32m [OK] [0;39m ok_log() ./test_register_ce -g input_file -K 2 -i 

