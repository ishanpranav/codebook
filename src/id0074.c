// Licensed under the MIT License.

// Digit Factorial Chains

#include "../lib/euler.h"
#include "../lib/factorial.h"
#include "../lib/list.h"

int main(void)
{
    struct List terms;
    clock_t start = clock();
    int* visited = calloc(1000000l, sizeof * visited);

    euler_assert(visited);

    long long* factorials = factorial_range(10);

    euler_assert(factorials);
    euler_ok(list(&terms, sizeof(long), 60));

    int count = 0;

    for (long m = 0; m < 1000000l; m++)
    {
        list_clear(&terms);

        visited[m] = 1;

        for (long n = m; ; )
        {
            euler_ok(list_add(&terms, &n));
            
            long sum = 0;

            for (long k = n; k; k /= 10)
            {
                sum += factorials[k % 10];
            }

            if (sum >= 1000000l)
            {
                break;
            }

            if (list_contains(&terms, &sum, long_equality_comparer))
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
    free(factorials);
    finalize_list(&terms);

    return euler_submit(74, count, start);
}
