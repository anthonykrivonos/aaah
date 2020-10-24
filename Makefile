CC = gcc
CXX = g++

INCLUDES =

CFLAGS = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g

LDLIBS =

aaah: aaah.o

aaah.o: aaah.c

.PHONY: clean
clean:
	rm -f *.o a.out core aaah

.PHONY: all
all: clean aaah

