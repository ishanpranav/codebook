# Licensed under the MIT License.

# Prime Summations

from sympy import primerange
from time import time

MAX_SEARCH = 100
term = -1
partitions = [0] * MAX_SEARCH
partitions[0] = 1
start = time()

for p in primerange(MAX_SEARCH):
    for j in range(p, MAX_SEARCH):
        partitions[j] += partitions[j - p]

for n in range(len(partitions)):
    if partitions[n] > 5000:
        term = n        
        break
    
print(f"0077{term:>64}    {time() - start:.6f}")
