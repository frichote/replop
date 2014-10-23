#Version du Makefile utilisant les fonctions avancées de Make.

CFLAGS = -lm -lpthread
LDFLAGS = -g -O4 -Wall -Wextra

CC = gcc

SOURCES = $(wildcard src/*.c) $(wildcard src/in_out/*.c) $(wildcard src/matrix/*.c) $(wildcard src/lapack/*.c)
OBJECTS = $(patsubst src/%.c,obj/%.o,$(SOURCES)) 

EXECUTABLE = LFMM
all: $(SOURCES) $(EXECUTABLE) 
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(CFLAGS) $(LDFLAGS)
obj/%.o: src/%.c  
	$(CC) $(LDFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o obj/lapack/*.o obj/in_out/*.o obj/matrix/*.o LFMM 


