// Licensed under the MIT License.

enum RpnOperator
{
    RPN_OPERATOR_ADD = '+',
    RPN_OPERATOR_SUBTRACT = '-',
    RPN_OPERATOR_MULTIPLY = '*',
    RPN_OPERATOR_DIVIDE = '/'
};

typedef enum RpnOperator RpnOperator;

int rpn_operator_apply(RpnOperator value, int left, int right);
