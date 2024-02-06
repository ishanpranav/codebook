// Licensed under the MIT License.

// Path Sum: Two Ways

#include <limits.h>
#include <string.h>
#include "../lib/coordinate.h"
#include "../lib/euler.h"
#include "../lib/graphs/grid_graph.h"

struct GridNeighborIterator
{
    struct GridGraph* grid;
    struct Coordinate u;
    struct Coordinate v;
    int step;
    bool end;
};

typedef struct GridNeighborIterator* GridNeighborIterator;

void grid_neighbor_next(GridNeighborIterator iterator)
{
    switch (iterator->step)
    {
        case 0:
            iterator->step++;

            if (iterator->u.i + 1 < iterator->grid->m)
            {
                iterator->v.i = iterator->u.i + 1;
                iterator->v.j = iterator->u.j;

                return;
            }
            euler_fallthrough();

        case 1:
            iterator->step++;

            if (iterator->u.j + 1 < iterator->grid->n)
            {
                iterator->v.i = iterator->u.i;
                iterator->v.j = iterator->u.j + 1;

                return;
            }
            euler_fallthrough();

        default:
            iterator->end = true;
            break;
    }

}

void grid_neighbor_begin(
    GridNeighborIterator iterator, 
    GridGraph instance, 
    Coordinate source)
{
    iterator->grid = instance;
    iterator->u = *source;
    iterator->step = 0;
    iterator->end = false;

    grid_neighbor_next(iterator);
}

int main(void)
{
    char lineBuffer[512];
    struct GridGraph grid;
    struct PriorityQueue priorityQueue;
    clock_t start = clock();

    euler_ok(grid_graph(&grid, 80, 80));

    grid_graph_deserialize(&grid, stdin, lineBuffer, sizeof lineBuffer);

    euler_ok(priority_queue(
        &priorityQueue,
        sizeof(struct Coordinate),
        sizeof(int),
        0,
        int_comparer));

    for (size_t i = 0; i < grid.m; i++)
    {
        for (size_t j = 0; j < grid.n; j++)
        {
            grid.edges[i * grid.m + j].distance = INT_MAX;
        }
    }

    int distance = 0;
    struct Coordinate u;
    struct Coordinate source = { 0 };

    grid.edges[source.i * grid.m + source.j].distance = 0;

    priority_queue_enqueue(&priorityQueue, &source, &distance);

    while (priority_queue_try_dequeue(&priorityQueue, &u, &distance))
    {
        if (distance != grid.edges[u.i * grid.m + u.j].distance)
        {
            continue;
        }

        struct GridNeighborIterator v;

        for (grid_neighbor_begin(&v, &grid, &u); !v.end; grid_neighbor_next(&v))
        {
            GridEdge edge = grid.edges + v.v.i * grid.m + v.v.j;
            
            distance = grid.edges[u.i * grid.m + u.j].distance;

            int alternative = distance + edge->weight;
            
            if (alternative < edge->distance)
            {
                edge->distance = alternative;
                
                priority_queue_enqueue(&priorityQueue, &v.v, &alternative);
            }
        }
    }

    int sourceWeight = grid.edges[source.i * grid.m + source.j].weight;
    
    distance = grid.edges[(grid.m - 1) * grid.m + grid.n - 1].distance;

    return euler_submit(81, sourceWeight + distance, start);
}
