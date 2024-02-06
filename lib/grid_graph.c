// Licensed under the MIT License.

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "euler.h"
#include "grid_neighbor_iterator.h"
#include "priority_queue.h"

Exception grid_graph(GridGraph instance, size_t m, size_t n)
{
    instance->edges = calloc(m * n, sizeof * instance->edges);

    if (!instance->edges)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->m = m;
    instance->n = n;

    return 0;
}

void grid_graph_deserialize(
    GridGraph instance,
    Stream input,
    char lineBuffer[],
    size_t length)
{
    size_t i = 0;

    while (fgets(lineBuffer, length * sizeof * lineBuffer, input))
    {
        size_t j = 0;

        for (String tok = strtok(lineBuffer, ","); tok; tok = strtok(NULL, ","))
        {
            size_t index = i * instance->n + j;

            instance->edges[index].weight = strtoll(tok, NULL, 10);
            j++;
        }

        i++;
    }
}

void grid_neighbor_next(GridNeighborIterator iterator)
{
    if (iterator->step == DIRECTIONS_TOP)
    {
        iterator->step = DIRECTIONS_LEFT;

        if ((iterator->steps & DIRECTIONS_TOP) == DIRECTIONS_TOP &&
            iterator->u.i > 0)
        {
            iterator->v.i = iterator->u.i - 1;
            iterator->v.j = iterator->u.j;

            return;
        }
    }

    if (iterator->step == DIRECTIONS_LEFT)
    {
        iterator->step = DIRECTIONS_BOTTOM;

        if ((iterator->steps & DIRECTIONS_LEFT) == DIRECTIONS_LEFT &&
            iterator->u.j > 0)
        {
            iterator->v.i = iterator->u.i;
            iterator->v.j = iterator->u.j - 1;

            return;
        }
    }

    if (iterator->step == DIRECTIONS_BOTTOM)
    {
        iterator->step = DIRECTIONS_RIGHT;

        if ((iterator->steps & DIRECTIONS_BOTTOM) == DIRECTIONS_BOTTOM &&
            iterator->u.i + 1 < iterator->grid->m)
        {
            iterator->v.i = iterator->u.i + 1;
            iterator->v.j = iterator->u.j;

            return;
        }
    }

    if (iterator->step == DIRECTIONS_RIGHT)
    {
        iterator->step = DIRECTIONS_NONE;

        if ((iterator->steps & DIRECTIONS_RIGHT) == DIRECTIONS_RIGHT &&
            iterator->u.j + 1 < iterator->grid->n)
        {
            iterator->v.i = iterator->u.i;
            iterator->v.j = iterator->u.j + 1;

            return;
        }
    }

    iterator->end = true;
}

void grid_neighbor_begin(
    GridNeighborIterator iterator,
    GridGraph instance,
    Coordinate source,
    Directions step)
{
    iterator->grid = instance;
    iterator->u = *source;
    iterator->step = DIRECTIONS_TOP;
    iterator->steps = step;
    iterator->end = false;

    grid_neighbor_next(iterator);
}

Exception grid_min_path(GridGraph instance, Coordinate source, Directions step)
{
    struct PriorityQueue priorityQueue;
    Exception ex = priority_queue(
        &priorityQueue,
        sizeof(struct Coordinate),
        sizeof(int),
        0,
        int_comparer);

    if (ex)
    {
        return ex;
    }

    for (size_t i = 0; i < instance->m; i++)
    {
        for (size_t j = 0; j < instance->n; j++)
        {
            instance->edges[i * instance->m + j].distance = INT_MAX;
        }
    }

    int distance = 0;
    struct Coordinate u;

    instance->edges[source->i * instance->m + source->j].distance = 0;

    priority_queue_enqueue(&priorityQueue, source, &distance);

    while (priority_queue_try_dequeue(&priorityQueue, &u, &distance))
    {
        if (distance != instance->edges[u.i * instance->m + u.j].distance)
        {
            continue;
        }

        struct GridNeighborIterator v;

        for (grid_neighbor_begin(&v, instance, &u, step);
            !v.end;
            grid_neighbor_next(&v))
        {
            GridEdge edge = instance->edges + v.v.i * instance->m + v.v.j;

            distance = instance->edges[u.i * instance->m + u.j].distance;

            int alternative = distance + edge->weight;

            if (alternative < edge->distance)
            {
                edge->distance = alternative;

                priority_queue_enqueue(&priorityQueue, &v.v, &alternative);
            }
        }
    }

    finalize_priority_queue(&priorityQueue);

    return 0;
}

void finalize_grid_graph(GridGraph instance)
{
    free(instance->edges);

    instance->edges = NULL;
    instance->m = 0;
    instance->n = 0;
}
