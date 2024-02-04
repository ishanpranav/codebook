# Licensed under the MIT License.

# Square Root Digital Expansion

from decimal import Decimal, getcontext
from itertools import islice
from time import time

start = time()
result = 0
getcontext().prec = 102

for i in range(2, 100):
    term = Decimal(i).sqrt()
    
    if term == int(term): continue
    
    result += sum(islice([int(c) for c in str(term) if c != '.'], 100))
        
print(f"0080{result:>64}    {time() - start:.6f}")
