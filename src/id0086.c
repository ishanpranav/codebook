// Licensed under the MIT License.

// Cuboid Route

#include "../lib/euler.h"

int main(void)
{
    int m = 100;
    long count = 2060;
    clock_t start = clock();

    while (count < 1000000l)
    {
        m++;

        int end = m + m;

        for (int i = 1; i <= end; i++)
        {
            if (math_is_polygonal(4, i * i + m * m, NULL))
            {
                if (i <= m)
                {
                    count += i / 2;
                }
                else 
                {
                    count += m - (i - 1) / 2;
                }
            }
        }
    }

    return euler_submit(86, m, start);
}
