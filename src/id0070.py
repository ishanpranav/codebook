# Licensed under the MIT License.

# Totient Permutation

from math import inf
from sympy import totient, isprime

def permutation_test(left, right):
    if len(left) != len(right): return False
    
    i = 0
    
    while i < len(left) and left[i] == right[i]:
        i += 1
    
    for item in left[i:]:
        if left.count(item) != right.count(item): return False
        
    return True

minNRPhi = inf

for n in range(4, int(1e7)):
    if isprime(n): continue
    
    phi = totient(n)
    nRPhi = n / phi
    
    if nRPhi >= minNRPhi or not permutation_test(str(n), str(phi)): continue
    
    minNRPhi = nRPhi
    
    print(n)
