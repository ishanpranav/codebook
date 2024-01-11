CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra

all: \
	id0001 id0002 id0004 id0005 id0006 id0007 id0008 id0010 id0011 id0012 \
	id0013 id0014 id0015 id0016 id0017

euler: lib/euler.h lib/euler.c
	$(CC) $(CFLAGS) -c lib/euler.c -o $@.o 

euler_math: lib/euler_math.h lib/euler_math.c
	$(CC) $(CFLAGS) -c lib/euler_math.c -o $@.o

id0001: src/id0001.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0002: src/id0002.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0004: src/id0004.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0005: src/id0005.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0006: src/id0006.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o
	 
id0007: src/id0007.c euler euler_math
	$(CC) $(CFLAGS) $< -o $@.o euler.o euler_math.o -lm
	 
id0008: src/id0008.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0010: src/id0010.c euler euler_math
	$(CC) $(CFLAGS) $< -o $@.o euler.o euler_math.o -lm

id0011: src/id0011.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0012: src/id0012.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0013: src/id0013.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0014: src/id0014.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0015: src/id0015.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0016: src/id0016.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lgmp

id0017: src/id0017.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0018: src/id0018.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

clean:
	rm -rf *.o
