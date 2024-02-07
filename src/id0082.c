// Licensed under the MIT License.

// Path Sum: Three Ways

#include "../lib/grid_neighbor_iterator.h"
#include "../lib/euler.h"
#include "../lib/priority_queue.h"

int main(void)
{
    char lineBuffer[512];
    struct GridGraph grid;
    struct Coordinate source = { 0 };
    clock_t start = clock();

    euler_ok(grid_graph(&grid, 80, 80));
    grid_graph_deserialize(&grid, stdin, lineBuffer, sizeof lineBuffer);
    euler_ok(grid_min_path(&grid, &source, DIRECTIONS_ALL & ~DIRECTIONS_LEFT));

    int sourceWeight = grid.edges[source.i * grid.m + source.j].weight;
    int distance = grid.edges[(grid.m - 1) * grid.m + grid.n - 1].distance;

    finalize_grid_graph(&grid);

    return euler_submit(82, sourceWeight + distance, start);
}
