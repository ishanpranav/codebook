// Licensed under the MIT License.

// Amicable Numbers

#include <math.h>
#include <stdlib.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    int* d = malloc(sizeof * d * 9998);

    if (!d)
    {
        euler_throw("Out of memory");
    }

    for (int a = 2; a < 10000; a++)
    {
        int da = 0;
        struct DivisorIterator iter;

        for (divisor_begin(&iter, a); !divisor_end(&iter); divisor_next(&iter))
        {
            da += iter.current;
        }

        d[a - 2] = da;
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
