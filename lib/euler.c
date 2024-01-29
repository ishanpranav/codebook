// Licensed under the MIT License.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "euler.h"
#include "binomial.h"
#include "exception.h"
#include "factorial.h"
#include "object.h"

Exception euler_submit(int id, long long result, clock_t start)
{
    double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
    
    printf("%04d%64lld    %.6lf\n", id, result, elapsed);

    return 0;
}

long long binomial(int n, int k)
{
    if (k > n - k)
    {
        k = n - k;
    }

    long long result = 1;

    for (int i = 0; i < k; i++)
    {
        result = (result * (n - i)) / (i + 1);
    }

    return result;
}

LPArray factorial_range(int max)
{
    if (max < 1)
    {
        return 0;
    }

    LPArray result = malloc(max * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    result[0] = 1;

    for (int i = 1; i < max; i++)
    {
        result[i] = i * result[i - 1];
    }

    return result;
}

long gcd(long a, long b)
{
    while (b > 0)
    {
        long r = a % b;

        a = b;
        b = r;
    }

    return a;
}

void swap(Object left, Object right, size_t itemSize)
{    
    char* p = left;
    char* q = right;
    char* swap;

    for (size_t i = 0; i < itemSize; i++)
    {
        swap = p[i];
        p[i] = q[i];
        q[i] = swap;
    }
}

long math_natural_sum(long n)
{
    return n * (n + 1) / 2;
}

long long math_reverse(long long n)
{
    long long x = 0;

    for (long long y = n; y; y /= 10)
    {
        x = (x * 10) + y % 10;
    }

    return x;
}

bool math_is_palindrome(long long n)
{
    return n == math_reverse(n);
}
