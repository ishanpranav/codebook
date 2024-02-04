// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "../euler.h"
#include "grid_graph.h"

Exception grid_graph(GridGraph instance, size_t m, size_t n)
{
    instance->costs = malloc(m * n * sizeof * instance->costs);
    
    if (!instance->costs)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->m = m;
    instance->n = n;
    instance->g.neighbors = grid_graph_neighbors;
    instance->g.weight = grid_graph_weight;

    return 0;
}

Array grid_graph_neighbors(Object instance, Object vertex, size_t* degree)
{
    
}

int grid_graph_weight(Object instance, Object source, Object target)
{

}

void grid_graph_deserialize(
    GridGraph instance, 
    Stream input, 
    char lineBuffer[],
    size_t length)
{
    size_t i = 0;

    while (fgets(lineBuffer, length * sizeof * lineBuffer, stdin))
    {
        size_t j = 0;

        for (String tok = strtok(lineBuffer, ","); tok; tok = strtok(NULL, ","))
        {
            instance->costs[i * instance->n + j] = strtoll(tok, NULL, 10);
            j++;
        }

        i++;
    }
}

void finalize_grid_graph(GridGraph instance)
{
    free(instance->costs);
    
    instance->costs = NULL;
    instance->m = 0;
    instance->n = 0;
}
