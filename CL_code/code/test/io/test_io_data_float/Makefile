## OPTIONS ####
CFLAGS = -lm -lpthread -Wall -Wextra
LDFLAGS = -g -O3 -Wall -Wextra

CC = colorgcc
## CC = gcc

# src obj
SRC = test_io_data_float.c
OBJ = $(patsubst %.c,%.o,$(SRC))

EXEC = test_io_data_float
all: $(SRC) $(EXEC)

$%.o: $%.c
	$(CC) $(LDFLAGS) -c $< -o $@

test_io_data_float : $(OBJ)
	$(CC) $(OBJ) -o $@ ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o test_io_data_float

