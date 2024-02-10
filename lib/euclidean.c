// Licensed under the MIT License.

#include <math.h>
#include <stdlib.h>
#include "euclidean.h"

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

long lcm(long a, long b)
{
    return (a / gcd(a, b)) * b;
}
