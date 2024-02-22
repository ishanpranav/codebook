// Licensed under the MIT License.

/** Represents a binary mathematical operator in reverse Polish notation. */
enum RpnOperator
{
    /** The addition operator. */
    RPN_OPERATOR_ADD = '+',

    /** The subtraction operator. */
    RPN_OPERATOR_SUBTRACT = '-',

    /** The multiplication operator. */
    RPN_OPERATOR_MULTIPLY = '*',

    /** The division operator. */
    RPN_OPERATOR_DIVIDE = '/'
};

/** Represents a binary mathematical operator in reverse Polish notation. */
typedef enum RpnOperator RpnOperator;

/**
 * Applies the given binary operator on two operands.
 * 
 * @param left  the left operand.
 * @param right the right operand.
 * @return The result of applying the given `value` on `left` and `right`.
*/
int rpn_operator_apply(RpnOperator value, int left, int right);
