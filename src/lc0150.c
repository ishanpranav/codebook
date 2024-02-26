// Licensed under the MIT License.

// Evaluate Reverse Polish Notation

#include "../lib/rpn.h"

int evalRPN(String tokens[], int tokensSize) 
{
    struct Rpn rpn =
    {
        .add = operator_add,
        .subtract = ,
        .multiply = rpn_multiply,
        .divide = rpn_div
    };

    return rpn_evaluate(&rpn, tokens, tokensSize);
}
