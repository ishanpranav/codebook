// Licensed under the MIT License.

// Digit Factorial Chains

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/factorial.h"

int main(void)
{
    Exception ex;
    clock_t start = clock();
    int* visited = calloc(1000000l, sizeof * visited);

    if (!visited)
    {
        ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
    }

    struct List terms;

    ex = list(&terms, 60);

    euler_ok();

    struct List factorial;

    ex = list(&factorial, 9);
    
    euler_ok();
    
    factorial_range(&factorial, 10);
    
    int count = 0;

    for (long m = 0; m < 1000000l; m++)
    {
        list_clear(&terms);

        visited[m] = 1;

        for (long n = m; ; )
        {
            ex = list_add(&terms, n);

            euler_ok();

            long sum = 0;

            for (long k = n; k; k /= 10)
            {
                sum += factorial.begin[k % 10];
            }

            if (sum >= 1000000l || list_contains(&terms, sum))
            {
                break;
            }

            if (visited[sum])
            {
                visited[m] += visited[sum];
            
                break;
            }

            visited[m]++;
            n = sum;
        }

        if (visited[m] == 60)
        {
            count++;
        }
    }
    
    free(visited);
    finalize_list(&terms);

    return euler_submit(74, count, start);
}
