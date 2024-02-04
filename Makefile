# Licensed under the MIT License.

A = .a
E = 
RM = rm -rf
AR = ar -r libeuler$(A)

CC = gcc
EXTRAS = -L.
CFLAGS = -O3 -pedantic -std=c99 -Wall -Wextra $(EXTRAS)
TWOS_COMPLEMENT = -fno-strict-overflow -fwrapv

LEULER = -leuler
LGMP = -lgmp
LM = -lm

RECURSE = $(foreach d,$(wildcard $(1:=/*)),$(call RECURSE,$d,$2) $(filter $(subst *,%,$2),$d))

all: \
	libeuler$(A) libleetcode$(A) \
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
	id0074$(E) id0075$(E) id0076$(E) id0077$(E) id0078$(E) id0079$(E) \
	id0080$(E)

libeuler$(A): $(call RECURSE,lib,*.c)
	$(RM) *.o
	$(CC) $(CFLAGS) -c $(call RECURSE,lib,*.c)
	$(AR) *.o
	$(RM) *.o

libleetcode$(A): $(wildcard src/lc*.c)
	$(RM) lc*.o
	$(CC) $(CFLAGS) -c $(wildcard src/lc*.c) $(LM)
	$(RM) lc*.o

id0001$(E): src/id0001.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0002$(E): src/id0002.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0003$(E): src/id0003.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0004$(E): src/id0004.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0005$(E): src/id0005.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0006$(E): src/id0006.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	 
id0007$(E): src/id0007.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	 
id0008$(E): src/id0008.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0009$(E): src/id0009.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0010$(E): src/id0010.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0011$(E): src/id0011.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0012$(E): src/id0012.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0013$(E): src/id0013.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0014$(E): src/id0014.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0015$(E): src/id0015.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0016$(E): src/id0016.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)

id0017$(E): src/id0017.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0018$(E): src/id0018.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0019$(E): src/id0019.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0020$(E): src/id0020.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)

id0021$(E): src/id0021.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0022$(E): src/id0022.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0023$(E): src/id0023.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0024$(E): src/id0024.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0025$(E): src/id0025.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)

id0026$(E): src/id0026.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0027$(E): src/id0027.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0028$(E): src/id0028.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0029$(E): src/id0029.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0030$(E): src/id0030.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0031$(E): src/id0031.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0032$(E): src/id0032.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0033$(E): src/id0033.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0034$(E): src/id0034.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0035$(E): src/id0035.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0036$(E): src/id0036.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0037$(E): src/id0037.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0038$(E): src/id0038.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0039$(E): src/id0039.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0040$(E): src/id0040.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0041$(E): src/id0041.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0042$(E): src/id0042.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0043$(E): src/id0043.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0044$(E): src/id0044.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0045$(E): src/id0045.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0046$(E): src/id0046.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0047$(E): src/id0047.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0048$(E): src/id0048.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)
	
id0049$(E): src/id0049.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0050$(E): src/id0050.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0051$(E): src/id0051.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0052$(E): src/id0052.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0053$(E): src/id0053.c libeuler$(A)
	$(CC) $(CFLAGS) $(TWOS_COMPLEMENT) $< -o $@ $(LEULER) $(LM)
	
id0054$(E): src/id0054.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0055$(E): src/id0055.c libeuler$(A)
	$(CC) $(CFLAGS) $(TWOS_COMPLEMENT) $< -o $@ $(LEULER) $(LM)
	
id0056$(E): src/id0056.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)
	
id0057$(E): src/id0057.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)
	
id0058$(E): src/id0058.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0059$(E): src/id0059.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0060$(E): src/id0060.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0061$(E): src/id0061.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0062$(E): src/id0062.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0063$(E): src/id0063.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0064$(E): src/id0064.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0065$(E): src/id0065.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)

id0066$(E): src/id0066.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM) $(LGMP)

id0068$(E): src/id0068.c libeuler$(A) 
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0069$(E): src/id0069.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0070$(E): src/id0070.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0071$(E): src/id0071.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0072$(E): src/id0072.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0073$(E): src/id0073.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0074$(E): src/id0074.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0075$(E): src/id0075.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0076$(E): src/id0076.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)
	
id0077$(E): src/id0077.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0078$(E): src/id0078.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0079$(E): src/id0079.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LM)

id0080$(E): src/id0080.c libeuler$(A)
	$(CC) $(CFLAGS) $< -o $@ $(LEULER) $(LGMP) $(LM)

clean:
	$(RM) *$(A) *.o
