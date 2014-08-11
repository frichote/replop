[1;34m ###### file: test_beta ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_beta
colorgcc -lm -lpthread -Wall -Wextra -g   -c -o test_beta.o test_beta.c
test_beta.c: In function ‘main’:
test_beta.c:70:2: warning: implicit declaration of function ‘create_m_beta’ [-Wimplicit-function-declaration]
test_beta.c:76:2: warning: implicit declaration of function ‘create_CCt’ [-Wimplicit-function-declaration]
test_beta.c:80:2: warning: implicit declaration of function ‘create_inv_cov_beta’ [-Wimplicit-function-declaration]
test_beta.c:19:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_beta.o -o test_beta ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -g -O3 -Wall -Wextra
test_beta.o: In function `main':
/home/frichote/replop/CL_code/code/test/LFMM/test_beta/test_beta.c:70: undefined reference to `create_m_beta'
/home/frichote/replop/CL_code/code/test/LFMM/test_beta/test_beta.c:72: undefined reference to `create_m_beta'
/home/frichote/replop/CL_code/code/test/LFMM/test_beta/test_beta.c:80: undefined reference to `create_inv_cov_beta'
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_beta] Error 1
[1;36m # Tests [0;39m
description.sh: 24: description.sh: ./test_beta: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_m_beta1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_beta m_beta p 1
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_m_beta2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_beta m_beta p 2
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_CCt.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_beta CCt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_inv_cov_beta.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_beta inv_cov_beta

[1;34m ###### file: test_error_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error_lfmm.o test_error_lfmm.c
test_error_lfmm.c: In function ‘main’:
test_error_lfmm.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error_lfmm.o -o test_error_lfmm ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_error_lfmm] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_error_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm cmd test.txt 0
description.sh: 1: eval: ./test_error_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm option '-g (...)' 0
description.sh: 1: eval: ./test_error_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm missing test.txt 0
description.sh: 1: eval: ./test_error_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm basic test.txt 0
description.sh: 1: eval: ./test_error_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm specific 'Specific message \!' 0
description.sh: 1: eval: ./test_error_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_error_lfmm autre test.txt 0

[1;34m ###### file: test_register_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_register_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_register_lfmm.o test_register_lfmm.c
test_register_lfmm.c: In function ‘main’:
test_register_lfmm.c:30:3: warning: passing argument 3 of ‘analyse_param_lfmm’ from incompatible pointer type [enabled by default]
../../../src/LFMM/register_lfmm.h:28:6: note: expected ‘LFMM_param’ but argument is of type ‘int *’
test_register_lfmm.c:30:3: error: too many arguments to function ‘analyse_param_lfmm’
../../../src/LFMM/register_lfmm.h:28:6: note: declared here
test_register_lfmm.c:34:3: warning: passing argument 1 of ‘print_summary_lfmm’ makes pointer from integer without a cast [enabled by default]
../../../src/LFMM/print_lfmm.h:39:6: note: expected ‘LFMM_param’ but argument is of type ‘int’
test_register_lfmm.c:34:3: error: too many arguments to function ‘print_summary_lfmm’
../../../src/LFMM/print_lfmm.h:39:6: note: declared here
make: *** [test_register_lfmm.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -h
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -l
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -d 1 -C dic.txt -s 2
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -a -C dic.txt -s 2
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g 
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p 0
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -i
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b 1000
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -C dic.txt
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -C dic.txt
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -L -v cov_file.txt -K 3
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -L 1000 -v cov_file.txt -K 3
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -n -v cov_file.txt -K 3
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -n 1000 -v cov_file.txt -K 3
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -D -v cov_file.txt -K 3
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -D 10 -v cov_file.txt -K 3
description.sh: 1: eval: ./test_register_lfmm: not found
[1;31m [FAILED] [0;39m ok_log() ./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -a

[1;34m ###### file: test_U ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_U
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_U.o test_U.c
test_U.c: In function ‘main’:
test_U.c:66:9: warning: implicit declaration of function ‘create_m_U’ [-Wimplicit-function-declaration]
test_U.c:72:9: warning: implicit declaration of function ‘create_inv_cov_U’ [-Wimplicit-function-declaration]
test_U.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_U.o -o test_U ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
test_U.o: In function `main':
test_U.c:(.text+0x3e6): undefined reference to `create_m_U'
test_U.c:(.text+0x469): undefined reference to `create_m_U'
test_U.c:(.text+0x4c8): undefined reference to `create_inv_cov_U'
test_U.c:(.text+0x527): undefined reference to `create_inv_cov_U'
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_U] Error 1
[1;36m # Tests [0;39m
description.sh: 22: description.sh: ./test_U: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_m_U1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_U
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_m_U2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_U
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_inv_cov_U1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_U
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_inv_cov_U2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_U

[1;34m ###### file: test_V ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_V
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_V.o test_V.c
test_V.c: In function ‘main’:
test_V.c:66:9: warning: implicit declaration of function ‘create_m_V’ [-Wimplicit-function-declaration]
test_V.c:72:9: warning: implicit declaration of function ‘create_inv_cov_V’ [-Wimplicit-function-declaration]
test_V.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_V.o -o test_V ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
test_V.o: In function `main':
test_V.c:(.text+0x3e6): undefined reference to `create_m_V'
test_V.c:(.text+0x469): undefined reference to `create_m_V'
test_V.c:(.text+0x4c8): undefined reference to `create_inv_cov_V'
test_V.c:(.text+0x527): undefined reference to `create_inv_cov_V'
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_V] Error 1
[1;36m # Tests [0;39m
description.sh: 22: description.sh: ./test_V: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_m_V1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_V
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_m_V2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_V
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_inv_cov_V1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_V
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_inv_cov_V2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_V

[1;34m ###### file: test_data_lfmm ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_data_lfmm
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_data_lfmm.o test_data_lfmm.c
test_data_lfmm.c: In function ‘main’:
test_data_lfmm.c:98:2: error: too few arguments to function ‘write_zscore_double’
../../../src/LFMM/data_lfmm.h:179:6: note: declared here
test_data_lfmm.c:100:2: error: too few arguments to function ‘write_zscore_double’
../../../src/LFMM/data_lfmm.h:179:6: note: declared here
test_data_lfmm.c:118:2: warning: passing argument 1 of ‘var_data’ from incompatible pointer type [enabled by default]
../../../src/LFMM/data_lfmm.h:188:8: note: expected ‘LFMM_param’ but argument is of type ‘float *’
test_data_lfmm.c:118:2: warning: passing argument 2 of ‘var_data’ from incompatible pointer type [enabled by default]
../../../src/LFMM/data_lfmm.h:188:8: note: expected ‘LFMM_GS_param’ but argument is of type ‘double *’
test_data_lfmm.c:118:2: error: too many arguments to function ‘var_data’
../../../src/LFMM/data_lfmm.h:188:8: note: declared here
test_data_lfmm.c:120:2: warning: passing argument 1 of ‘var_data’ from incompatible pointer type [enabled by default]
../../../src/LFMM/data_lfmm.h:188:8: note: expected ‘LFMM_param’ but argument is of type ‘float *’
test_data_lfmm.c:120:2: warning: passing argument 2 of ‘var_data’ from incompatible pointer type [enabled by default]
../../../src/LFMM/data_lfmm.h:188:8: note: expected ‘LFMM_GS_param’ but argument is of type ‘double *’
test_data_lfmm.c:120:2: error: too many arguments to function ‘var_data’
../../../src/LFMM/data_lfmm.h:188:8: note: declared here
test_data_lfmm.c:25:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
make: *** [test_data_lfmm.o] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_data_lfmm: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_data_lfmm files/sum.txt files/sum2.txt files/mean.txt files/B.txt files/R.txt files/C.txt files/U.txt files/V.txt files/I.txt 10 3 files/DIC.txt files/out_zscore1.txt files/out_zscore2.txt files/out_R.txt files/out_sum.txt files/out_sum2.txt files/out_mean.txt > files/out_dev_dic.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_sum.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_sum2.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_R.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_mean.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_zscore1.txt_all_1.res': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_zscore1.txt_all_2.res': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_zscore2.txt_1.res': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data_lfmm
Error in read.table(args[1]) : no lines available in input
Calls: as.matrix -> read.table
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

