# Project Euler

Efficient Project Euler solutions in C language

## Constraints

- Adhere to the [project style guide](cstyle.md).
- Implement all solutions following the C99 standard.
  - Assume that the English letter characters are ordered sequentially (i.e., no
    EBCDIC).

## Attribution

This repository depends on the
[GNU Multiple Precision Arithmetic Library (GMP)](https://en.wikipedia.org/wiki/GNU_Multiple_Precision_Arithmetic_Library),
which is licensed under the GNU Lesser General Public License v3.0 (`LGPL-3.0`).

## Summary

### 1-20, 67

|   Id   |                      Problem                       |             Domain             |        Result         | Implementation                                                                                 |
| :----: | :------------------------------------------------: | :----------------------------: | :-------------------: | ---------------------------------------------------------------------------------------------- |
|   1    |        [Multiples of 3 or 5](src/id0001.c)         |           Sequences            |          Sum          | [1 + 2 + 3 + 4 + ...](https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF)         |
|   2    |       [Even Fibonacci Numbers](src/id0002.c)       |           Sequences            |          Sum          | [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)                         |
|   3    |        [Largest Prime Factor](src/id0003.c)        |         Number theory          |        Maximum        | [Trial division](https://en.wikipedia.org/wiki/Trial_division)                                 |
|   4    |     [Largest Palindrome Product](src/id0004.c)     |         Number theory          |        Maximum        | [Palindromic number](https://en.wikipedia.org/wiki/Palindromic_number)                         |
|   5    |         [Smallest Multiple](src/id0005.c)          |         Number theory          | Least common multiple | [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)                       |
|   6    |       [Sum Square Difference](src/id0006.c)        |           Sequences            |      Difference       | [Square pyramidal number](https://en.wikipedia.org/wiki/Square_pyramidal_number)               |
|   7    |           [10001st Prime](src/id0007.c)            |         Number theory          |         Term          | [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)                   |
|   8    |    [Largest Product in a Series](src/id0008.c)     | Sequences, Dynamic programming |        Maximum        | Sliding-window technique                                                                       |
|   9    |    [Special Pythagorean Triplet](src/id0009.c)     |            Geometry            |        Product        | [Euclid\'s formula](https://en.wikipedia.org/wiki/Pythagorean_triple)                          |
|   10   |        [Summation of Primes](src/id0010.c)         |         Number theory          |          Sum          |                                                                                                |
|   11   |     [Largest Product in a Grid](src/id0011.c)      |      Dynamic programming       |        Maximum        |                                                                                                |
|   12   | [Highly Divisible Triangular Number](src/id0012.c) |         Number theory          |        Optimum        | [Integer factorization](https://en.wikipedia.org/wiki/Integer_factorization)                   |
|   13   |             [Large Sum](src/id0013.c)              |           Arithmetic           |          Sum          | [Floating-point arithmetic](https://en.wikipedia.org/wiki/Floating-point_arithmetic)           |
|   14   |      [Longest Collatz Sequence](src/id0014.c)      |           Sequences            |        Optimum        | [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture)                         |
|   15   |           [Lattice Paths](src/id0015.c)            |         Combinatorics          | Binomial coefficient  | [Binomial coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient)                     |
|   16   |          [Power Digit Sum](src/id0016.c)           | Arbitrary-precision arithmetic |          Sum          | [Arbitrary-precision arithmetic](https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic) |
|   17   |        [Number Letter Counts](src/id0017.c)        |         Combinatorics          |         Count         |                                                                                                |
| 18, 67 |          [Maximum Path Sum](src/id0018.c)          |      Dynamic programming       |        Maximum        | Bottom-up approach                                                                             |
|   19   |          [Counting Sundays](src/id0019.c)          |         Combinatorics          |         Count         |
|   20   |        [Factorial Digit Sum](src/id0020.c)         | Arbitrary-precision arithmetic |          Sum          |                                                                                                |

### 21-40

| Id  |                   Problem                   |    Domain     |         Result          | Implementation                                                              |
| :-: | :-----------------------------------------: | :-----------: | :---------------------: | --------------------------------------------------------------------------- |
| 21  |      [Amicable Numbers](src/id0021.c)       | Number theory |           Sum           | [Amicable numbers](https://en.wikipedia.org/wiki/Amicable_numbers)          |
| 22  |        [Names Scores](src/id0022.c)         |    Sorting    |           Sum           | [Quicksort](https://en.wikipedia.org/wiki/Quicksort)                        |
| 23  |      [Non-Abundant Sums](src/id0023.c)      | Number theory |           Sum           | [Abundant numbers](https://en.wikipedia.org/wiki/Abundant_number)           |
| 24  | [Lexicographic Permutations](src/id0024.c)  | Combinatorics |       Permutation       | [Permutation](https://en.wikipedia.org/wiki/Permutation)                    |
| 25  | [1000-digit Fibonacci Number](src/id0025.c) | Number theory |       Term number       | [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)      |
| 26  |      [Reciprocal Cycles](src/id0026.c)      | Number theory |         Optimum         | [Full reptend prime](https://en.wikipedia.org/wiki/Full_reptend_prime)      |
| 27  |      [Quadratic Primes](src/id0027.c)       | Number theory |         Product         |                                                                             |
| 28  |   [Number Spiral Diagonals](src/id0028.c)   |   Sequences   |           Sum           | [Arithmetic sequence](https://en.wikipedia.org/wiki/Arithmetic_progression) |
| 29  |       [Distinct Powers](src/id0029.c)       | Number theory |          Count          |                                                                             |
| 30  |     [Digit Fifth Powers](src/id0030.c)      | Number theory |           Sum           |                                                                             |
| 31  |          [Coin Sums](src/id0031.c)          | Combinatorics |          Count          | Dynamic programming                                                         |
| 32  |     [Pandigital Products](src/id0032.c)     | Number theory |           Sum           |                                                                             |
| 33  | [Digit Cancelling Fractions](src/id0033.c)  | Number theory | Greatest common divisor |                                                                             |
| 34 | [Digit Factorials](src/id0034.c) | Number theory | Sum | [Factorial](https://en.wikipedia.org/wiki/Factorial) |
| 35 | [Circular Primes](src/id0035.c) | Number theory | Count | [Circular prime](https://en.wikipedia.org/wiki/Circular_prime) |
| 36 | [Double-base Palindromes](src/id0036.c) | Number theory | Sum | [Radix](https://en.wikipedia.org/wiki/Radix) |
| 37 | [Truncatable Primes](src/id0037.c) | Number theory | Sum | [Truncatable prime](https://en.wikipedia.org/wiki/Truncatable_prime) |
| 38 | [Pandigital Multiples](src/id0038.c) | Number theory | Maximum | |
| 39 | [Integer Right Triangles](src/id0039.c) | Geometry | Maximum | |
| 40 | [Champernowne\'s Constant](src/id0040.c) | Number theory | Product | [Champernowne constant](https://en.wikipedia.org/wiki/Champernowne_constant) |

### 41-
