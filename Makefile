CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra
TWOS_COMPLEMENT = -fno-strict-overflow -fwrapv

all: \
	id0001.o id0002.o id0003.o id0004.o id0005.o id0006.o id0007.o id0008.o \
	id0009.o id0010.o id0011.o id0012.o id0013.o id0014.o id0015.o id0016.o \
	id0017.o id0018.o id0019.o id0020.o id0021.o id0022.o id0023.o id0024.o \
	id0025.o id0026.o id0027.o id0028.o id0029.o id0030.o id0031.o id0032.o \
	id0033.o id0034.o id0035.o id0036.o id0037.o id0038.o id0039.o id0040.o \
	id0041.o id0042.o id0043.o id0044.o id0045.o id0046.o id0047.o id0048.o \
	id0049.o id0050.o id0051.o id0052.o id0053.o id0054.o id0055.o id0056.o \
	id0057.o id0058.o id0059.o id0060.o id0061.o id0062.o id0063.o id0064.o

boolean_set.o: lib/boolean_set.c lib/boolean_set.h
	$(CC) $(CFLAGS) -c $< -o $@

divisor_iterator.o: lib/divisor_iterator.c lib/divisor_iterator.h
	$(CC) $(CFLAGS) -c $< -o $@

euler.o: lib/euler.c lib/euler.h
	$(CC) $(CFLAGS) -c $< -o $@

list.o: lib/list.c lib/list.h
	$(CC) $(CFLAGS) -c $< -o $@

lp_string.o: lib/lp_string.c lib/lp_string.h
	$(CC) $(CFLAGS) -c $< -o $@

lp_string_collection.o: lib/lp_string_collection.c lib/lp_string_collection.h
	$(CC) $(CFLAGS) -c $< -o $@

math.o: lib/math.c lib/euler.h
	$(CC) $(CFLAGS) -c $< -o $@

permutation_iterator.o: lib/permutation_iterator.c lib/permutation_iterator.h
	$(CC) $(CFLAGS) -c $< -o $@

prime_list.o: lib/prime_list.c lib/prime_list.h
	$(CC) $(CFLAGS) -c $< -o $@

series.o: lib/series.c lib/series.h
	$(CC) $(CFLAGS) -c $< -o $@

id0001.o: src/id0001.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0002.o: src/id0002.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0003.o: src/id0003.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lm

id0004.o: src/id0004.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0005.o: src/id0005.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0006.o: src/id0006.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	 
id0007.o: src/id0007.c \
	boolean_set.o divisor_iterator.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ boolean_set.o divisor_iterator.o euler.o list.o prime_list.o -lm
	 
id0008.o: src/id0008.c euler.o series.o
	$(CC) $(CFLAGS) $< -o $@ euler.o series.o

id0009.o: src/id0009.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lm

id0010.o: src/id0010.c \
	boolean_set.o divisor_iterator.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ boolean_set.o divisor_iterator.o euler.o list.o prime_list.o -lm

id0011.o: src/id0011.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0012.o: src/id0012.c divisor_iterator.o euler.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o euler.o -lm

id0013.o: src/id0013.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0014.o: src/id0014.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0015.o: src/id0015.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0016.o: src/id0016.c euler.o series.o
	$(CC) $(CFLAGS) $< -o $@ euler.o series.o -lgmp

id0017.o: src/id0017.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0018.o: src/id0018.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0019.o: src/id0019.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0020.o: src/id0020.c euler.o series.o
	$(CC) $(CFLAGS) $< -o $@ euler.o series.o -lgmp

id0021.o: src/id0021.c divisor_iterator.o euler.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o euler.o -lm

id0022.o: src/id0022.c euler.o lp_string.o lp_string_collection.o
	$(CC) $(CFLAGS) $< -o $@ euler.o lp_string.o lp_string_collection.o

id0023.o: src/id0023.c boolean_set.o divisor_iterator.o euler.o list.o
	$(CC) $(CFLAGS) $< -o $@ boolean_set.o divisor_iterator.o euler.o list.o -lm

id0024.o: src/id0024.c euler.o list.o permutation_iterator.o
	$(CC) $(CFLAGS) $< -o $@ euler.o list.o permutation_iterator.o

