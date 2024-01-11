// Licensed under the MIT License.

/** Represents text as a zero-terminated sequence of characters. */
typedef char* LPString;

/** Represents an opaque type. */
typedef const void* Object;

/**
 * Creates a new instance of `LPString` with the same value as a specified
 * `LPString`.
 * 
 * @param instance the `LPString` instance to copy.
 * @return A new string with the same value.
 */
LPString lp_string_clone(LPString instance);

/**
 * Compares `left` with `right` and returns an integer that indicates whether
 * `left` precedes, follows, or appears in the same position in the sort order
 * as `right`.
 * 
 * @param left  a string to compare to `right`.
 * @param right a string to compare to `left`.
 * @return A signed integer that indicates the relative values of `left` and 
 *         `right`. 
*/
int lp_string_compare(Object left, Object right);
