[1;34m ###### file: test_sort ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_sort
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_sort.o test_sort.c
test_sort.c: In function ‘test_matrix’:
test_sort.c:51:2: error: unknown type name ‘Memory’
test_sort.c:54:2: warning: implicit declaration of function ‘allocate_memory’ [-Wimplicit-function-declaration]
test_sort.c:55:9: warning: passing argument 6 of ‘sortCols’ makes pointer from integer without a cast [enabled by default]
../../../src/nnlsm/sort.h:27:6: note: expected ‘Nnlsm_param’ but argument is of type ‘int’
test_sort.c:61:2: warning: implicit declaration of function ‘free_memory’ [-Wimplicit-function-declaration]
test_sort.c: In function ‘main’:
test_sort.c:70:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
test_sort.c:70:27: warning: unused parameter ‘argv’ [-Wunused-parameter]
make: *** [test_sort.o] Error 1
[1;36m # Tests [0;39m
description.sh: 20: description.sh: ./test_sort: not found

