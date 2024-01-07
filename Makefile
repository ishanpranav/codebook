CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra
LIBM = -lm
TWOS_COMPLEMENT = -fno-strict-overflow -fwrapv

all: \
	id0001

euler: src/euler.h src/euler.c
	$(CC) $(CFLAGS) -c src/euler.c -o $@.o 

id0001: src/id0001.c euler
	$(CC) $(CFLAGS) $< -o $@.o euler.o

clean:
	rm -rf *.o
