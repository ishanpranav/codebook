# Licensed under the MIT License.

# Counting Fractions

from sympy import sieve
from time import time

start = time()
summatoryTotient = sum(sieve.totientrange(2, 1000000 + 1))

print(f"0072{summatoryTotient:>64}    {time() - start:.6f}")
