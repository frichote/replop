#Version du Makefile utilisant les fonctions avancées de Make.

### OPTIONS ####
CFLAGS = -lm -lpthread
LDFLAGS = -g -O3 -Wall -Wextra

CC = colorgcc
## CC = gcc

### DIRECTORIES ####
BIN = bin
LIB = lib
OBJ = obj
SRC = src

### SOURCES FILES ####
SRC_LAPACK = $(wildcard $(SRC)/lapack/*.c)
SRC_TOOLS = $(wildcard $(SRC)/bituint/*.c) $(wildcard $(SRC)/matrix/*.c) $(wildcard $(SRC)/nnlsm/*.c) $(wildcard $(SRC)/io/*.c)
SRC_LFMM = $(wildcard $(SRC)/LFMM/*.c) $(SRC)/LFMM.c $(SRC_TOOLS)
SRC_sNMF = $(wildcard $(SRC)/sNMF/*.c) $(SRC)/sNMF.c $(SRC_TOOLS)
SRC_createDataSet = $(wildcard $(SRC)/createDataSet/*.c) $(wildcard $(SRC)/sNMF/*.c) $(SRC)/createDataSet.c $(SRC_TOOLS) 
SRC_crossEntropy = $(wildcard $(SRC)/crossEntropy/*.c) $(wildcard $(SRC)/sNMF/*.c) $(SRC)/crossEntropy.c $(SRC_TOOLS)

### OBJECTS FILES ###
OBJ_LAPACK = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_LAPACK)) 
OBJ_LFMM = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_LFMM)) 
OBJ_sNMF = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_sNMF)) 
OBJ_createDataSet = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_createDataSet)) 
OBJ_crossEntropy = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_crossEntropy)) 



EXECUTABLE = $(LIB)/lapack.a $(BIN)/sNMF $(BIN)/crossEntropy $(BIN)/createDataSet $(BIN)/LFMM
all: $(SRC_LAPACK) $(SRC_LFMM) $(SRC_sNMF) $(SRC_createDataSet) $(SRC_crossEntropy) $(EXECUTABLE) 

$(LIB)/lapack.a: $(OBJ_LAPACK)
	ar rcs $@ $^

$(BIN)/LFMM : $(OBJ_LFMM) 
	$(CC) $(OBJ_LFMM) $(LIB)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/sNMF : $(OBJ_sNMF) 
	$(CC) $(OBJ_sNMF) $(LIB)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/createDataSet : $(OBJ_createDataSet) 
	$(CC) $(OBJ_createDataSet) $(LIB)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/crossEntropy : $(OBJ_crossEntropy) 
	$(CC) $(OBJ_crossEntropy) $(LIB)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c  
	$(CC) $(LDFLAGS) -c $< -o $@



clean:
	rm -f $(OBJ)/*.o $(OBJ)/*/*.o $(LIB)/* $

doc:
	doxygen docs/doxygen.cfg

