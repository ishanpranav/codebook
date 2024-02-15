// Licensed under the MIT License.

// Ugly Number

#include <stdbool.h>

bool isUgly(int n)
{
    if (!n)
    {
        return false;
    }

    if (n == 1)
    {
        return true;
    }

    int m[] = { 2, 3, 5, 0 };

    for (int* it = m; *it; it++)
    {
        while (n % *it == 0)
        {
            n /= *it;
        }
    }

    return n == 1;
}
