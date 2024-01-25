# Licensed under the MIT License.

# Odd Period Square Roots

from sympy import integer_nthroot
from time import time

start = time()
count = 0

for n in range(2, 10000):
    nthroot = integer_nthroot(n, 2)
    
    if nthroot[1]: continue

    a = nthroot[0]
    dn = 0
    k = 1
    i = 0
    
    while a != 2 * nthroot[0]:
        dn = a * k - dn
        k = (n - dn * dn) // k
        a = (nthroot[0] + dn) // k
        i += 1
    
    count += i % 2

print(f"0064{count:>64}    {time() - start:.6f}")
