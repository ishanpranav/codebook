// Licensed under the MIT License.

// Path Sum: Two Ways

#include <string.h>
#include "../lib/euler.h"
#include "../lib/graphs/grid_graph.h"

int main(void)
{
    // char lineBuffer[512];
    // struct GridGraph graph;
    // clock_t start = clock();

    // euler_ok(grid_graph(&graph, 80, 80));

    // grid_graph_deserialize(&graph, stdin, lineBuffer, sizeof lineBuffer);

    struct PriorityQueue heap;

    euler_ok(priority_queue(&heap, sizeof(double), sizeof(int), 0, int_comparer));

    int a = 2, b = 6, c = 3, d = 1;
    double ak = 2.1, bk = 6.2, ck = 3.3, dk = 1.4;

    euler_assert(!heap.count);
    euler_ok(priority_queue_enqueue(&heap, &ak, &a));
    euler_assert(heap.count == 1);
    // euler_ok(priority_queue_enqueue(&heap, &bk, &b));
    // euler_ok(priority_queue_enqueue(&heap, &ck, &c));
    // euler_ok(priority_queue_enqueue(&heap, &dk, &d));

    // struct PriorityQueueElement result;

    // euler_assert(priority_queue_try_dequeue(&result, &heap));
    // printf("%d?\n", *(int*)result.item);
    // euler_assert(*(int*)result.item == 1);
    // euler_assert(result.priority == 1);
    // euler_ok(priority_queue_enqueue(&heap, arr + 4, 8));
    // euler_ok(priority_queue_enqueue(&heap, arr + 5, 12));
    // euler_ok(priority_queue_enqueue(&heap, arr + 6, 14));
    
    double* items = heap.items;
    int* priorities = heap.priorities;

    for (size_t i = 1; i < heap.count + 1; i++)
    {
        printf("%lf (%d), ", items[i], priorities[i]);
    }

    // list_clear(&heap);
    // euler_assert(!heap.count);
    
    finalize_priority_queue(&heap);
    // finalize_grid_graph(&graph);

    // for (size_t i = 0; i < graph.m; i++)
    // {
    //     for (size_t j = 0; j < graph.n; j++)
    //     {
    //         printf("%d ", graph.costs[i * graph.n + j]);
    //     }

    //     printf("\n");
    // }

    // return euler_submit(81, 0, start);
}
