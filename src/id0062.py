# Licensed under the MIT License.

# Cubic Permutations

from time import time

def math_cubic_permutation() -> int:
    lookup = {}
    max = 1

    while True:
        b = max
        max *= 10
        
        while b < max:
            cb = b * b * b
            key = "".join(sorted(str(cb)))
            
            if key not in lookup:
                matches = []
                lookup[key] = matches
            else:
                matches = lookup[key]
            
            matches.append(cb)
            
            if len(matches) == 5: return min(matches)
            
            b += 1

start = time()
result = math_cubic_permutation()

print(f"0062{result:>64}    {time() - start:.6f}")
