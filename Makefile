CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra
LIBM = -lm

all: \
	id0001 id0002 id0004 id0005 id0006 id0007 id0008 id0010 id0011

euler: src/lib/euler.h src/lib/euler.c
	$(CC) $(CFLAGS) -c src/lib/euler.c -o $@.o 

prime_set: src/lib/prime_set.h src/lib/prime_set.c
	$(CC) $(CFLAGS) -c src/lib/prime_set.c -o $@.o

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
	 
id0007: src/id0007.c euler prime_set
	$(CC) $(CFLAGS) $< -o $@.o euler.o prime_set.o $(LIBM)
	 
id0008: src/id0008.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0010: src/id0010.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o prime_set.o $(LIBM)

id0011: src/id0011.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

clean:
	rm -rf *.o
