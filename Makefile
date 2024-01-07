CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra
LIBM = -lm

all: \
	id0001 id0002 id0003

euler: src/euler.h src/euler.c
	$(CC) $(CFLAGS) -c src/euler.c -o $@.o 

id0001: src/id0001.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0002: src/id0002.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0003: src/id0003.c euler
	$(CC)  $(CFLAGS) $< -o $@.o euler.o -lm
	
clean:
	rm -rf *.o
