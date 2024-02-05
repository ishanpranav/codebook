// Licensed under the MIT License.

#include "../object.h"
#include "../priority_queue.h"
#include "../stream.h"
#include "grid_graph_edge.h"

struct GridGraph
{
    struct GridGraphEdge* edges;
    size_t m;
    size_t n;
};

typedef struct GridGraph* GridGraph;

Exception grid_graph(GridGraph instance, size_t m, size_t n);
void grid_graph_deserialize(
    GridGraph instance, 
    Stream input, 
    char lineBuffer[],
    size_t length);
void finalize_grid_graph(GridGraph instance);