id0025.o: src/id0025.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lgmp

id0026.o: src/id0026.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0027.o: src/id0027.c \
	boolean_set.o divisor_iterator.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ boolean_set.o divisor_iterator.o euler.o list.o prime_list.o -lm

id0028.o: src/id0028.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0029.o: src/id0029.c divisor_iterator.o euler.o list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o euler.o list.o -lm
	
id0030.o: src/id0030.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lm
	
id0031.o: src/id0031.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0032.o: src/id0032.c permutation_iterator.o euler.o list.o
	$(CC) $(CFLAGS) $< -o $@ permutation_iterator.o euler.o list.o
	
id0033.o: src/id0033.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0034.o: src/id0034.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0035.o: src/id0035.c \
	boolean_set.o divisor_iterator.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ boolean_set.o divisor_iterator.o euler.o list.o prime_list.o -lm

id0036.o: src/id0036.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0037.o: src/id0037.c \
	divisor_iterator.o boolean_set.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o prime_list.o -lm
	
id0038.o: src/id0038.c euler.o list.o
	$(CC) $(CFLAGS) $< -o $@ euler.o list.o
	
id0039.o: src/id0039.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lm
	
id0040.o: src/id0040.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0041.o: src/id0041.c \
	divisor_iterator.o boolean_set.o euler.o list.o permutation_iterator.o \
	prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o permutation_iterator.o prime_list.o -lm
	
id0042.o: src/id0042.c euler.o lp_string.o lp_string_collection.o math.o
	$(CC) $(CFLAGS) $< -o $@ euler.o lp_string.o lp_string_collection.o math.o -lm
	
id0043.o: src/id0043.c euler.o list.o permutation_iterator.o
	$(CC) $(CFLAGS) $< -o $@ euler.o list.o permutation_iterator.o -lm
	
id0044.o: src/id0044.c euler.o math.o
	$(CC) $(CFLAGS) $< -o $@ euler.o math.o -lm
	
id0045.o: src/id0045.c euler.o math.o
	$(CC) $(CFLAGS) $< -o $@ euler.o math.o -lm

id0046.o: src/id0046.c \
	divisor_iterator.o boolean_set.o euler.o list.o math.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o math.o prime_list.o -lm
	
id0047.o: src/id0047.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o

id0048.o: src/id0048.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lgmp
	
id0049.o: src/id0049.c \
	divisor_iterator.o boolean_set.o euler.o list.o permutation_iterator.o \
	prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o permutation_iterator.o prime_list.o -lm
	
id0050.o: src/id0050.c \
 	divisor_iterator.o boolean_set.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o prime_list.o -lm
	
id0051.o: src/id0051.c \
	divisor_iterator.o boolean_set.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o prime_list.o -lm
	
id0052.o: src/id0052.c euler.o list.o permutation_iterator.o
	$(CC) $(CFLAGS) $< -o $@ euler.o list.o permutation_iterator.o -lm
	
id0053.o: src/id0053.c euler.o
	$(CC) $(CFLAGS) $(TWOS_COMPLEMENT) $< -o $@ euler.o
	
id0054.o: src/id0054.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o
	
id0055.o: src/id0055.c euler.o
	$(CC) $(CFLAGS) $(TWOS_COMPLEMENT) $< -o $@ euler.o
	
id0056.o: src/id0056.c euler.o lp_string.o
	$(CC) $(CFLAGS) $< -o $@ euler.o lp_string.o -lgmp -lm
	
id0057.o: src/id0057.c euler.o
	$(CC) $(CFLAGS) $< -o $@ euler.o -lgmp
	
id0058.o: src/id0058.c \
	divisor_iterator.o boolean_set.o euler.o list.o prime_list.o
	$(CC) $(CFLAGS) $< -o $@ divisor_iterator.o boolean_set.o euler.o list.o prime_list.o -lm
	
id0059.o: src/id0059.c euler.o lp_string.o lp_string_collection.o
	$(CC) $(CFLAGS) $< -o $@ euler.o lp_string.o lp_string_collection.o

clean:
	rm -rf *.o
