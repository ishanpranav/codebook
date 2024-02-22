// Licensed under the MIT License.

// Evaluate Reverse Polish Notation

#include "../lib/rpn.h"

int evalRPN(String tokens[], int tokensSize) 
{
    return rpn_evaluate(tokens, tokensSize);
}
