[1;34m ###### file: test_als_F ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_als_F
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_als_F.o test_als_F.c
test_als_F.c: In function ‘main’:
test_als_F.c:30:2: error: unknown type name ‘Memory’
test_als_F.c:45:2: warning: implicit declaration of function ‘allocate_memory’ [-Wimplicit-function-declaration]
test_als_F.c:54:2: warning: passing argument 1 of ‘update_F’ from incompatible pointer type [enabled by default]
../../../src/sNMF/als_F.h:22:6: note: expected ‘sNMF_param’ but argument is of type ‘double *’
test_als_F.c:54:2: error: too many arguments to function ‘update_F’
../../../src/sNMF/als_F.h:22:6: note: declared here
test_als_F.c:56:2: warning: passing argument 1 of ‘update_F’ from incompatible pointer type [enabled by default]
../../../src/sNMF/als_F.h:22:6: note: expected ‘sNMF_param’ but argument is of type ‘double *’
test_als_F.c:56:2: error: too many arguments to function ‘update_F’
../../../src/sNMF/als_F.h:22:6: note: declared here
test_als_F.c:64:2: warning: implicit declaration of function ‘free_memory’ [-Wimplicit-function-declaration]
test_als_F.c:65:2: warning: passing argument 1 of ‘free’ makes pointer from integer without a cast [enabled by default]
/usr/include/stdlib.h:488:13: note: expected ‘void *’ but argument is of type ‘int’
test_als_F.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
make: *** [test_als_F.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_als_F: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_als_F files/R.txt files/Q.txt 10 100 files/K.txt 3 files/out_F1.txt files/out_F2.txt files/out_normalize_F.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_F1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_F
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_F2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_F
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_normalize_F.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_F

[1;34m ###### file: test_als_Q ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_als_Q
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_als_Q.o test_als_Q.c
test_als_Q.c: In function ‘main’:
test_als_Q.c:31:9: error: unknown type name ‘Memory’
test_als_Q.c:49:9: warning: implicit declaration of function ‘allocate_memory’ [-Wimplicit-function-declaration]
test_als_Q.c:60:2: warning: implicit declaration of function ‘F_tF_alpha’ [-Wimplicit-function-declaration]
test_als_Q.c:66:2: warning: implicit declaration of function ‘tF_tX’ [-Wimplicit-function-declaration]
test_als_Q.c:74:2: warning: implicit declaration of function ‘free_memory’ [-Wimplicit-function-declaration]
test_als_Q.c:75:2: warning: passing argument 1 of ‘free’ makes pointer from integer without a cast [enabled by default]
/usr/include/stdlib.h:488:13: note: expected ‘void *’ but argument is of type ‘int’
test_als_Q.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
make: *** [test_als_Q.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_als_Q: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_als_Q files/R.txt files/F.txt 10 100 files/K.txt files/alpha.txt 3 files/out_temp1_1.txt files/out_temp1_2.txt files/out_temp3_1.txt files/out_temp3_2.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_temp1_1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_Q
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_temp1_2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_Q
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_temp3_1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_Q
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_temp3_2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_als_Q

[1;34m ###### file: test_criteria ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_criteria
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_criteria.o test_criteria.c
test_criteria.c: In function ‘main’:
test_criteria.c:29:2: error: unknown type name ‘Memory’
test_criteria.c:46:9: warning: implicit declaration of function ‘allocate_memory’ [-Wimplicit-function-declaration]
test_criteria.c:57:2: warning: passing argument 1 of ‘least_square’ from incompatible pointer type [enabled by default]
../../../src/sNMF/criteria.h:21:8: note: expected ‘sNMF_param’ but argument is of type ‘bituint *’
test_criteria.c:57:2: error: too many arguments to function ‘least_square’
../../../src/sNMF/criteria.h:21:8: note: declared here
test_criteria.c:62:2: warning: implicit declaration of function ‘free_memory’ [-Wimplicit-function-declaration]
test_criteria.c:63:2: warning: passing argument 1 of ‘free’ makes pointer from integer without a cast [enabled by default]
/usr/include/stdlib.h:488:13: note: expected ‘void *’ but argument is of type ‘int’
test_criteria.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
make: *** [test_criteria.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_criteria: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_criteria files/R.txt files/Q.txt files/F.txt 10 100 files/K.txt 3 files/alpha.txt files/out_LS.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_LS.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_criteria

[1;34m ###### file: test_error_nmf ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_nmf
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_nmf.o test_error_nmf.c
test_error_nmf.c:12:41: fatal error: ../../../src/sNMF/error_nmf.h: No such file or directory
compilation terminated.
make: *** [test_error_nmf.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_error_nmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_nmf cmd test.txt 0
description.sh: 1: eval: ./test_error_nmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_nmf option '-g (...)' 0
description.sh: 1: eval: ./test_error_nmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_nmf missing test.txt 0
description.sh: 1: eval: ./test_error_nmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_nmf basic test.txt 0
description.sh: 1: eval: ./test_error_nmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_nmf specific 'Specific message \!' 0
description.sh: 1: eval: ./test_error_nmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_nmf autre test.txt 0

[1;34m ###### file: test_register_snmf ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_snmf
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_snmf.o test_register_snmf.c
test_register_snmf.c: In function ‘main’:
test_register_snmf.c:32:3: warning: passing argument 3 of ‘analyse_param_snmf’ from incompatible pointer type [enabled by default]
../../../src/sNMF/register_snmf.h:28:6: note: expected ‘sNMF_param’ but argument is of type ‘int *’
test_register_snmf.c:32:3: error: too many arguments to function ‘analyse_param_snmf’
../../../src/sNMF/register_snmf.h:28:6: note: declared here
test_register_snmf.c:36:3: warning: passing argument 1 of ‘print_summary_snmf’ makes pointer from integer without a cast [enabled by default]
../../../src/sNMF/print_snmf.h:40:6: note: expected ‘sNMF_param’ but argument is of type ‘int’
test_register_snmf.c:36:3: error: too many arguments to function ‘print_summary_snmf’
../../../src/sNMF/print_snmf.h:40:6: note: declared here
make: *** [test_register_snmf.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -h
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -l
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -a 100 -c 0.01 -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -g output.G -I 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -a 100 -c 0.01 -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -Q inputQ -I 1000
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -a 100 -c -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -g output.G -Q input.Q
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -m 1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -m 2
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -m 3
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -a 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -a -1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -c -1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -c 0
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -c 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -c 1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -e 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -e 0
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -e -1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -i 0
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -i 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -i -1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -s
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -s -1
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -m
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -m 0
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -p
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -p 0
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -q 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -g 
description.sh: 1: eval: ./test_register_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_snmf -x input_file.txt -K 10 -Q 

[1;34m ###### file: test_print_snmf ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_print_snmf
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_print_snmf.o test_print_snmf.c
colorgcc test_print_snmf.o -o test_print_snmf ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_print_snmf] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_print_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_print_snmf
description.sh: 1: eval: ./test_print_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_print_snmf prout1 
description.sh: 1: eval: ./test_print_snmf: not found
[1;31m [FAILED] [0;39m ok_log() ./test_print_snmf prout1 prout2

