// Licensed under the MIT License.

// Counting Fractions in a Range

#include "../lib/euler.h"

long math_farey_count(int maxD, int n, int d)
{
    int* table = malloc(maxD * sizeof * table);

    if (!table)
    {
        return -1;
    }

    for (int i = 0; i < maxD; i++)
    {
        table[i] = i * n / d;
    }

    for (int i = 1; i < maxD; i++)
    {
        for (int j = i + i; j < maxD; j += i)
        {
            table[j] -= table[i];
        }
    }

    long result = 0;

    for (int i = 0; i < maxD; i++)
    {
        result += table[i];
    }

    free(table);

    return result;
}

int main(void)
{
    clock_t start = clock();
    long lessThanOneHalf = math_farey_count(12001, 1, 2);

    euler_assert(lessThanOneHalf != -1);

    long lessThanOneThird = math_farey_count(12001, 1, 3);

    euler_assert(lessThanOneThird != -1);
    
    long count = lessThanOneHalf - lessThanOneThird - 1;

    return euler_submit(73, count, start);
}
