# Licensed under the MIT License.

# Convergents of e

from time import time

a = [ 0, 1264, 1457 ]

for i in range(11, 100 + 1):
    a[0] = a[1]
    a[1] = a[2]
    
    if i % 3 == 0:
        a[2] = a[0] + (2 * i // 3) * a[1]
    else:
        a[2] = a[0] + a[1]

result = sum(int(c) for c in str(a[2]))
start = time()

print(f"0065{result:>64}    {time() - start:.6f}")
