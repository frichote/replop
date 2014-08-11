[1;34m ###### file: test_cholesky ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_cholesky
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_cholesky.o test_cholesky.c
test_cholesky.c: In function ‘main’:
test_cholesky.c:15:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_cholesky.o -o test_cholesky ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_cholesky] Error 1
[1;36m # Tests [0;39m
description.sh: 19: description.sh: ./test_cholesky: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_N10.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_cholesky files/file_N10.txt 10 files/out_N10.txt
description.sh: 23: description.sh: ./test_cholesky: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_N1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_cholesky files/file_N1.txt 1 files/out_N1.txt

[1;34m ###### file: test_data ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_data
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_data.o test_data.c
test_data.c: In function ‘main’:
test_data.c:56:18: warning: division by zero [-Wdiv-by-zero]
test_data.c:21:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_data.o -o test_data ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_data] Error 1
[1;36m # Tests [0;39m
description.sh: 26: description.sh: ./test_data: not found
[1;31m [FAILED] [0;39m log() ./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_update_N10_M10.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_I_N10_M10.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() ./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt

[1;34m ###### file: test_error ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_error
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_error.o test_error.c
test_error.c: In function ‘main’:
test_error.c:14:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_error.o -o test_error ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_error] Error 1
[1;36m # Tests [0;39m
description.sh: 18: description.sh: ./test_error: not found
[1;31m [FAILED] [0;39m log() ./test_error open test.txt 10 > files/out_open.txt
description.sh: 20: description.sh: ./test_error: not found
[1;31m [FAILED] [0;39m log() ./test_error read test.txt 10 > files/out_read.txt
description.sh: 22: description.sh: ./test_error: not found
[1;31m [FAILED] [0;39m log() ./test_error interne test.txt 10 > files/out_interne.txt
description.sh: 24: description.sh: ./test_error: not found
[1;31m [FAILED] [0;39m log() ./test_error constant test.txt 10 > files/out_constant.txt
description.sh: 26: description.sh: ./test_error: not found
[1;31m [FAILED] [0;39m log() ./test_error nan test.txt 10 > files/out_nan.txt
description.sh: 28: description.sh: ./test_error: not found
[1;31m [FAILED] [0;39m log() ./test_error autre test.txt 10 > files/out_autre.txt

[1;34m ###### file: test_inverse ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_inverse
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_inverse.o test_inverse.c
test_inverse.c: In function ‘main’:
test_inverse.c:18:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_inverse.o -o test_inverse ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_inverse] Error 1
[1;36m # Tests [0;39m
description.sh: 25: description.sh: ./test_inverse: not found
[1;31m [FAILED] [0;39m ok_matrix() cmp inv_N10.txt out_inv1_N10.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp det_N10.txt out_det_N10.txt
description.sh: 31: description.sh: ./test_inverse: not found
[1;31m [FAILED] [0;39m ok_matrix() cmp inv_N1.txt out_inv1_N1.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp det_N1.txt out_det_N1.txt

[1;34m ###### file: test_matrix ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_matrix
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_matrix.o test_matrix.c
test_matrix.c: In function ‘main’:
test_matrix.c:22:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_matrix.o -o test_matrix ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_matrix] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_matrix: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_matrix files/data_N10\_M100.txt 10 100 files/out_dble_sum2_N10\_M100.txt files/out_dble_sum_N10\_M100.txt files/out_cpy_N10\_M100.txt files/trans_double_N10\_M100.txt files/trans_float_N10\_M100.txt files/trans_int_N10\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum2_N10_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum2_N10\_M100.txt files/dble_sum2_N10\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum_N10_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum_N10\_M100.txt files/dble_sum_N10\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_cpy_N10_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_cpy_N10\_M100.txt files/data_N10\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/trans_N10\_M100.txt files/trans_double_N10\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/trans_N10\_M100.txt files/trans_float_N10\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/trans_N10\_M100.txt files/trans_int_N10\_M100.txt
description.sh: 37: description.sh: ./test_matrix: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum2_N1_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum2_N1\_M100.txt files/dble_sum2_N1\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum_N1_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum_N1\_M100.txt files/dble_sum_N1\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_cpy_N1_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_cpy_N1\_M100.txt files/data_N1\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/trans_N1\_M100.txt files/trans_double_N1\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/trans_N1\_M100.txt files/trans_float_N1\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/trans_N1\_M100.txt files/trans_int_N1\_M100.txt
description.sh: 46: description.sh: ./test_matrix: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum2_N1_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum2_N1\_M1.txt files/dble_sum2_N1\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum_N1_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum_N1\_M1.txt files/dble_sum_N1\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_cpy_N1_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_cpy_N1\_M1.txt files/data_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() cmp files/trans_N1\_M1.txt files/trans_double_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() cmp files/trans_N1\_M1.txt files/trans_float_N1\_M1.txt
[1;32m [OK] [0;39m ok_matrix() cmp files/trans_N1\_M1.txt files/trans_int_N1\_M1.txt
description.sh: 55: description.sh: ./test_matrix: not found
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum2_N10_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum2_N10\_M1.txt files/dble_sum2_N10\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_dble_sum_N10_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_dble_sum_N10\_M1.txt files/dble_sum_N10\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_cpy_N10_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_cpy_N10\_M1.txt files/data_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() cmp files/trans_N10\_M1.txt files/trans_double_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() cmp files/trans_N10\_M1.txt files/trans_float_N10\_M1.txt
[1;32m [OK] [0;39m ok_matrix() cmp files/trans_N10\_M1.txt files/trans_int_N10\_M1.txt

[1;34m ###### file: test_normalize ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_normalize
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_normalize.o test_normalize.c
test_normalize.c: In function ‘main’:
test_normalize.c:16:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
colorgcc test_normalize.o -o test_normalize ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
../../../obj/LFMM/data_lfmm.o: In function `lambda':
/home/frichote/replop/CL_code/code/src/LFMM/data_lfmm.c:223: undefined reference to `quantile_Gamma_Distribution'
../../../obj/matrix/rand.o: In function `zscore2pvalue_student':
/home/frichote/replop/CL_code/code/src/matrix/rand.c:317: undefined reference to `Student_t_Distribution'
collect2: ld returned 1 exit status
make: *** [test_normalize] Error 1
[1;36m # Tests [0;39m
description.sh: 1: eval: ./test_normalize: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_normalize  files/data_N10\_M100.txt 10 100 files/out_cov_N10\_M100.txt files/out_norm_N10\_M100.txt files/out2_cov_N10\_M100.txt files/out_mean_N10\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_cov_N10_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_cov_N10\_M100.txt files/cov_N10\_M100.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out2_cov_N10\_M100.txt files/cov_N10\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_norm_N10_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_norm_N10\_M100.txt files/norm_N10\_M100.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_mean_N10_M100.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_mean_N10\_M100.txt files/mean_N10\_M100.txt
description.sh: 1: eval: ./test_normalize: not found
[1;31m [FAILED] [0;39m ok_cl() ./test_normalize  files/data_N10\_M1.txt 10 1 files/out_cov_N10\_M1.txt files/out_norm_N10\_M1.txt files/out2_cov_N10\_M1.txt files/out_mean_N10\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_cov_N10_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_cov_N10\_M1.txt files/cov_N10\_M1.txt
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out2_cov_N10\_M1.txt files/cov_N10\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_norm_N10_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_norm_N10\_M1.txt files/norm_N10\_M1.txt
Error in file(file, "rt") : cannot open the connection
Calls: as.matrix -> read.table -> file
In addition: Warning message:
In file(file, "rt") :
  cannot open file 'files/out_mean_N10_M1.txt': No such file or directory
Execution halted
[1;31m [FAILED] [0;39m ok_matrix() cmp files/out_mean_N10\_M1.txt files/mean_N10\_M1.txt

