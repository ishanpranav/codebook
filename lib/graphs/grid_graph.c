// Licensed under the MIT License.

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
