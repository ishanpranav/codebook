// Licensed under the MIT License.

// Path Sum: Two Ways

#include "../lib/euler.h"

struct Grid
{
    int m;
    int n;
    
};

typedef struct Grid* Grid;

int minDistance(int mdist[], int vset[], int V)
{
    int minVal = INT_MAX;
    static int minInd = -1; //remembers the previous value if not modified in the loop
    for (int i = 0; i < V; i++)
        if (vset[i] == 0 && mdist[i] < minVal)
        {
            minVal = mdist[i];
            minInd = i;
        }

    return minInd;
}

int main(void)
{
    clock_t start = clock();

    return euler_submit(81, 0, start);
}
