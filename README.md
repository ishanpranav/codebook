<!-- Licensed under the MIT License. -->

# Codebook

This is my C-language "book of code" for competitive programming problems.
Thanks to the depth and breadth of competitive programming problems, this
repository has become home to a [diverse library](lib/) including mathematical
functions, data structures, and algorithms.

- [Project Euler](#project-euler)
- [LeetCode](#leetcode)

## Why C?

C is a wonderful language because powerful abstractions come at an extremely low
cost. I can take liberties with my implementations (such as runtime generics)
while outperforming modern (bloated) alternatives, often by orders of magnitude.
Plus C is readable, elegant, and beautiful (sometimes).

## Constraints

- Adhere to the [project style guide](cstyle.md).
- Implement all final solutions following the C99 standard.
  - Assume that the English letter characters are ordered sequentially (i.e., no
    EBCDIC).
  - Assume that signed integer overflow is defined based on two's complement.

## Dependencies

This repository depends on the [GNU Multiple Precision Arithmetic Library
(GMP)](https://en.wikipedia.org/wiki/GNU_Multiple_Precision_Arithmetic_Library),
which is licensed under the GNU Lesser General Public License v3.0 (`LGPL-3.0`).

## Project Euler

|   Id   |                      Problem                       |             Domain             |        Result         | Implementation                                                                                 |
| :----: | :------------------------------------------------: | :----------------------------: | :-------------------: | ---------------------------------------------------------------------------------------------- |
|   1    |        [Multiples of 3 or 5](src/id0001.c)         |           Sequences            |          Sum          | [1 + 2 + 3 + 4 + ...](https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF)         |
|   2    |       [Even Fibonacci Numbers](src/id0002.c)       |           Sequences            |          Sum          | [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)                         |
|   3    |        [Largest Prime Factor](src/id0003.c)        |         Number theory          |        Maximum        | [Trial division](https://en.wikipedia.org/wiki/Trial_division)                                 |
|   4    |     [Largest Palindrome Product](src/id0004.c)     |         Number theory          |        Maximum        | [Palindromic number](https://en.wikipedia.org/wiki/Palindromic_number)                         |
|   5    |         [Smallest Multiple](src/id0005.c)          |         Number theory          | Least common multiple | [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)                       |
|   6    |       [Sum Square Difference](src/id0006.c)        |           Sequences            |      Difference       | [Square pyramidal number](https://en.wikipedia.org/wiki/Square_pyramidal_number)               |
|   7    |           [10001st Prime](src/id0007.c)            |         Number theory          |         Term          | [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)                   |
|   8    |    [Largest Product in a Series](src/id0008.c)     |      Dynamic programming       |        Maximum        | Sliding-window technique                                                                       |
|   9    |    [Special Pythagorean Triplet](src/id0009.c)     |            Geometry            |        Product        | [Euclid\'s formula](https://en.wikipedia.org/wiki/Pythagorean_triple)                          |
|   10   |        [Summation of Primes](src/id0010.c)         |         Number theory          |          Sum          |                                                                                                |
|   11   |     [Largest Product in a Grid](src/id0011.c)      |      Dynamic programming       |        Maximum        |                                                                                                |
|   12   | [Highly Divisible Triangular Number](src/id0012.c) |           Sequences            |         Term          | [Integer factorization](https://en.wikipedia.org/wiki/Integer_factorization)                   |
|   13   |             [Large Sum](src/id0013.c)              |           Arithmetic           |       Quotient        | [Floating-point arithmetic](https://en.wikipedia.org/wiki/Floating-point_arithmetic)           |
|   14   |      [Longest Collatz Sequence](src/id0014.c)      |           Sequences            |         Term          | [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture)                         |
|   15   |           [Lattice Paths](src/id0015.c)            |         Combinatorics          | Binomial coefficient  | [Binomial coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient)                     |
|   16   |          [Power Digit Sum](src/id0016.c)           | Arbitrary-precision arithmetic |          Sum          | [Arbitrary-precision arithmetic](https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic) |
|   17   |        [Number Letter Counts](src/id0017.c)        |         Combinatorics          |         Count         |                                                                                                |
| 18, 67 |          [Maximum Path Sum](src/id0018.c)          |      Dynamic programming       |        Maximum        | Bottom-up approach                                                                             |
|   19   |          [Counting Sundays](src/id0019.c)          |         Combinatorics          |         Count         |
|   20   |        [Factorial Digit Sum](src/id0020.c)         | Arbitrary-precision arithmetic |          Sum          |                                                                                                |
| 21  |      [Amicable Numbers](src/id0021.c)       | Number theory |           Sum           | [Amicable numbers](https://en.wikipedia.org/wiki/Amicable_numbers)                       |
| 22  |        [Names Scores](src/id0022.c)         |    Sorting    |           Sum           | [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)                     |
| 23  |      [Non-Abundant Sums](src/id0023.c)      | Number theory |           Sum           | [Abundant numbers](https://en.wikipedia.org/wiki/Abundant_number)                        |
| 24  | [Lexicographic Permutations](src/id0024.c)  | Combinatorics |       Permutation       | [Permutation](https://en.wikipedia.org/wiki/Permutation)                                 |
| 25  | [1000-digit Fibonacci Number](src/id0025.c) |   Sequences   |       Term number       | [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)                   |
| 26  |      [Reciprocal Cycles](src/id0026.c)      | Number theory |         Maximum         | [Full reptend prime](https://en.wikipedia.org/wiki/Full_reptend_prime)                   |
| 27  |      [Quadratic Primes](src/id0027.c)       | Number theory |         Product         |                                                                                          |
| 28  |   [Number Spiral Diagonals](src/id0028.c)   |   Sequences   |           Sum           | [Arithmetic sequence](https://en.wikipedia.org/wiki/Arithmetic_progression)              |
| 29  |       [Distinct Powers](src/id0029.c)       | Number theory |          Count          |                                                                                          |
| 30  |     [Digit Fifth Powers](src/id0030.c)      | Number theory |           Sum           |                                                                                          |
| 31  |          [Coin Sums](src/id0031.c)          | Combinatorics |        Partition        | [Partition function](<https://en.wikipedia.org/wiki/Partition_function_(number_theory)>) |
| 32  |     [Pandigital Products](src/id0032.c)     | Number theory |           Sum           | [Pandigital number](https://en.wikipedia.org/wiki/Pandigital_number)                     |
| 33  | [Digit Cancelling Fractions](src/id0033.c)  | Number theory | Greatest common divisor |                                                                                          |
| 34  |      [Digit Factorials](src/id0034.c)       | Combinatorics |           Sum           | [Factorial](https://en.wikipedia.org/wiki/Factorial)                                     |
| 35  |       [Circular Primes](src/id0035.c)       | Number theory |          Count          | [Circular prime](https://en.wikipedia.org/wiki/Circular_prime)                           |
| 36  |   [Double-base Palindromes](src/id0036.c)   | Number theory |           Sum           | [Radix](https://en.wikipedia.org/wiki/Radix)                                             |
| 37  |     [Truncatable Primes](src/id0037.c)      | Number theory |           Sum           | [Truncatable prime](https://en.wikipedia.org/wiki/Truncatable_prime)                     |
| 38  |    [Pandigital Multiples](src/id0038.c)     | Number theory |         Maximum         |                                                                                          |
| 39  |   [Integer Right Triangles](src/id0039.c)   |   Geometry    |         Maximum         |                                                                                          |
| 40  |  [Champernowne\'s Constant](src/id0040.c)   | Number theory |         Product         | [Champernowne constant](https://en.wikipedia.org/wiki/Champernowne_constant)             |
| 41  |           [Pandigital Prime](src/id0041.c)            |         Number theory          |   Maximum   |                                                                                                                                                                                                                                                                          |
| 42  |        [Coded Triangle Numbers](src/id0042.c)         |           Sequences            |    Count    |                                                                                                                                                                                                                                                                          |
| 43  |        [Sub-string Divisibility](src/id0043.c)        |         Number theory          |     Sum     |                                                                                                                                                                                                                                                                          |
| 44  |          [Pentagonal Numbers](src/id0044.c)           |           Sequences            |   Minimum   | [Pentagonal number](https://en.wikipedia.org/wiki/Pentagonal_number)                                                                                                                                                                                                     |
| 45  | [Triangular, Pentagonal, and Hexagonal](src/id0045.c) |           Sequences            |    Term     | [Hexagonal number](https://en.wikipedia.org/wiki/Hexagonal_number)                                                                                                                                                                                                       |
| 46  |     [Goldbach\'s Other Conjecture](src/id0046.c)      |         Number theory          |   Minimum   |                                                                                                                                                                                                                                                                          |
| 47  |        [Distinct Primes Factors](src/id0047.c)        |         Number theory          |    Term     |                                                                                                                                                                                                                                                                          |
| 48  |              [Self Powers](src/id0048.c)              | Arbitrary-precision arithmetic |   Modulus   |                                                                                                                                                                                                                                                                          |
| 49  |          [Prime Permutations](src/id0049.c)           |           Sequences            |    Terms    |                                                                                                                                                                                                                                                                          |
| 50  |         [Consecutive Prime Sum](src/id0050.c)         |         Number theory          |   Maximum   |                                                                                                                                                                                                                                                                          |
| 51  |       [Prime Digit Replacements](src/id0051.c)        |         Number theory          |   Minimum   |                                                                                                                                                                                                                                                                          |
| 52  |          [Permuted Multiples](src/id0052.c)           |         Combinatorics          |   Minimum   |                                                                                                                                                                                                                                                                          |
| 53  |        [Combinatoric Selections](src/id0053.c)        |         Combinatorics          |    Count    |                                                                                                                                                                                                                                                                          |
| 54  |              [Poker Hands](src/id0054.c)              |           Simulation           |    Count    | [Poker](https://en.wikipedia.org/wiki/Poker)                                                                                                                                                                                                                             |
| 55  |            [Lychrel Numbers](src/id0055.c)            |         Number theory          |    Count    | [Lychrel number](https://en.wikipedia.org/wiki/Lychrel_number)                                                                                                                                                                                                           |
| 56  |          [Powerful Digit Sum](src/id0056.c)           | Arbitrary-precision arithmetic |   Maximum   |                                                                                                                                                                                                                                                                          |
| 57  |        [Square Root Convergents](src/id0057.c)        | Arbitrary-precision arithmetic |    Count    | [Continued fraction expansion](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion)                                                                                                                                             |
| 58  |             [Spiral Primes](src/id0058.c)             |           Sequences            | Term number |                                                                                                                                                                                                                                                                          |
| 59  |            [XOR Decryption](src/id0059.c)             |          Cryptography          |     Sum     | [Frequency analysis](https://en.wikipedia.org/wiki/Frequency_analysis)                                                                                                                                                                                                   |
| 60  |            [Prime Pair Sets](src/id0060.c)            |         Number theory          |   Minimum   | [Miller–Rabin primality test](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test), [Modular exponentiation](https://en.wikipedia.org/wiki/Modular_exponentiation), [Exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring) |
| 61  |    [Cyclical Figurate Numbers](src/id0061.c)     |                 Number theory                 |    Sum    | [Polygonal number](https://en.wikipedia.org/wiki/Polygonal_number)                                                                     |
| 62  |        [Cubic Permutations](src/id0062.c)        |                 Number theory                 |  Minimum  | [Multimap](https://en.wikipedia.org/wiki/Multimap), [Daniel J. Bernstein (djb2) hash algorithm](http://www.cse.yorku.ca/~oz/hash.html) |
| 63  |      [Powerful Digit Counts](src/id0063.c)       |                 Number theory                 |   Count   |                                                                                                                                        |
| 64  |     [Odd Period Square Roots](src/id0064.c)      |                    Algebra                    |   Count   |                                                                                                                                        |
| 65  |         [Convergents of e](src/id0065.c)         |        Arbitrary-precision arithmetic         |   Count   |                                                                                                                                        |
| 66  |       [Diophantine Equation](src/id0066.c)       |        Arbitrary-precision arithmetic         |  Maximum  | [Pell\'s equation](https://mathworld.wolfram.com/PellEquation.html)                                                                    |
| 68  |         [Magic 5-gon Ring](src/id0068.c)         |                 Magic shapes                  |  Maximum  | [Magic square](https://en.wikipedia.org/wiki/Magic_constant)                                                                           |
| 69  |         [Totient Maximum](src/id0069.c)          |                 Number theory                 | Primorial | [Euler\'s totient function](https://en.wikipedia.org/wiki/Euler%27s_totient_function)                                                  |
| 70  |       [Totient Permutation](src/id0070.c)        |                 Number theory                 |  Minimum  |                                                                                                                                        |
| 71  |        [Ordered Fractions](src/id0071.c)         |                   Sequences                   |   Term    | [Farey sequence](https://en.wikipedia.org/wiki/Farey_sequence)                                                                         |
| 72  |        [Counting Fractions](src/id0072.c)        |                 Number theory                 |   Count   | [Totient summatory function](https://en.wikipedia.org/wiki/Totient_summatory_function)                                                 |
| 73  |  [Counting Fractions in a Range](src/id0073.c)   |                   Sequences                   |   Count   |                                                                                                                                        |
| 74  |      [Digit Factorial Chains](src/id0074.c)      |                 Combinatorics                 |   Count   |                                                                                                                                        |
| 75  | [Singular Integer Right Triangles](src/id0075.c) |                   Geometry                    |   Count   |                                                                                                                                        |
| 76  |       [Counting Summations](src/id0076.c)        |                 Combinatorics                 | Partition |                                                                                                                                        |
| 77  |         [Prime Summations](src/id0077.c)         |                 Combinatorics                 |   Term    |                                                                                                                                        |
| 78  |         [Coin Partitions](src/id0078.c)          |                 Combinatorics                 |   Term    | [Pentagonal number theorem](https://en.wikipedia.org/wiki/Pentagonal_number_theorem)                                                   |
| 79  |       [Passcode Derivation](src/id0079.c)        |                 Graph theory                  |  Minimum  | [Adjacency matrix](https://en.wikipedia.org/wiki/Adjacency_matrix)                                                                     |
| 80  |  [Square Root Digital Expansion](src/id0080.c)   | Arbitrary-precision floating point arithmetic |    Sum    |                                                                                                                                        |
| 81  |  [Path Sum: Two Ways](src/id0081.c)  | Graph theory | Minimum path |                                                                                                      |
| 82  | [Path Sum: Three Ways](src/id0082.c) | Graph theory | Minimum path |                                                                                                      |
| 83  | [Path Sum: Four Ways](src/id0083.c)  | Graph theory | Minimum path |                                                                                                      |
| 84  |    [Monopoly Odds](src/id0084.c)     |  Simulation  |    Maxima    | Blackman and Vigna's [xoshiro256\*\*](https://en.wikipedia.org/wiki/Xorshift#xoshiro256**) algorithm |
| 85  | [Counting Rectangles](src/id0085.c)  |   Geometry   |     Area     |                                                                                                      |
| 86 | [Cuboid Route](src/id0086.c) | Geometry | Minimum | |
| 87 | [Prime Power Triples](src/id0087.c) | Number theory | Count | [Hash set](https://en.wikipedia.org/wiki/Hash_table) |

## LeetCode

|  Id  |                                 Problem                                  |    Domain     |        Result        | Implementation        |
| :--: | :----------------------------------------------------------------------: | :-----------: | :------------------: | --------------------- |
|  7   |                     [Reverse Integer](src/lc0007.c)                      |  Mathematics  |       Integer        | `math_reverse`        |
|  8   |                    [String to Integer](src/lc0008.c)                     |    Strings    |       Integer        | `atoll`               |
|  9   |                    [Palindrome Number](src/lc0009.c)                     |  Mathematics  |       Boolean        | `math_is_palindrome`  |
|  23  |                   [Merge k Sorted Lists](src/lc0023.c)                   | Linked Lists  |     Linked List      | `PriorityQueue`       |
|  28  |    [Find the Index of the First Occurrence in a String](src/lc0028.c)    |    Strings    |        Index         | `strstr`              |
|  29  |                   [Divide Two Integers](src/lc0029.c)                    |  Mathematics  |       Quotient       |                       |
|  31  |                     [Next Permutation](src/lc0031.c)                     |     Array     |     Permutation      | `PermutationIterator` |
|  46  |                       [Permutations](src/lc0046.c)                       |     Array     |     Permutation      | `PermutationIterator` |
| 49 | [Group Anagrams](src/lc0049.c) | Combinatorics | Sort | `Lookup` |
|  50  |                        [Pow(x, n)](src/lc0050.c)                         |  Mathematics  |        Power         | `pow`                 |
|  60  |                   [Permutation Sequence](src/lc0060.c)                   |  Mathematics  |     Permutation      | `PermutationIterator` |
|  62  |                       [Unique Paths](src/lc0062.c)                       | Combinatorics | Binomial coefficient | `binomial`            |
|  69  |                         [Sqrt(x)](src/lc0069.c)                          |  Mathematics  |     Square root      | `sqrt`                |
|  75  |                       [Sort Colors](src/lc0075.c)                        |    Sorting    |         Sort         | `qsort`               |
| 367  |                   [Valid Perfect Square](src/lc0367.c)                   |  Mathematics  |       Boolean        | `math_is_polygonal`   |
| 2119 |             [A Number After a Double Reversal](src/lc2119.c)             |  Mathematics  |       Boolean        | `math_reverse`        |
| 2400 | [Number of Ways to Reach a Position After Exactly k Steps](src/lc2400.c) | Combinatorics | Binomial coefficient | `mod_binomial_range`            |
| 2550 |                       [Monkey Move](src/lc2550.c)                        | Combinatorics |        Power         | `mod_pow`             |
