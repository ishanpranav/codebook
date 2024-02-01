# Licensed under the MIT License.

O = .o
E = .o

CC = gcc
EXTRAS = 
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra $(EXTRAS)
TWOS_COMPLEMENT = -fno-strict-overflow -fwrapv

LM = -lm
LGMP = -lgmp

SIEVE_O = boolean_set$(O) list$(O) sieve$(O)
STRING_COLLECTION_O = list$(O) string_builder$(O) string_collection$(O)
PERMUTATION_ITERATOR_O = comparer$(O) equality_comparer$(O) permutation_iterator$(O)

all: \
	id0001$(E) id0002$(E) id0003$(E) id0004$(E) id0005$(E) id0006$(E) \
	id0007$(E) id0008$(E) id0009$(E) id0010$(E) id0011$(E) id0012$(E) \
	id0013$(E) id0014$(E) id0015$(E) id0016$(E) id0017$(E) id0018$(E) \
	id0019$(E) id0020$(E) id0021$(E) id0022$(E) id0023$(E) id0024$(E) \
	id0025$(E) id0026$(E) id0027$(E) id0028$(E) id0029$(E) id0030$(E) \
	id0031$(E) id0032$(E) id0033$(E) id0034$(E) id0035$(E) id0036$(E) \
	id0037$(E) id0038$(E) id0039$(E) id0040$(E) id0041$(E) id0042$(E) \
	id0043$(E) id0044$(E) id0045$(E) id0046$(E) id0047$(E) id0048$(E) \
	id0049$(E) id0050$(E) id0051$(E) id0052$(E) id0053$(E) id0054$(E) \
	id0055$(E) id0056$(E) id0057$(E) id0058$(E) id0059$(E) id0060$(E) \
	id0061$(E) id0062$(E) id0063$(E) id0064$(E) id0065$(E) id0066$(E) \
	id0068$(E) id0069$(E) id0070$(E) id0071$(E) id0072$(E) id0073$(E) \
	id0074$(E) #id0075$(E) id0076$(E) id0077$(E) id0078$(E) id0079$(E)

djb2_hash$(O): lib/hashes/djb2_hash.c lib/hash.h
	$(CC) $(CFLAGS) -c $< -o $@

pjw_hash$(O): lib/hashes/pjw_hash.c lib/hash.h
	$(CC) $(CFLAGS) -c $< -o $@

sdbm_hash$(O): lib/hashes/sdbm_hash.c lib/hash.h
	$(CC) $(CFLAGS) -c $< -o $@

divisor_primality_test$(O): lib/primality_tests/divisor_primality_test.c
	$(CC) $(CFLAGS) -c $< -o $@
	
miller_rabin_primality_test$(O): \
	lib/primality_tests/miller_rabin_primality_test.c
	$(CC) $(CFLAGS) -c $< -o $@

bubble_sort$(O): lib/sorts/bubble_sort.c lib/sort.h
	$(CC) $(CFLAGS) -c $< -o $@

insertion_sort$(O): lib/sorts/insertion_sort.c lib/sort.h
	$(CC) $(CFLAGS) -c $< -o $@

selection_sort$(O): lib/sorts/selection_sort.c lib/sort.h
	$(CC) $(CFLAGS) -c $< -o $@

boolean_set$(O): lib/boolean_set.c lib/boolean_set.h
	$(CC) $(CFLAGS) -c $< -o $@

comparer$(O): lib/comparer.c lib/comparer.h
	$(CC) $(CFLAGS) -c $< -o $@

euler$(O): lib/euler.c lib/euler.h
	$(CC) $(CFLAGS) -c $< -o $@

equality_comparer$(O): lib/equality_comparer.c lib/equality_comparer.h
	$(CC) $(CFLAGS) -c $< -o $@

factor_iterator$(O): lib/factor_iterator.c lib/factor_iterator.h
	$(CC) $(CFLAGS) -c $< -o $@

list$(O): lib/list.c lib/list.h
	$(CC) $(CFLAGS) -c $< -o $@

math$(O): lib/math.c lib/euler.h
	$(CC) $(CFLAGS) -c $< -o $@

permutation_iterator$(O): lib/permutation_iterator.c lib/permutation_iterator.h
	$(CC) $(CFLAGS) -c $< -o $@

sieve$(O): lib/sieve.c lib/sieve.h
	$(CC) $(CFLAGS) -c $< -o $@

