# Licensed under the MIT License.

# Magic 5-gon Ring

from itertools import permutations
from time import time

maxString = ""
start = time()

for l in permutations([ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]):
    if l[0] > l[3] or l[0] > l[5] or l[0] > l[7] or l[0] > l[9]: continue
    if l[3] != 10 and l[5] != 10 and l[7] != 10 and l[9] != 10: continue
    
    sum = l[0] + l[1] + l[2]
    
    if l[2] + l[3] + l[4] != sum or l[4] + l[5] + l[6] != sum: continue
    if l[6] + l[7] + l[8] != sum or l[8] + l[9] + l[1] != sum: continue
    
    string = "".join(map(str, [
        l[0], l[1], l[2], 
        l[3], l[2], l[4], 
        l[5], l[4], l[6], 
        l[7], l[6], l[8], 
        l[9], l[8], l[1]
    ]))
    
    if string > maxString:
        maxString = string

print(f"0068{maxString:>64}    {time() - start:.6f}")
