// Licensed under the MIT License.

// Largest Product in a Series

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/series.h"

long long series_max_product(Series series, int k)
{
    long long result = 0;

    for (char* iter = series->begin; iter < series->end - k - 1; iter++)
    {
        long long product = *iter;

        for (int j = 1; j < k; j++)
        {
            product *= iter[j];
        }

        if (product > result)
        {
            result = product;
        }
    }

    return result;
}

int main(void)
{
    char buffer[1024];
    clock_t start = clock();

    if (fread(buffer, 1, sizeof buffer, stdin) == 0)
    {
        euler_throw("Format");
    }

    Series series = series_from_string(buffer);
    long long max = series_max_product(series, 13);

    free(series);
    
    return euler_submit(8, max, start);
}
