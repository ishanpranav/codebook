# Licensed under the MIT License.

# Convergents of e

from time import time

a = [ 0, 1, 2 ]

for i in range(2, 100 + 1):
    a[0] = a[1]
    a[1] = a[2]
    
    if i % 3 == 0:
        a[2] = a[0] + (2 * i // 3) * a[1]
    else:
        a[2] = a[0] + a[1]
    
sum = 0

while a[2] > 0:
    sum += a[2] % 10
    a[2] //= 10

start = time()

print(f"0065{sum:>64}    {time() - start:.6f}")
