#Version du Makefile utilisant les fonctions avancées de Make.

### OPTIONS ####
CFLAGS = -lm -lpthread
LDFLAGS = -g -O3 -Wall -Wextra

CC = colorgcc
## CC = gcc

### SOURCES FILES ####
SOURCES_LAPACK = $(wildcard src/lapack/*.c)
SOURCES_TOOLS = $(wildcard src/bituint/*.c) $(wildcard src/matrix/*.c) $(wildcard src/nnlsm/*.c) $(wildcard src/io/*.c)
SOURCES_LFMM = $(wildcard src/LFMM/*.c) src/LFMM.c $(SOURCES_TOOLS)
SOURCES_sNMF = $(wildcard src/sNMF/*.c) src/sNMF.c $(SOURCES_TOOLS)
SOURCES_createDataSet = $(wildcard src/createDataSet/*.c) $(wildcard src/sNMF/*.c) src/createDataSet.c $(SOURCES_TOOLS) 
SOURCES_crossEntropy = $(wildcard src/crossEntropy/*.c) $(wildcard src/sNMF/*.c) src/crossEntropy.c $(SOURCES_TOOLS)

### OBJECTS FILES ###
OBJECTS_LAPACK = $(patsubst src/%.c,obj/%.o,$(SOURCES_LAPACK)) 
OBJECTS_LFMM = $(patsubst src/%.c,obj/%.o,$(SOURCES_LFMM)) 
OBJECTS_sNMF = $(patsubst src/%.c,obj/%.o,$(SOURCES_sNMF)) 
OBJECTS_createDataSet = $(patsubst src/%.c,obj/%.o,$(SOURCES_createDataSet)) 
OBJECTS_crossEntropy = $(patsubst src/%.c,obj/%.o,$(SOURCES_crossEntropy)) 

### DIRECTORIES ####
BINDIR = bin
LIBDIR = lib


EXECUTABLE = lib/lapack.a bin/sNMF bin/crossEntropy bin/createDataSet bin/LFMM
all: $(SOURCES_LAPACK) $(SOURCES_LFMM) $(SOURCES_sNMF) $(SOURCES_createDataSet) $(SOURCES_crossEntropy) $(EXECUTABLE) 

$(LIBDIR)/lapack.a: $(OBJECTS_LAPACK)
	ar rcs $@ $^

$(BINDIR)/LFMM : $(OBJECTS_LFMM) 
	$(CC) $(OBJECTS_LFMM) $(LIBDIR)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(BINDIR)/sNMF : $(OBJECTS_sNMF) 
	$(CC) $(OBJECTS_sNMF) $(LIBDIR)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(BINDIR)/createDataSet : $(OBJECTS_createDataSet) 
	$(CC) $(OBJECTS_createDataSet) $(LIBDIR)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

$(BINDIR)/crossEntropy : $(OBJECTS_crossEntropy) 
	$(CC) $(OBJECTS_crossEntropy) $(LIBDIR)/lapack.a -o $@ $(CFLAGS) $(LDFLAGS)

obj/%.o: src/%.c  
	$(CC) $(LDFLAGS) -c $< -o $@



clean:
	rm -f obj/*.o obj/*/*.o bin/*

doc:
	doxygen docs/doxygen.cfg

