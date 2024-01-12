// Licensed under the MIT License.

// Amicable Numbers

#include <assert.h>
#include <stdlib.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    int* d = malloc(sizeof * d * 9998);

    assert(d);

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
