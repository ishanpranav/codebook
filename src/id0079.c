// Licensed under the MIT License.

// Passcode Derivation

#include <string.h>
#include "../lib/euler.h"

struct Graph
{
    bool vertices[10];
    bool edges[10][10];
};

typedef struct Graph* Graph;

void graph(Graph graph)
{
    memset(graph->vertices, false, sizeof graph->vertices);
    memset(graph->edges, false, sizeof graph->edges);
}

bool graph_is_leaf(Graph instance, int vertex)
{
    if (!instance->vertices[vertex])
    {
        return false;
    }

    for (int v = 0; v < 10; v++)
    {
        if (!instance->vertices[v])
        {
            continue;
        }

        if (instance->edges[vertex][v])
        {
            return false;
        }
    }

    return true;
}

int graph_first_leaf(Graph instance)
{
    for (int u = 0; u < 10; u++)
    {
        if (graph_is_leaf(instance, u))
        {
            return u;
        }
    }

    return -1;
}

void graph_remove_leaf(Graph instance, int vertex)
{
    instance->vertices[vertex] = false;

    for (int v = 0; v < 10; v++)
    {
        instance->edges[v][vertex] = false;
    }
}

int main(void)
{
    struct Graph g;
    clock_t start = clock();

    graph(&g);

    for (int i = 0; i < 50; i++)
    {
        char a, b, c;
        int scan = scanf("%c%c%c ", &a, &b, &c);

        euler_assert(scan == 3);

        g.vertices[a - '0'] = true;
        g.vertices[b - '0'] = true;
        g.vertices[c - '0'] = true;
        g.edges[b - '0'][a - '0'] = true;
        g.edges[c - '0'][b - '0'] = true;
    }

    int leaf;
    long min = 0;

    while ((leaf = graph_first_leaf(&g)) != -1)
    {
        min = (min * 10) + leaf;

        graph_remove_leaf(&g, leaf);
    }

    return euler_submit(79, min, start);
}
