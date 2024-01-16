// Licensed under the MIT License.

#include <stdio.h>
#include "euler.h"
#include "exception.h"

Exception euler_submit(int id, long long result, clock_t start)
{
    double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
    
    printf("%04d%64lld    %lf\n", id, result, elapsed);

    return 0;
}

void euler_swap(long* p, long* q)
{
    long swap = *p;

    *p = *q;
    *q = swap;
}

long math_natural_sum(long n)
{
    return n * (n + 1) / 2;
}

long math_gcd(long a, long b)
{
    while (b > 0)
    {
        long r = a % b;

        a = b;
        b = r;
    }

    return a;
}

bool math_is_palindrome(long n)
{
    long x = 0;

    for (long y = n; y; y /= 10)
    {
        x = (x * 10) + y % 10;
    }

    return x == n;
}
