### OPTIONS ####
CFLAGS = -lm -lpthread
LDFLAGS += -g -O3 -Wall -Wextra

# debug mode for LFMM
LDFLAGS += -DDEBUG

##CC = colorgcc
CC = gcc

### DIRECTORIES ####
BIN = bin
LIB = lib
OBJ = obj
SRC = src
MAIN = main

### SOURCES FILES ####
SRC_LAPACK = 	$(wildcard $(SRC)/lapack/*.c)
SRC_TOOLS = 	$(wildcard $(SRC)/bituint/*.c)		\
		$(wildcard $(SRC)/matrix/*.c) 		\
		$(wildcard $(SRC)/nnlsm/*.c) 		\
		$(wildcard $(SRC)/io/*.c) 		\
		$(wildcard $(SRC)/stats/*.c)		
SRC_convert = 	$(wildcard $(SRC)/convert/*.c) 		\
		$(SRC_TOOLS) 
SRC_LFMM = 	$(wildcard $(SRC)/LFMM/*.c) 		\
		$(SRC_TOOLS)
SRC_createDataSet = $(wildcard $(SRC)/createDataSet/*.c) \
		$(SRC_TOOLS) 
SRC_crossEntropy = $(wildcard $(SRC)/crossEntropy/*.c) 	\
		$(SRC_TOOLS)
SRC_sNMF =  	$(wildcard $(SRC)/crossEntropy/*.c) 	\
		$(wildcard $(SRC)/createDataSet/*.c) 	\
		$(wildcard $(SRC)/sNMF/*.c) 		\
		$(SRC_TOOLS)
SRC_pca = 	$(wildcard $(SRC)/pca/*.c) 		\
		$(SRC_TOOLS)
SRC_tracyWidom = $(wildcard $(SRC)/tracyWidom/*.c) 	\
		$(SRC_TOOLS)
SRC_main = 	$(wildcard $(SRC)/main/*.c)

### OBJECTS FILES ###
OBJ_LAPACK = 	$(patsubst $(SRC)/%.c,obj/%.o,$(SRC_LAPACK)) 
OBJ_LFMM = 	$(patsubst $(SRC)/%.c,obj/%.o,$(SRC_LFMM)) 
OBJ_sNMF = 	$(patsubst $(SRC)/%.c,obj/%.o,$(SRC_sNMF)) 
OBJ_convert = 	$(patsubst $(SRC)/%.c,obj/%.o,$(SRC_convert)) 
OBJ_createDataSet = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_createDataSet)) 
OBJ_crossEntropy = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_crossEntropy)) 
OBJ_pca = 	$(patsubst $(SRC)/%.c,obj/%.o,$(SRC_pca)) 
OBJ_tracyWidom =$(patsubst $(SRC)/%.c,obj/%.o,$(SRC_tracyWidom)) 

OBJ_main = $(patsubst $(SRC)/%.c,obj/%.o,$(SRC_main)) 

### HEADER FILES ###
HEADER_LFMM = 	$(patsubst $(SRC)/%.c,$(SRC)/%.h,$(SRC_LFMM))
HEADER_sNMF = 	$(patsubst $(SRC)/%.c,$(SRC)/%.h,$(SRC_sNMF))
HEADER_convert = $(patsubst $(SRC)/%.c,$(SRC)/%.h,$(SRC_convert))
HEADER_createDataSet = $(patsubst $(SRC)/%.c,$(SRC)/%.h,$(SRC_createDataSet))
HEADER_crossEntropy = $(patsubst $(SRC)/%.c,$(SRC)/%.h,$(SRC_crossEntropy))


# EXECUTABLE
EXECUTABLE = 	$(LIB)/lapack.a 	\
		$(BIN)/sNMF		\
		$(BIN)/crossEntropy 	\
		$(BIN)/createDataSet 	\
		$(BIN)/LFMM 		\
		$(BIN)/vcf2geno 	\
		$(BIN)/ancestrymap2geno \
		$(BIN)/ancestrymap2lfmm \
		$(BIN)/ped2geno 	\
		$(BIN)/ped2lfmm 	\
		$(BIN)/lfmm2geno 	\
		$(BIN)/geno2lfmm 	\
		$(BIN)/pca 		\
		$(BIN)/tracyWidom

all: 	$(SRC_LAPACK) 		\
	$(SRC_LFMM) 		\
	$(SRC_sNMF) 		\
	$(SRC_createDataSet) 	\
	$(SRC_crossEntropy) 	\
	$(SRC_convert) 		\
	$(SRC_pca) 		\
	$(SRC_main) 		\
	$(EXECUTABLE) 		\
	$(SRC_tracyWidom)

$(LIB)/lapack.a: $(OBJ_LAPACK)
	ar rcs $@ $^

$(BIN)/LFMM : $(OBJ_LFMM) $(LIB)/lapack.a $(OBJ)/main/main_LFMM.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/pca : $(OBJ_pca) $(LIB)/lapack.a $(OBJ)/main/main_pca.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/tracyWidom : $(OBJ_tracyWidom) $(LIB)/lapack.a $(OBJ)/main/main_tracyWidom.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/sNMF : $(OBJ_sNMF) $(LIB)/lapack.a $(OBJ)/main/main_sNMF.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/createDataSet : $(OBJ_createDataSet) $(OBJ_sNMF) $(LIB)/lapack.a $(OBJ)/main/main_createDataSet.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/crossEntropy : $(OBJ_crossEntropy) $(OBJ_sNMF) $(LIB)/lapack.a $(OBJ)/main/main_crossEntropy.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/vcf2geno : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_vcf2geno.o 
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/ancestrymap2geno : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_ancestrymap2geno.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/ancestrymap2lfmm : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_ancestrymap2lfmm.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/ped2geno : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_ped2geno.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/ped2lfmm : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_ped2lfmm.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/lfmm2geno : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_lfmm2geno.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN)/geno2lfmm : $(OBJ_convert) $(LIB)/lapack.a $(OBJ)/main/main_geno2lfmm.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c 
	$(CC) $(LDFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)/*.o $(OBJ)/*/*.o $(LIB)/* $(BIN)/*

doc:
	doxygen docs/doxygen.cfg
