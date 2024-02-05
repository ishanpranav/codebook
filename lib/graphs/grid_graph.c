// Licensed under the MIT License.

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "../euler.h"
#include "../coordinate.h"
#include "grid_graph.h"

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

static Exception grid_graph_neighbors(
    List result,
    GridGraph instance,
    Object vertex,
    int weight)
{
    Coordinate u = vertex;
    struct Coordinate v;
    Exception ex = list_ensure_capacity(result, result->count + 4);

    if (ex)
    {
        return ex;
    }

    if (u->i + 1 < instance->m)
    {
        v.i = u->i + 1;
        v.j = u->j;

        list_add(result, &v);
    }

    if (u->j + 1 < instance->n)
    {
        v.i = u->i;
        v.j = u->j + 1;

        list_add(result, &v);
    }

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

void finalize_grid_graph(GridGraph instance)
{
    free(instance->edges);

    instance->edges = NULL;
    instance->m = 0;
    instance->n = 0;
}
