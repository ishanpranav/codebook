# Licensed under the MIT License.

# Diophantine Equation

from sympy import integer_nthroot
from time import time

start = time()
maxD = -1
maxX = 0

for d in range(2, 1000 + 1):
    isqrt, is_square = integer_nthroot(d, 2)
    
    if is_square: continue

    a = isqrt
    h = 0
    k = 1
    x = [ 0, 1, isqrt ]
    y = [ 0, 0, 1 ]
    
    while x[2] * x[2] - d * y[2] * y[2] != 1:
        h = a * k - h
        k = (d - h * h) // k
        a = (isqrt + h) // k
        x[0] = x[1]
        x[1] = x[2]
        x[2] = a * x[1] + x[0]
        y[0] = y[1]
        y[1] = y[2]
        y[2] = a * y[1] + y[0]

    if x[2] > maxX: 
        maxD = d
        maxX = x[2]
        
print(f"0066{maxD:>64}    {time() - start:.6f}")
