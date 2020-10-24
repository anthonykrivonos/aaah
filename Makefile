CC = gcc
CXX = g++

INCLUDES =

CFLAGS = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g

LDLIBS =

.PHONY: all
all: clean aaah sigaaahction

aaah: aaah.o
sigaaahction: sigaaahction.o

aaah.o: aaah.c
sigaaahction.o: sigaaahction.c

.PHONY: clean
clean:
	rm -f *.o a.out core aaah sigaaahction

