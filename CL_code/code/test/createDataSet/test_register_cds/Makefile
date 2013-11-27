## OPTIONS ####
CFLAGS = -lm -lpthread
LDFLAGS = -g -O3 -Wall -Wextra

CC = colorgcc
## CC = gcc

# src obj
SRC = test_register_cds.c
OBJ = $(patsubst %.c,%.o,$(SRC))

EXEC = test_register_cds
all: $(SRC) $(EXEC)

$%.o: $%.c
	$(CC) $(LDFLAGS) -c $< -o $@

test_register_cds : $(OBJ)
	$(CC) $(OBJ) -o $@ ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o test_register_cds

