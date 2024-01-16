// Licensed under the MIT License.

/**  Specifies a divisor iterator's state. */
enum DivisorIteratorState
{
    /** The initial state. */
    DIVISOR_ITERATOR_STATE_INITIAL,

    /** The state during which the iterator checks the next pair of divisors. */
    DIVISOR_ITERATOR_STATE_SWAP,

    /** The state during which the iterator provides a paired divisor. */
    DIVISOR_ITERATOR_STATE_YIELD
};
