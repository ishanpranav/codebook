// Licensed under the MIT License.

#include <stddef.h>

struct Graph
{
    void* (*neighbors)(void* instance, void* vertex, size_t* degree);
    int (*weight)(void* instance, void* source, void* target);
};

typedef struct Graph* Graph;
