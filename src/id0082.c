// Licensed under the MIT License.

// Path Sum: Three Ways

#include <limits.h>
#include "../lib/grid_neighbor_iterator.h"
#include "../lib/euler.h"
#include "../lib/priority_queue.h"

int main(void)
{
    char lineBuffer[512];
    int minDistance = INT_MAX;
    struct GridGraph grid;
    struct Coordinate s = { 0 };
    struct Coordinate source = { 0 };
    clock_t start = clock();

    euler_ok(grid_graph(&grid, 80, 80));
    grid_graph_deserialize(&grid, stdin, lineBuffer, sizeof lineBuffer);

    struct Coordinate t = 
    { 
        .j = grid.n - 1
    };

    for (s.i = 0; s.i < grid.m; s.i++)
    {
        grid_min_path(&grid, &s, DIRECTIONS_ALL & ~DIRECTIONS_LEFT);

        for (t.i = 0; t.i < grid.n; t.i++)
        {
            if (grid.edges[t.i * grid.m + t.j].distance < minDistance)
            {
                source = s;
                minDistance = grid.edges[t.i * grid.m + t.j].distance;
            }
        }
    }
    
    int sourceWeight = grid.edges[source.i * grid.m + source.j].weight;

    finalize_grid_graph(&grid);

    return euler_submit(82, sourceWeight + minDistance, start);
}
