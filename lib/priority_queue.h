#include "list.h"
#include "priority_queue_element.h"

typedef struct List* PriorityQueue;

Exception priority_queue(
    PriorityQueue instance,
    size_t itemSize,
    size_t capacity);

bool priority_queue_try_dequeue(
    PriorityQueueElement result,
    PriorityQueue instance);

Exception priority_queue_enqueue(
    PriorityQueue instance, 
    Object item, 
    int priority);
