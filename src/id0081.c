// Licensed under the MIT License.

// Path Sum: Two Ways

#include <string.h>
#include "../lib/euler.h"
#include "../lib/graphs/grid_graph.h"

int main(void)
{
    char lineBuffer[512];
    struct GridGraph graph;
    clock_t start = clock();

    euler_ok(grid_graph(&graph, 80, 80));

    grid_graph_deserialize(&graph, stdin, lineBuffer, sizeof lineBuffer);

    // for (size_t i = 0; i < graph.m; i++)
    // {
    //     for (size_t j = 0; j < graph.n; j++)
    //     {
    //         printf("%d ", graph.costs[i * graph.n + j]);
    //     }

    //     printf("\n");
    // }

    return euler_submit(81, 0, start);
}
