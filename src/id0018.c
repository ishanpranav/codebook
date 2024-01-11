// Licensed under the MIT License.

// Maximum Path Sum I
// Maximum Path Sum II

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "../lib/euler.h"
#define MAX_HEIGHT 15

int main(void)
{
    int m = 0;
    int items[MAX_HEIGHT][MAX_HEIGHT + 1] = { 0 };
    clock_t start = clock();
    char buffer[64];

    while (fgets(buffer, sizeof buffer, stdin))
    {
        char* mid = buffer;

        for (int j = 0; j < m + 1; j++)
        {
            items[m][j] = strtol(mid, &mid, 10);
        }

        m++;
    }
    
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (items[i + 1][j] > items[i + 1][j + 1])
            {
                items[i][j] += items[i + 1][j];
            }
            else
            {
                items[i][j] += items[i + 1][j + 1];
            }
        }
    }

    euler_submit(18, items[0][0], start);
}
