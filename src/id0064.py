# Licensed under the MIT License.

# Odd Period Square Roots

from sympy import integer_nthroot
from time import time

start = time()
count = 0

for n in range(2, 10000):
    isqrt, is_square = integer_nthroot(n, 2)
    
    if is_square: continue

    h = 0
    k = 1
    i = 0
    a = isqrt
    end = 2 * a
    
    while a != end:
        h = a * k - h
        k = (n - h * h) // k
        a = (isqrt + h) // k
        i += 1
    
    count += i % 2

print(f"0064{count:>64}    {time() - start:.6f}")
