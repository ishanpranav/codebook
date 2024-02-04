# Licensed under the MIT License.

# Coin Partitions

from sympy import partition
from time import time

n = 0
start = time()

while partition(n) % 1000000 != 0:
    n += 1

print(f"0078{n:>64}    {time() - start:.6f}")
