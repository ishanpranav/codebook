#include "factorial.h"

Exception factorial_range(List results, int max)
{
    if (max < 1)
    {
        return 0;
    }

    Exception ex = list_ensure_capacity(results, max);

    if (ex)
    {
        return ex;
    }

    list_add(results, 1);

    for (int i = 1; i < max; i++)
    {
        results->begin[i] = i * results->begin[i - 1];
    }

    return 0;
}
