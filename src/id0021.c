// Licensed under the MIT License.

// Amicable Numbers

#include <stdlib.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"
#include "../lib/exception.h"

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    int* d = malloc(sizeof * d * 9998);

    if (!d)
    {
        Exception ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
    }
    
    for (int a = 2; a < 10000; a++)
    {
        d[a - 2] = divisor_sum(a);
    }

    for (int a = 2; a < 10000; a++)
    {
        int b = d[a - 2];

        if (a != b && a == d[b - 2])
        {
            sum += a;
        }
    }

    free(d);
    
    return euler_submit(21, sum, start);
}
