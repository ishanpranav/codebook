// Licensed under the MIT License.

// Maximum Path Sum I
// Maximum Path Sum II

#include "../lib/euler.h"
#include "../lib/string.h"
#define BUFFER_SIZE 512
#define MAX_HEIGHT 100

int main(int argc, String argv[])
{
    int id;

    if (argc == 2)
    {
        id = strtol(argv[1], NULL, 10);
    }
    else
    {
        id = 18;
    }

    int m = 0;
    int items[MAX_HEIGHT][MAX_HEIGHT + 1] = { 0 };
    char buffer[BUFFER_SIZE];
    clock_t start = clock();

    while (fgets(buffer, sizeof buffer, stdin))
    {
        String substring = buffer;

        for (int j = 0; j < m + 1; j++)
        {
            items[m][j] = strtol(substring, &substring, 10);
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

    return euler_submit(id, items[0][0], start);
}
