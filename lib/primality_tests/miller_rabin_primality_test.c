// Licensed under the MIT License.

#include <math.h>
#include <stdbool.h>
#include "../pow.h"
#include "../primality_test.h"

static bool miller_rabin_witness(
    long long n,
    long long s,
    long long d,
    long long a)
{
    long long x = mod_pow(a, d, n);
    long long y = 1;

    while (s)
    {
        y = (x * x) % n;

        if (y == 1 && x != 1 && x != n - 1)
        {
            return false;
        }

        x = y;
        s--;
    }

    if (y != 1)
    {
        return false;
    }

    return true;
}

static bool miller_rabin_witness_all(
    long long n,
    long long s,
    long long d,
    long long a[])
{
    for (long long* p = a; *p; p++)
    {
        if (!miller_rabin_witness(n, s, d, *p))
        {
            return false;
        }
    }

    return true;
}

static bool miller_rabin_is_prime(long long n)
{
    long long d = n / 2;
    long long s = 1;

    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    if (n < 1373653l)
    {
        static long long a[] = { 2, 3, 0 };

        return miller_rabin_witness_all(n, s, d, a);
    }

    if (n < 9080191l)
    {
        static long long a[] = { 31, 73, 0 };

        return miller_rabin_witness_all(n, s, d, a);
    }

    if (n < 4759123141ll)
    {
        static long long a[] = { 2, 7, 61, 0 };

        return miller_rabin_witness_all(n, s, d, a);
    }

    if (n < 1122004669633ll)
    {
        static long long a[] = { 13, 23, 1662803l, 0 };

        return miller_rabin_witness_all(n, s, d, a);
    }

    if (n < 2152302898747ll)
    {
        static long long a[] = { 2, 3, 5, 7, 11, 0 };

        return miller_rabin_witness_all(n, s, d, a);
    }

    if (n < 3474749660383ll)
    {
        static long long a[] = { 2, 3, 5, 7, 11, 13, 0 };

        return miller_rabin_witness_all(n, s, d, a);
    }

    static long long a[] = { 2, 3, 5, 7, 11, 13, 17, 0 };

    return miller_rabin_witness_all(n, s, d, a);
}

Primality miller_rabin_primality_test(long n)
{
    if (n < 2)
    {
        return PRIMALITY_NONE;
    }

    if (n <= 3)
    {
        return PRIMALITY_PRIME;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return PRIMALITY_COMPOSITE;
    }

    if (miller_rabin_is_prime(n))
    {
        return PRIMALITY_PRIME;
    }

    return PRIMALITY_COMPOSITE;
}
