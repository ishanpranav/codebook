// Licensed under the MIT License.

/** Represents a binary mathematical operator in reverse Polish notation. */
typedef double (*Operator)(double left, double right);

/**
 * Adds two operands.
 * 
 * @param left  the left addend.
 * @param right the right addend.
 * @return The sum of `left` and `right`.
*/
double add_operator(double left, double right);

/**
 * Subtracts one operand from an other.
 * 
 * @param left  the left addend.
 * @param right the right addend.
 * @return The difference of `left` and `right`.
*/
double subtract_operator(double left, double right);

/**
 * Multiplies two operands.
 * 
 * @param left  the left factor.
 * @param right the right factor.
 * @return The product of `left` and `right`. 
*/
double multiply_operator(double left, double right);

/**
 * Performs integer division between two operands.
 * 
 * @param left  the dividend.
 * @param right the divisor.
 * @return The integer quotient of `left div right`.
*/
double div_operator(double left, double right);
