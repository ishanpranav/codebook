// Licensed under the MIT License.

#include "rpn.h"
#include "rpn_operator.h"

int rpn_evaluate(String tokens[], size_t length)
{
    size_t sp = 0;
    int* stack = malloc(length * sizeof * stack);

    for (size_t i = 0; i < length; i++)
    {
        if (tokens[i][1] != '\0' || isdigit(tokens[i][0]))
        {
            stack[sp] = atoi(tokens[i]);
            sp++;

            continue;
        }

        stack[sp - 2] = rpn_operator_apply(
            tokens[i][0], 
            stack[sp - 2], 
            stack[sp - 1]);
        sp--;
    }
    
    return stack[0];
}
