// Licensed under the MIT License.

// Largest Product in a Grid

#include <assert.h>
#include "lib/euler.h"

int main(void)
{
    int grid[20][20];

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int scan = scanf("%d", &grid[i][j]);

            assert(scan == 1);
        }
    }

    clock_t start = clock();
    long max = 0;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            long product = grid[i][j];

            for (int k = 1; k < 4; k++)
            {
                product *= grid[i][j + k];
            }

            if (product > max)
            {
                max = product;
            }
        }
    }

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 17; i++)
        {
            long product = grid[i][j];

            for (int h = 1; h < 4; h++)
            {
                product *= grid[i + h][j];
            }

            if (product > max)
            {
                max = product;
            }
        }
    }

    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            long product = grid[i][j];

            for (int n = 1; n < 4; n++)
            {
                product *= grid[i + n][j + n];
            }

            if (product > max)
            {
                max = product;
            }
        }
    }
    
    for (int i = 0; i < 17; i++)
    {
        for (int j = 19; j >= 3; j--)
        {
            long product = grid[i][j];

            for (int n = 1; n < 4; n++)
            {
                product *= grid[i + n][j - n];
            }

            if (product > max)
            {
                max = product;
            }
        }
    }

    euler_submit(11, max, start);
}
