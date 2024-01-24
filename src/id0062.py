# Licensed under the MIT License.

# Cubic Permutations

from itertools import permutations
from time import time

def math_cubic_permutation() -> int:
    lookup = {}
    max = 1

    while True:
        b = max
        max *= 10
        
        while b < max:
            cb = b * b * b
            digits = "".join(sorted(str(cb)))
            
            if digits not in lookup.keys():
                matches = set()
                lookup[digits] = matches
            else:
                matches = lookup[digits]
            
            matches.add(cb)
            
            if len(matches) == 5:
                return min(matches)
            
            b += 1

print(math_cubic_permutation())