series$(O): lib/series.c lib/series.h
	$(CC) $(CFLAGS) -c $< -o $@

string$(O): lib/string.c lib/string.h
	$(CC) $(CFLAGS) -c $< -o $@

string_builder$(O): lib/string_builder.c lib/string_builder.h
	$(CC) $(CFLAGS) -c $< -o $@

string_collection$(O): lib/string_collection.c lib/string_collection.h
	$(CC) $(CFLAGS) -c $< -o $@

totient$(O): lib/totient.c lib/totient.h
	$(CC) $(CFLAGS) -c $< -o $@
	
id0001$(E): src/id0001.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0002$(E): src/id0002.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0003$(E): src/id0003.c euler$(O) factor_iterator$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) factor_iterator$(O) $(SIEVE_O) $(LM)

id0004$(E): src/id0004.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0005$(E): src/id0005.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0006$(E): src/id0006.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	 
id0007$(E): src/id0007.c euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(SIEVE_O) $(LM)
	 
id0008$(E): src/id0008.c euler$(O) series$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) series$(O)

id0009$(E): src/id0009.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(LM)

id0010$(E): src/id0010.c euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(SIEVE_O) $(LM)

id0011$(E): src/id0011.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0012$(E): src/id0012.c euler$(O) factor_iterator$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) factor_iterator$(O) $(SIEVE_O) $(LM)

id0013$(E): src/id0013.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0014$(E): src/id0014.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0015$(E): src/id0015.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0016$(E): src/id0016.c euler$(O) string$(O) series$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string$(O) series$(O) $(LGMP)

id0017$(E): src/id0017.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0018$(E): src/id0018.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0019$(E): src/id0019.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0020$(E): src/id0020.c euler$(O) string$(O) series$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string$(O) series$(O) $(LGMP)

id0021$(E): src/id0021.c euler$(O) factor_iterator$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) factor_iterator$(O) $(SIEVE_O) $(LM)

id0022$(E): src/id0022.c insertion_sort$(O) selection_sort$(O) bubble_sort$(O) euler$(O) string$(O) $(STRING_COLLECTION_O)
	$(CC) $(CFLAGS) $< -o $@ insertion_sort$(O) selection_sort$(O) bubble_sort$(O) euler$(O) string$(O) $(STRING_COLLECTION_O)

id0023$(E): src/id0023.c euler$(O) factor_iterator$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) factor_iterator$(O) $(SIEVE_O) $(LM)

id0024$(E): src/id0024.c euler$(O) $(PERMUTATION_ITERATOR_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(PERMUTATION_ITERATOR_O)

id0025$(E): src/id0025.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(LGMP)

id0026$(E): src/id0026.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0027$(E): src/id0027.c euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(SIEVE_O) $(LM)

id0028$(E): src/id0028.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0029$(E): src/id0029.c equality_comparer$(O) euler$(O) list$(O)
	$(CC) $(CFLAGS) $< -o $@ equality_comparer$(O) euler$(O) list$(O) $(LM)
	
id0030$(E): src/id0030.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(LM)
	
id0031$(E): src/id0031.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0032$(E): src/id0032.c euler$(O) list$(O) $(PERMUTATION_ITERATOR_O) 
	$(CC) $(CFLAGS) $< -o $@ euler$(O) list$(O) $(PERMUTATION_ITERATOR_O)
	
id0033$(E): src/id0033.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0034$(E): src/id0034.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0035$(E): src/id0035.c euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(SIEVE_O) $(LM)

id0036$(E): src/id0036.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0037$(E): src/id0037.c euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(SIEVE_O) $(LM)
	
id0038$(E): src/id0038.c comparer$(O) euler$(O) string_builder$(O)
	$(CC) $(CFLAGS) $< -o $@ comparer$(O) euler$(O) string_builder$(O)
	
id0039$(E): src/id0039.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LM)
	
id0040$(E): src/id0040.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0041$(E): src/id0041.c miller_rabin_primality_test$(O) euler$(O) list$(O) \
	$(PERMUTATION_ITERATOR_O)
	$(CC) $(CFLAGS) $< -o $@ miller_rabin_primality_test$(O) euler$(O) list$(O) $(PERMUTATION_ITERATOR_O) $(LM)
	
