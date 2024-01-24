# Licensed under the MIT License.

# Cyclic Figurate Numbers

from math import sqrt
from time import time

def math_is_cyclic(a: int, b: int) -> bool: return a // 100 == b % 100

def math_is_polygonal(s: int, x: int) -> bool:
    sM2 = s - 2
    sM4 = sM2 - 2
    term = (sqrt(8 * sM2 * x + sM4 * sM4) + sM4) / (2 * sM2)

    return term == int(term)

def math_is_octagonal_or_smaller_figurate(x: int) -> bool:
    for s in range(3, 6):
        if math_is_polygonal(s, x): return True
    
    for s in range(7, 9):
        if math_is_polygonal(s, x): return True
                
    return False

def math_is_permuted_polygonal(l: set) -> bool:
    if len(l) != 6: return False
    
    polys = {}
    
    for i in range(3, 9):
        polys[i] = False
        
    for x in l:
        for s in range(8, 2, -1):
            if math_is_polygonal(s, x):
                polys[s] = True
                break
            
    return all(polys.values())
    
def math_cyclical_figurate_sum() -> int:
    polygonals = set()
    
    for x in range(1000, 10000):
        if math_is_octagonal_or_smaller_figurate(x):
            polygonals.add(x)
    
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
                            
                            l = set()
                            l.add(a)
                            l.add(b)
                            l.add(c)
                            l.add(d)
                            l.add(e)
                            l.add(f)
                            
                            if not math_is_permuted_polygonal(l): continue
                            
                            return sum(l)

    return -1

start = time()
result = math_cyclical_figurate_sum()

print(f"0061{result:>64}    {time() - start:.6f}")
