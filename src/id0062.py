# Licensed under the MIT License.

# Cubic Permutations

from itertools import permutations
from math import isclose

def math_cubic_permutation() -> int:
    n = 1

    while True:
        result = n * n * n
        digits = []
        k = result
        
        while k > 0:
            digits.append(k % 10)
            k //= 10
        
        count = 0
        found = set()
        
        for permutation in permutations(digits):
            if permutation[0] == 0: continue
            
            k = 0
            
            for digit in permutation:
                k = 10 * k + digit
                
            found.add(k)
            
        for k in found:
            k = k ** (1/3)
            
            if isclose(k, round(k)):
                count += 1
        
        if count == 3:
            print(result, count)
            
        if count == 5:
            return result
                
        n += 1

min = math_cubic_permutation()

print(min)
