CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra

all: \
	id0001 id0002 id0004 id0005 id0006 id0007 id0008 id0010 id0011 id0012 \
	id0013 id0014

euler: src/lib/euler.h src/lib/euler.c
	$(CC) $(CFLAGS) -c src/lib/euler.c -o $@.o 

id0001: src/id0001.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0002: src/id0002.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0004: src/id0004.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0005: src/id0005.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0006: src/id0006.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm
	 
id0007: src/id0007.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm
	 
id0008: src/id0008.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0010: src/id0010.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0011: src/id0011.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0012: src/id0012.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o  -lm

id0013: src/id0013.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o  -lm

id0014: src/id0014.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o  -lm

clean:
	rm -rf *.o
