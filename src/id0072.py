# Licensed under the MIT License.

# Counting Fractions

from sympy import sieve
from time import time

start = time()
result = sum(sieve.totientrange(2, 1000000 + 1))

print(f"0072{result:>64}    {time() - start:.6f}")
