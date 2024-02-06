#include <stdbool.h>
#include "coordinate.h"
#include "directions.h"
#include "grid_graph.h"

struct GridNeighborIterator
{
    struct GridGraph* grid;
    struct Coordinate u;
    struct Coordinate v;
    enum Directions step;
    enum Directions steps;
    bool end;
};

typedef struct GridNeighborIterator* GridNeighborIterator;

void grid_neighbor_begin(
    GridNeighborIterator iterator, 
    GridGraph instance, 
    Coordinate source,
    Directions step);
void grid_neighbor_next(GridNeighborIterator iterator);
