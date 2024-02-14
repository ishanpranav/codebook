// Licensed under the MIT License.

// Square Digit Chains

#include "../lib/euler.h"

int math_sum_of_square_digits(long n, int results[])
{
    if (n < 568 && results[n])
    {
        return results[n];
    }

    long result = 0;

    for (long k = n; k; k /= 10)
    {
        int d = k % 10;

        result += d * d;
    }

    return result;
}

int math_square_digit_chain(long m, int results[])
{
    long n = m;

    while (n != 1 && n != 89)
    {
        n = math_sum_of_square_digits(n, results);
    }

    return n;
}

int main(void)
{
    long count = 0;
    int results[568] = { 0 };
    clock_t start = clock();

    for (long m = 1; m < 568; m++)
    {
        results[m] = math_square_digit_chain(m, results);

        if (results[m] == 89)
        {
            count++;
        }
    }

    for (long m = 1; m < 10000000l; m++)
    {
        long n = math_square_digit_chain(m, results);

        if (n == 89)
        {
            count++;
        }
    }

    return euler_submit(91, count, start);
}
