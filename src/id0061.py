# Licensed under the MIT License.

# Cyclic Figurate Numbers

from math import sqrt
from time import time

def math_is_cyclic(a: int, b: int) -> bool: 
    return a != b and a // 100 == b % 100

def math_is_polygonal(s: int, x: int) -> bool:
    sM2 = s - 2
    sM4 = sM2 - 2
    term = (sqrt(8 * sM2 * x + sM4 * sM4) + sM4) / (2 * sM2)

    return term == int(term)

def math_is_octagonal_or_smaller_polygonal(x: int) -> bool:
    for s in range(3, 6):
        if math_is_polygonal(s, x): return True
    
    return math_is_polygonal(7, x) or math_is_polygonal(8, x)

def math_is_permuted_polygonal(values: list) -> bool:
    flags = {}
    
    for i in range(3, 9):
        flags[i] = False
        
    for x in values:
        for s in range(8, 2, -1):
            if not math_is_polygonal(s, x): continue
            
            flags[s] = True
            break
            
    return all(flags.values())
    
def math_cyclic_polygonal_sum(polygonals: list[int]) -> int:
    for a in polygonals:
        for b in polygonals:
            if not math_is_cyclic(a, b): continue
            
            for c in polygonals:
                if not math_is_cyclic(b, c): continue
                
                for d in polygonals: 
                    if not math_is_cyclic(c, d): continue
                    
                    for e in polygonals: 
                        if not math_is_cyclic(d, e): continue
                        
                        for f in polygonals:
                            if not math_is_cyclic(e, f): continue
                            if not math_is_cyclic(f, a): continue
                            
                            values = [a, b, c, d, e, f]
                            
                            if not math_is_permuted_polygonal(values): continue
                            
                            return sum(values)

    return -1

start = time()
polygonals = []

for x in range(1000, 10000):
    if math_is_octagonal_or_smaller_polygonal(x):
        polygonals.append(x)
    
result = math_cyclic_polygonal_sum(polygonals)

print(f"0061{result:>64}    {time() - start:.6f}")
