// Licensed under the MIT License.

// Largest Prime Factor

#include <math.h>
#include "../lib/euler.h"

long long math_max_prime_factor(long long n)
{
    long long max = 0;
    long long sqrtN = ceil(sqrt(n));

    for (long long i = 2; i <= sqrtN; i++) 
    {
        while (n % i == 0) 
        {
            n /= i;

            if (i > max) 
            {
                max = i;
            }
        }
    }

    if (!max || (n > 1 && n > max)) 
    {
        return n;
    }

    return max;
}

int main(void)
{
    clock_t start = clock();
    long long max = math_max_prime_factor(600851475143);

    return euler_submit(3, max, start);
}
