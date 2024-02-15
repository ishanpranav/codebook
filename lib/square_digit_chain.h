// Licensed under the MIT License.

/** Represents a square digit chain used to compute happy numbers. */
struct SquareDigitChain
{
    int cache[568];
};

/** Represents a square digit chain used to compute happy numbers. */
typedef struct SquareDigitChain* SquareDigitChain;

/**
 * Initializes a new `SquareDigitChain` instance.
 * 
 * @param instance the `SquareDigitChain` instance.
*/
void square_digit_chain(SquareDigitChain instance);

/** 
 * Gets the terminal value of the square digit chain for a given value.
 * 
 * @param instance the `SquareDigitChain` instance.
 * @param n        the value to test.
 * @return The terminal value (`1` or `89`) of the square digit chain of `n`.
 *         If the terminal value is `1`, `n` is a happy number.
*/
int square_digit_chain_get(SquareDigitChain instance, long n);
