// Licensed under the MIT License.

#include "euler.h"

long math_even_fibonnaci_sum(long n)
{
    if (n < 2)
    {
        return 0;
    }
    
    long ef1 = 0;
    long ef2 = 2;
    long sum = ef1 + ef2;

    while (ef2 <= n)
    {
        long long ef3 = 4 * ef2 + ef1;

        if (ef3 > n)
        {
            break;
        }
        
        ef1 = ef2;
        ef2 = ef3;
        sum += ef2;
    }

    return sum;
}

int main(void)
{
    clock_t start = clock();
    long sum = math_even_fibonnaci_sum(4000000);

    euler_submit(2, sum, start);
}
