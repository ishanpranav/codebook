CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra

all: \
	id0001 id0002 id0003 id0004 id0005 id0006 id0007 id0008 id0009 id0010 \
	id0011 id0012 id0013 id0014 id0015 id0016 id0017 id0018 id0019 id0020 \
	id0021

euler: lib/euler.c lib/euler.h
	$(CC) $(CFLAGS) -c $< -o $@.o 

euler_math: lib/euler_math.c lib/euler_math.h
	$(CC) $(CFLAGS) -c $< -o $@.o

series: lib/series.c lib/series.h
	$(CC) $(CFLAGS) -c $< -o $@.o

id0001: src/id0001.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0002: src/id0002.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0003: src/id0003.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

id0004: src/id0004.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0005: src/id0005.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0006: src/id0006.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o
	 
id0007: src/id0007.c euler euler_math
	$(CC) $(CFLAGS) $< -o $@.o euler.o euler_math.o -lm
	 
id0008: src/id0008.c euler series
	$(CC) $(CFLAGS) $< -o $@.o euler.o series.o

id0009: src/id0009.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

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

id0016: src/id0016.c euler series
	$(CC) $(CFLAGS) $< -o $@.o euler.o series.o -lgmp

id0017: src/id0017.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0018: src/id0018.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0019: src/id0019.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

id0020: src/id0020.c euler series
	$(CC) $(CFLAGS) $< -o $@.o euler.o series.o -lgmp

id0021: src/id0021.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o -lm

clean:
	rm -rf *.o
