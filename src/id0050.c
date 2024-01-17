#include "../lib/euler.h"
#include "../lib/prime_list.h"

int main(void)
{
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 1000000l);

    euler_ok();

    long maxSum = 0;
    long maxLength = 0;

    for (long* p = primes.primes.begin; p < primes.primes.end; p++)
    {
        long sum = 0;

        for (long* q = p; q < primes.primes.end; q++)
        {
            sum += *q;

            if (sum > 1000000l)
            {
                break;
            }

            if (sum <= maxSum)
            {
                continue;
            }

            long length = q - p;

            if (length <= maxLength || !prime_list_is_prime(&primes, sum))
            {
                continue;
            }

            maxSum = sum;
            maxLength = length;
        }
    }

    return euler_submit(50, maxSum, start);
}
