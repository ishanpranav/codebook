// Licensed under the MIT License.

#include "string_builder.h"

/**
 * Converts a single-character Roman numeral to the integer that it represents.
 *  
 * @param value the numeral character.
 * @return The integral value of the given numeral; otherwise, `0`.
*/
int roman_from_char(char value);

/**
 * Converts a Roman numeral string to the integer that it represents.
 * 
 * @param value the numeral string.
 * @return The integral value of the given numeral; otherwise, `0`.
*/
int roman_from_string_builder(StringBuilder value);

/**
 * Determines the length of an integer when expressed as a modern minimal
 * subtractive Roman numeral.
 * 
 * @param value the integral value.
 * @return The length of the given value when expressed as a Roman numeral.
*/
size_t roman_length(int value);

/**
 * Converts an integer into a Roman numeral string.
 * 
 * @param result when this method returns, contains a modern minimal subtractive
 *               Roman numeral string that represents the given value. This
 *               argument is passed uninitialized. The caller is responsible.
 * @param value  the integral value.
 * @return An exception; otherwise `0`.
*/
Exception roman_to_string_builder(StringBuilder result, int value);