id0042$(E): src/id0042.c euler$(O) math$(O) $(STRING_COLLECTION_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(STRING_COLLECTION_O) $(LM)
	
id0043$(E): src/id0043.c euler$(O) string_builder$(O) $(PERMUTATION_ITERATOR_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string_builder$(O) $(PERMUTATION_ITERATOR_O) $(LM)
	
id0044$(E): src/id0044.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LM)
	
id0045$(E): src/id0045.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LM)

id0046$(E): src/id0046.c miller_rabin_primality_test$(O) euler$(O)
	$(CC) $(CFLAGS) $< -o $@ miller_rabin_primality_test$(O) euler$(O) $(LM)
	
id0047$(E): src/id0047.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)

id0048$(E): src/id0048.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(LGMP)
	
id0049$(E): src/id0049.c equality_comparer$(O) euler$(O) string_builder$(O) \
	permutation_iterator$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ equality_comparer$(O) euler$(O) string_builder$(O) permutation_iterator$(O) $(SIEVE_O) $(LM)
	
id0050$(E): src/id0050.c miller_rabin_primality_test$(O) euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ miller_rabin_primality_test$(O) euler$(O) $(SIEVE_O) $(LM)
	
id0051$(E): src/id0051.c miller_rabin_primality_test$(O) euler$(O) \
	string_builder$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ miller_rabin_primality_test$(O) euler$(O) string_builder$(O) $(SIEVE_O) $(LM)
	
id0052$(E): src/id0052.c euler$(O) string_builder$(O) $(PERMUTATION_ITERATOR_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string_builder$(O) $(PERMUTATION_ITERATOR_O) $(LM)
	
id0053$(E): src/id0053.c euler$(O)
	$(CC) $(CFLAGS) $(TWOS_COMPLEMENT) $< -o $@ euler$(O)
	
id0054$(E): src/id0054.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0055$(E): src/id0055.c euler$(O)
	$(CC) $(CFLAGS) $(TWOS_COMPLEMENT) $< -o $@ euler$(O)
	
id0056$(E): src/id0056.c euler$(O) string$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string$(O) math$(O) $(LGMP) $(LM)
	
id0057$(E): src/id0057.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(LGMP)
	
id0058$(E): src/id0058.c miller_rabin_primality_test$(O) euler$(O)
	$(CC) $(CFLAGS) $< -o $@ miller_rabin_primality_test$(O) euler$(O) $(LM)
	
id0059$(E): src/id0059.c euler$(O) string_builder$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string_builder$(O)

id0060$(E): src/id0060.c miller_rabin_primality_test$(O) euler$(O) math$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ miller_rabin_primality_test$(O) euler$(O) math$(O) $(SIEVE_O) $(LM)

id0061$(E): src/id0061.c euler$(O) list$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) list$(O) math$(O) $(LM)

id0062$(E): src/id0062.c sdbm_hash$(O) comparer$(O) euler$(O) list$(O) string_builder$(O)
	$(CC) $(CFLAGS) $< -o $@ sdbm_hash$(O) comparer$(O) euler$(O) list$(O) string_builder$(O)

id0063$(E): src/id0063.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LM)

id0064$(E): src/id0064.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LM)

id0065$(E): src/id0065.c euler$(O) string$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) string$(O) $(LGMP)

id0066$(E): src/id0066.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LGMP) $(LM)

id0068$(E): src/id0068.c euler$(O) math$(O) $(PERMUTATION_ITERATOR_O) 
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(PERMUTATION_ITERATOR_O) $(LM)

id0069$(E): src/id0069.c euler$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) $(SIEVE_O) $(LM)
	
id0070$(E): src/id0070.c euler$(O) equality_comparer$(O) string_builder$(O) \
	permutation_iterator$(O) $(SIEVE_O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) equality_comparer$(O) string_builder$(O) permutation_iterator$(O) $(SIEVE_O) $(LM)
	
id0071$(E): src/id0071.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0072$(E): src/id0072.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0073$(E): src/id0073.c euler$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O)
	
id0074$(E): src/id0074.c equality_comparer$(O) euler$(O) list$(O)
	$(CC) $(CFLAGS) $< -o $@ equality_comparer$(O) euler$(O) list$(O)
	
id0075$(E): src/id0075.c euler$(O) math$(O)
	$(CC) $(CFLAGS) $< -o $@ euler$(O) math$(O) $(LM)

clean:
	rm -rf *$(O)
