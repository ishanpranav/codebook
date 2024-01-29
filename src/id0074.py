# Licensed under the MIT License.

# Digit Factorial Chains

from math import factorial
from time import time

count = 0
visited = {}
start = time()
factorials = { str(n): factorial(n) for n in range(10) }

for m in range(1000000):
    terms = set()
    visited[m] = 1
    n = m
  
    while len(terms) < 60:
        terms.add(n)
        
        n = sum(factorials[c] for c in str(n))
    
        if n in terms: break
        
        if n in visited: 
            visited[m] += visited[n]
        
            break

        visited[m] += 1

    if visited[m] == 60:
        count += 1

print(len(visited))
print(f"0074{count:>64}    {time() - start:.6f}")
