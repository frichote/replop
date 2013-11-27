### OPTIONS ####
CFLAGS = -lm -lpthread
LDFLAGS = -g -O3 -Wall -Wextra

CC = colorgcc
## CC = gcc

# src obj
SRC = $main.c
OBJ = \$(patsubst %.c,%.o,\$(SRC))

EXEC = $main
all: \$(SRC) \$(EXEC)

\$%.o: \$%.c
        \$(CC) \$(LDFLAGS) -c \$< -o \$@

$main : \$(OBJ)
        \$(CC) \$(OBJ) -o \$@ ../../src/$dir/$file.o \$(CFLAGS) \$(LDFLAGS)


