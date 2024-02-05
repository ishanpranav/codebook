#include "comparer.h"
#include "list.h"
#include "priority_queue_element.h"

struct PriorityQueue
{
    int (*priorityComparer)(const void* left, const void* right);
    
    void* items;
    void* priorities;
    size_t itemSize;
    size_t prioritySize;
    size_t count;
    size_t capacity;
};

typedef struct PriorityQueue* PriorityQueue;

Exception priority_queue(
    PriorityQueue instance,
    size_t itemSize,
    size_t prioritySize,
    size_t capacity,
    Comparer priorityComparer);

Exception priority_queue_ensure_capacity(
    PriorityQueue instance,
    size_t capacity);

Exception priority_queue_enqueue(
    PriorityQueue instance, 
    Object item, 
    Object priority);

void finalize_priority_queue(PriorityQueue instance);
