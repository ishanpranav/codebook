# Licensed under the MIT License.

# Totient Permutation

from math import inf, sqrt
from sympy import primerange
from time import time

MAX_SEARCH = 0.375

minN = -1
minNRPhi = inf
minPrime = int(sqrt(1e7) * (1 - MAX_SEARCH))
maxPrime = int(sqrt(1e7) * (1 + MAX_SEARCH))
start = time()

for p in primerange(minPrime, maxPrime):
    for q in primerange(p):
        n = p * q
        
        if n > 1e7: break
        
        phi = (p - 1) * (q - 1)
        nRPhi = n / phi
        
        if nRPhi >= minNRPhi or sorted(str(n)) != sorted(str(phi)): continue
        
        minN = n
        minNRPhi = nRPhi

print(f"0070{minN:>64}    {time() - start:.6f}")
