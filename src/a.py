from sympy import sieve

n = 50_000_000
sums = set()

for p in sieve.primerange(n ** (1/2)):
    for q in sieve.primerange(n ** (1/3)):
        for r in sieve.primerange(n ** (1/4)):
            sum = p ** 2 + q ** 3 + r ** 4
            
            if sum > n: break
                
            sums.add(sum)
            
print(len(sums), max(sums))
