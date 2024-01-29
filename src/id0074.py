from time import time

count = 0
factorial = [ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 ]
start = time()

for n in range(1, 1000000):
    terms = set()

    while len(terms) < 60:
        terms.add(n)
        
        k = n
        term = 0
            
        while k > 0:
            term += factorial[k % 10]    
            k //= 10
            
        if term in terms:
            break
        
        n = term

    if len(terms) == 60:
        count += 1

print(f"0074{count:>64}    {time() - start:.6f}")
