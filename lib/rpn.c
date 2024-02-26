// Licensed under the MIT License.

#include <ctype.h>
#include "rpn.h"
#include "rpn_operator.h"

static RpnOperator rpn_get_operator(Rpn instance, String operator)
{
    switch (operator[0])
    {
        case '+': return instance->add;
        case '-': return instance->subtract;
        case '*': return instance->multiply;
        case '/': return instance->divide;
    }

    return NULL;
}

double rpn_evaluate(Rpn instance, String tokens[], size_t length)
{
    size_t sp = 0;
    double* stack = malloc(length * sizeof * stack);

    for (size_t i = 0; i < length; i++)
    {
        if (tokens[i][1] != '\0' || isdigit(tokens[i][0]))
        {
            stack[sp] = atof(tokens[i]);
            sp++;

            continue;
        }

        double left = stack[sp - 2];
        double right = stack[sp - 1];

        stack[sp - 2] = rpn_get_operator(instance, tokens[i])(left, right);
        sp--;
    }

    return stack[0];
}
