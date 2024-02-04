// Licensed under the MIT License.

#include "../array.h"
#include "../exception.h"
#include "../graph.h"
#include "../object.h"
#include "../stream.h"
#include <stddef.h>

struct GridGraph
{
    struct Graph g;
    int* costs;
    size_t m;
    size_t n;
};

typedef struct GridGraph* GridGraph;

Exception grid_graph(GridGraph instance, size_t m, size_t n);
Array grid_graph_neighbors(Object instance, Object vertex, size_t* degree);
int grid_graph_weight(Object instance, Object source, Object target);
void grid_graph_deserialize(
    GridGraph instance, 
    Stream input, 
    char lineBuffer[],
    size_t length);
void finalize_grid_graph(GridGraph instance);
