# Licensed under the MIT License.

# Singular Integer Right Triangles

from collections import defaultdict
from math import gcd, sqrt
from time import time

def math_pythagorean_triplet_counts(max: int) -> defaultdict:
    result = defaultdict(int)
    end = int(sqrt(max))

    for m in range(1, end, 2):
        for n in range(2, end, 2):
            if gcd(m, n) != 1: continue
            
            sum = abs(m * m - n * n) + m * m + n * n + 2 * m * n
            
            for kSum in range(sum, max, sum):
                result[kSum] += 1

    return result

start = time()
count = 0

for tripletCount in math_pythagorean_triplet_counts(1500001).values():
    if tripletCount == 1:
        count += 1

print(f"0075{count:>64}    {time() - start:.6f}")
