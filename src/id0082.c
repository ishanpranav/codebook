// Licensed under the MIT License.

// Coordinate minSource;
// Coordinate minTarget;
// int minDistance = int.MaxValue;
// IDictionary<Coordinate, Coordinate> minPath;

// for (int sourceI = 0; sourceI < grid.GetLength(0); sourceI++)
// {
//     Coordinate s = new Coordinate(sourceI, 0);

//     Dijkstra(
//         grid,
//         s,
//         Neighbors,
//         Weight,
//         out IDictionary<Coordinate, int> distances,
//         out IDictionary<Coordinate, Coordinate> path);

//     for (int targetI = 0; targetI < grid.GetLength(0); targetI++)
//     {
//         Coordinate t = new Coordinate(targetI, grid.GetLength(1) - 1);
        
//         if (distances[t] < minDistance)
//         {
//             minSource = s;
//             minTarget = t;
//             minPath = path;
//             minDistance = distances[t];
//         }
//     }
// }

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
