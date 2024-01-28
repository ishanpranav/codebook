# Licensed under the MIT License.

# Magic 5-gon Ring

from itertools import permutations
from time import time

maxString = ""
start = time()

for a, b, c, d, e, f, g, h, i, j in permutations(range(1, 10 + 1)):
    if a > d or a > f or a > h or a > j: continue
    if d != 10 and f != 10 and h != 10 and j != 10: continue
    
    sum = a + b + c
    
    if c + d + e != sum or e + f + g != sum: continue
    if g + h + i != sum or i + j + b != sum: continue
    
    string = "".join(map(str, [ a, b, c, d, c, e, f, e, g, h, g, i, j, i, b ]))
    
    if string > maxString:
        maxString = string

print(f"0068{maxString:>64}    {time() - start:.6f}")
