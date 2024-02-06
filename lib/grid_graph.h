// Licensed under the MIT License.

#include "exception.h"
#include "grid_edge.h"
#include "stream.h"

/** Represents a two-dimensional-grid-based graph. */
struct GridGraph
{
    struct GridEdge* edges;
    size_t m;
    size_t n;
};

/** Represents a two-dimensional-grid-based graph. */
typedef struct GridGraph* GridGraph;

/**
 * Initializes a `GridGraph` instance.
 *
 * @param instance the `GridGraph` instance.
 * @param m        the number of rows.
 * @param n        the number of columns.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception grid_graph(GridGraph instance, size_t m, size_t n);

/**
 * Deserializes a two-dimensional-grid-based graph from a formatted input
 * stream.
 *
 * @param instance   the `GridGraph` instance to which edges are added.
 * @param input      the input stream.
 * @param lineBuffer the line buffer. The caller must ensure that the buffer
 *                   size is sufficient.
 * @param length     the line buffer size.
*/
void grid_graph_deserialize(
    GridGraph instance,
    Stream input,
    char lineBuffer[],
    size_t length);

/**
 * Determines the minimum path between a source vertex `s` and all other
 * vertices `t` in the graph using Dijkstra's shortest path algorithm.
 *
 * @param instance the `GridGraph` instance.
 * @param source   the coordinate of the source vertex (`s`).
 * @param step     a bitwise combination of allowed directions.
 * @return An exception; otherwise, `0`.
*/
Exception grid_min_path(GridGraph instance, Coordinate source, Directions step);

/**
 * Frees all resources.
 *
 * @param instance the `GridGraph` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_grid_graph(GridGraph instance);
