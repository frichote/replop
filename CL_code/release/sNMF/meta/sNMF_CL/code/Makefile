#Version du Makefile utilisant les fonctions avancées de Make.

CFLAGS = -lm -lpthread
LDFLAGS = -g -O3 -Wall -Wextra

CC = gcc

SOURCES_O = $(wildcard src/*/*.c)
SOURCES_M = $(wildcard src/*.c)
OBJECTS_O = $(patsubst src/%.c,obj/%.o,$(SOURCES_O)) 
OBJECTS_M = $(patsubst src/%.c,obj/%.o,$(SOURCES_M)) 

EXECUTABLE = sNMF crossEntropy createDataSet
all: $(SOURCES_O) $(SOURCES_M) $(EXECUTABLE) 
	
sNMF : $(OBJECTS_O) obj/sNMF.o 
	$(CC) $(OBJECTS_O) obj/sNMF.o -o $@ $(CFLAGS) $(LDFLAGS)

createDataSet : $(OBJECTS_O) obj/createDataSet.o 
	$(CC) $(OBJECTS_O) obj/createDataSet.o -o $@ $(CFLAGS) $(LDFLAGS)

crossEntropy : $(OBJECTS_O) obj/crossEntropy.o 
	$(CC) $(OBJECTS_O) obj/crossEntropy.o -o $@ $(CFLAGS) $(LDFLAGS)

obj/%.o: src/%.c  
	$(CC) $(LDFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o obj/*/*.o sNMF crossEntropy createDataSet


