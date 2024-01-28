# Licensed under the MIT License.

# Prime Digit Replacements

from sympy import isprime, sieve
from time import time

def mask_list_mask(value: list[int]) -> bool:
    counts = [0] * 10
    
    for it in value:
        counts[it] += 1
        
    for i in range(3):
        if counts[i] < 2: continue
        
        for j in range(len(value)):
            if value[j] != i: continue

            value[j] = -1
            
        return True

    return False

def math_prime_digit_replacement() -> int:
    for p in sieve:
        mask = []
        
        for q in str(p):
            mask.append(int(q))
        
        if not mask_list_mask(mask): continue
        
        length = 0
        first = 0
        
        for i in range(10):
            image = []
            
            for it in mask:
                if it == -1:
                    image.append(i)
                else:
                    image.append(it)
            
            n = 0
            
            for q in image: n = n * 10 + q
            
            if n <= 100000 or not isprime(n): continue
            
            if length == 0: 
                first = n
            
            length += 1
        
        if length == 8: return first
        
    return -1

start = time()
first = math_prime_digit_replacement()

print(f"0051{first:>64}    {time() - start:.6f}")
