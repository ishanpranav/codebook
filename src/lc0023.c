// Licensed under the MIT License.

// Merge k Sorted Lists

#include "../lib/euler.h"
#include "../lib/priority_queue.h"

static struct ListNode
{
    int val;
    struct ListNode* next;
};

static int list_node_comparer(const void* left, const void* right)
{
    struct ListNode* p = *(const struct ListNode**)left;
    struct ListNode* q = *(const struct ListNode**)right;

    return p->val - q->val;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (!listsSize)
    {
        return NULL;
    }

    struct PriorityQueue priorityQueue;

    euler_ok(priority_queue(
        &priorityQueue,
        0,
        sizeof(struct ListNode*),
        listsSize,
        list_node_comparer));

    struct ListNode* head = calloc(1, sizeof * head);

    head->val = 1;

    int out;
    struct ListNode* tail = head;

    for (int i = 0; i < listsSize; i++)
    {
        if (!lists[i])
        {
            continue;
        }

        euler_ok(priority_queue_enqueue(&priorityQueue, &out, lists + i));
    }

    while (priority_queue_try_dequeue(&priorityQueue, &out, &tail->next))
    {
        tail = tail->next;

        if (tail && tail->next)
        {
            euler_ok(priority_queue_enqueue(&priorityQueue, &out, &tail->next));
        }
    }

    return head->next;
}
