[1;34m ###### file: test_sort ######
[1;36m # Test files creation
[1;36m # Make [0;39m
rm -f *.o test_sort
colorgcc -lm -lpthread -Wall -Wextra   -c -o test_sort.o test_sort.c
test_sort.c: In function ‘main’:
test_sort.c:70:15: warning: unused parameter ‘argc’ [-Wunused-parameter]
test_sort.c:70:27: warning: unused parameter ‘argv’ [-Wunused-parameter]
colorgcc test_sort.o -o test_sort ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o -lm -lpthread -Wall -Wextra -g -O3 -Wall -Wextra
[1;36m # Tests [0;39m
\033[1;32m [OK] \033[0;39m test file: files/test_K1N1_0.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K1N1_1.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K1N10_0.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K1N10_1.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K1N10_rand.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N10_0.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N10_1.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N10_rand.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N1_0.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N1_1.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N1_rand.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K100N10_rand.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-1.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-2.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-3.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-4.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-5.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-6.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-7.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-8.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-9.txt
\033[1;32m [OK] \033[0;39m test file: files/test_K10N100_rand-10.txt
\033[1;32m [OK] \033[0;39m test file: files/plop.txt

