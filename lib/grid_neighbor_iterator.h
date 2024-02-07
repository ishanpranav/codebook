// Licensed under the MIT License.

#include <stdbool.h>
#include "coordinate.h"
#include "directions.h"
#include "grid_graph.h"

/** Iterates over the neighbors of a vertex in a grid graph. */
struct GridNeighborIterator
{
    struct GridGraph* grid;
    struct Coordinate u;
    struct Coordinate v;
    enum Directions step;
    enum Directions steps;
    bool end;
};

/** Iterates over the neighbors of a vertex in a grid-based graph. */
typedef struct GridNeighborIterator* GridNeighborIterator;

/**
 * Provides an iterator over the neighbors of a vertex in a grid-based graph.
 *
 * @param iterator when this method returns, contains the iterator. This
 *                 argument is passed uninitialized.
 * @param instance the `GridGraph` instance.
 * @param source   the source vertex.
 * @param step     a bitwise combination of allowed directions.
*/
void grid_neighbor_begin(
    GridNeighborIterator iterator,
    GridGraph instance,
    Coordinate source,
    Directions step);

/**
 * Advances the iterator to the next neighboring vertex.
 *
 * @param iterator the iterator.
*/
void grid_neighbor_next(GridNeighborIterator iterator);
