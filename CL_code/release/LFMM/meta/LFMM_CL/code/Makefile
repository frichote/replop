#Version du Makefile utilisant les fonctions avancées de Make.

CFLAGS = -lm -lpthread
LDFLAGS = -g -O3 -Wall -Wextra

CC = gcc

SOURCES_O = $(wildcard src/*/*.c)
SOURCES_M = $(wildcard src/*.c)
OBJECTS_O = $(patsubst src/%.c,obj/%.o,$(SOURCES_O)) 
OBJECTS_M = $(patsubst src/%.c,obj/%.o,$(SOURCES_M)) 

EXECUTABLE = LFMM
all: $(SOURCES_O) $(SOURCES_M) $(EXECUTABLE) 
	
LFMM : $(OBJECTS_O) obj/LFMM.o 
	$(CC) $(OBJECTS_O) obj/LFMM.o -o $@ $(CFLAGS) $(LDFLAGS)

obj/%.o: src/%.c  
	$(CC) $(LDFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o obj/*/*.o LFMM


