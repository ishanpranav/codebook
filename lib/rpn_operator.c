// Licensed under the MIT License.

#include "rpn_operator.h"

int rpn_operator_apply(RpnOperator value, int left, int right)
{
    switch (value)
    {
        case RPN_OPERATOR_ADD: return left + right;
        case RPN_OPERATOR_SUBTRACT: return left - right;
        case RPN_OPERATOR_MULTIPLY: return left * right;
        case RPN_OPERATOR_DIVIDE: return left / right;
    }

    return 0;
}
