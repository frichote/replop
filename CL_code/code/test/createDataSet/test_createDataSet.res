[1;34m ###### file: test_error_cds ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_cds
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_cds.o test_error_cds.c
test_error_cds.c: In function ‘main’:
test_error_cds.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_cds.o -o test_error_cds ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_error_cds] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_error_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_cds cmd test.txt
description.sh: 1: eval: ./test_error_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_cds option "-g (genotype_file)" 
description.sh: 1: eval: ./test_error_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_cds missing test.txt
description.sh: 1: eval: ./test_error_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_cds basic test.txt
description.sh: 1: eval: ./test_error_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_cds specific "specific message \!"
description.sh: 1: eval: ./test_error_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_cds autre test.txt

[1;34m ###### file: test_register_cds ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_cds
colorgcc -lm -lpthread   -c -o test_register_cds.o test_register_cds.c
test_register_cds.c: In function ‘main’:
test_register_cds.c:30:2: warning: passing argument 3 of ‘analyse_param_cds’ from incompatible pointer type [enabled by default]
../../../src/createDataSet/register_cds.h:22:6: note: expected ‘long long int *’ but argument is of type ‘int *’
test_register_cds.c:30:2: warning: passing argument 4 of ‘analyse_param_cds’ from incompatible pointer type [enabled by default]
../../../src/createDataSet/register_cds.h:22:6: note: expected ‘double *’ but argument is of type ‘long long int *’
test_register_cds.c:30:2: warning: passing argument 5 of ‘analyse_param_cds’ from incompatible pointer type [enabled by default]
../../../src/createDataSet/register_cds.h:22:6: note: expected ‘char *’ but argument is of type ‘double *’
test_register_cds.c:30:2: error: too many arguments to function ‘analyse_param_cds’
../../../src/createDataSet/register_cds.h:22:6: note: declared here
test_register_cds.c:33:2: error: incompatible type for argument 5 of ‘print_summary_cds’
../../../src/createDataSet/print_cds.h:27:6: note: expected ‘char *’ but argument is of type ‘double’
test_register_cds.c:33:2: error: too many arguments to function ‘print_summary_cds’
../../../src/createDataSet/print_cds.h:27:6: note: declared here
make: *** [test_register_cds.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -h
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m 1 -s 10 -r 0.05
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m 2 -s 10 -r 0.05
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m 3 -s 10 -r 0.05
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -o output.txt
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds 
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x 
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m 0 
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m -1
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m a
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -m
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -s -1
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -s
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -r 0 
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -r 1 
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -r -1
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -r a
description.sh: 1: eval: ./test_register_cds: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_cds -x input_file.txt -r

