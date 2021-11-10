# C Compiler
CC=gcc

# C Flags
CCFLAGS=-g `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`

# Cross Compiler
ifdef CROSS_COMPILE
	CC=$(CROSS_COMPILE)$(CC)
endif

# main target
out: build/main.o build/window.o
	$(CC) -o build/main build/main.o build/window.o $(CCFLAGS)

build/main.o: src/main.c
	$(CC) -c src/main.c -o build/main.o $(CCFLAGS)

build/window.o: src/window.c src/window.h
	$(CC) -c src/window.c -o build/window.o $(CCFLAGS)

# clean files
clean:
	rm build/*.o
	rm build/main