[1;34m ###### file: test_error_ce ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_ce
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_ce.o test_error_ce.c
test_error_ce.c: In function ‘main’:
test_error_ce.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_ce.o -o test_error_ce ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_error_ce] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_error_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_ce cmd test.txt
description.sh: 1: eval: ./test_error_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_ce option "-g (genotype_file)" 
description.sh: 1: eval: ./test_error_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_ce missing test.txt
description.sh: 1: eval: ./test_error_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_ce basic test.txt
description.sh: 1: eval: ./test_error_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_ce specific "specific message \!"
description.sh: 1: eval: ./test_error_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_ce autre test.txt

[1;34m ###### file: test_register_ce ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_ce
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_ce.o test_register_ce.c
colorgcc test_register_ce.o -o test_register_ce ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_register_ce] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file.txt -K 3
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -h
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file.txt -K 3 -m 1 -q Q_file.txt -g G_file.txt -i I_file.txt
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 0
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K a
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -m 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -m 0
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -m -1
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -m a
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -q 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -g 
description.sh: 1: eval: ./test_register_ce: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_ce -x input_file -K 2 -i 

