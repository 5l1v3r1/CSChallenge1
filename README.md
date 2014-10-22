# Purpose

I wrote this challenge for my friend to help him test his CS skills. His college CS course requires him to know the following topics in C:

    * Memory allocation through malloc() & free().
    * Structures
    * File I/O through <stdio.h>
    * String manipulation functions

# Challenge

Included is a file called [numbers.dat](numbers.dat). It is a raw binary file which contains a list of 64-bit structures. The first 32-bits in each structure contains a signed integer value `x`, the second 32-bits contains a signed integer value `y`.

Your challenge is to read every structure in [numbers.dat](numbers.dat), and for each 64-bit structure, compute an integer `z` where `z = x / y` (here, the / operator is integer division which chops off the decimal place). Then, compute the arithmetic mean of all the values of `z`. The mean you compute should be rounded down to the last integer. Then, turn this integer value into a string and reverse the string. Finally, print out the reversed string.

# Example

Suppose the file is as follows (hexadecimal format):

    20 00 00 00 02 00 00 00
    40 00 00 00 03 00 00 00

This file contains the following two structures:

    (x = 32, y = 2)
    (x = 64, y = 3)

The values `z` for both of these structures can be computed:

    z = 32/2 = 16
    z = 64/3 = 21

The arithmetic mean, rounded down to the nearest integer, can be found:

    mean = (16 + 21) / 2 = 37 / 2 = 18

The string version of the mean is "18", so the program should print out "81".