from math import inf, log10
from sympy import isprime, primerange
from time import time

MAX_SEARCH = 10000

def math_concat(a, b): return a * pow(10, int(log10(b)) + 1) + b
    
def math_is_prime_pair(a, b): 
    return isprime(math_concat(a, b)) and isprime(math_concat(b, a))

start = time()
primes = list(primerange(2, MAX_SEARCH))
min = inf

for i in range(len(primes)):
    a = primes[i]
    candidates = []
    
    for j in range(i + 1, len(primes)):
        b = primes[j]
        
        if math_is_prime_pair(a, b):
            candidates.append(b)
    
    for j in range(len(candidates)):
        for k in range(j + 1, len(candidates)):
            b = candidates[j]
            c = candidates[k]
            
            if not math_is_prime_pair(b, c): continue
            
            for l in range(k + 1, len(candidates)):
                d = candidates[l]
                
                if not math_is_prime_pair(b, d): continue
                if not math_is_prime_pair(c, d): continue
                 
                for m in range(l + 1, len(candidates)):
                    e = candidates[m]
                    sum = a + b + c + d + e
                    
                    if sum >= min: continue
                    if not math_is_prime_pair(b, e): continue
                    if not math_is_prime_pair(c, e): continue
                    if not math_is_prime_pair(d, e): continue
                    
                    min = sum
    
print(f"0060{min:>64}    {time() - start:.6f}")
