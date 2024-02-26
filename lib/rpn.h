// Licensed under the MIT License.

#include "euler.h"

/** Represents a reverse Polish notation parser. */
struct Rpn
{
    double (*add)(double left, double right);
    double (*subtract)(double left, double right);
    double (*multiply)(double left, double right);
    double (*divide)(double left, double right);
};

/** Represents a reverse Polish notation parser. */
typedef struct Rpn* Rpn;

/**
 * Evaluates a sequence of tokens in reverse Polish notation.
 * 
 * @param instance the `Rpn` instance.
 * @param tokens   the sequence of tokens consisting of operators and operands.
 * @param length   the number of tokens.
 * @return The evaluated expression.
*/
int rpn_evaluate(Rpn instance, String tokens[], size_t length);
