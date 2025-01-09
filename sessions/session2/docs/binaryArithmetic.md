[session2](../../session2/) | [Binary Arithmetic](../docs/binaryArithmetic.md)

# Binary Arithmetic

Computers work with binary number and in this section we will review some basic binary arithmetic.

## Binary and Hexadecimal representation of numbers

Because computers work with binary numbers it is important to be familiar with binary and hexadecimal notation.

Hexadecimal notation (Hex) is used to represent 4 bits as a range of 16 numbers 0 through 9 and A-F.

Hex is easier for humans to read and write than simple binary.

Bottom 4 bits of an 8 bit byte

8 + 4 + 2 + 1 = 15

| decimal | binary | hexadecimal |
|:------- |:-------|:------------|
| 0       | 0000   | 00          |
| 1       | 0001   | 01          |
| 2       | 0010   | 02          |
| 3       | 0011   | 03          |
| 4       | 0100   | 04          |
| 5       | 0101   | 05          |
| 6       | 0110   | 06          |
| 7       | 0111   | 07          |
| 8       | 1000   | 08          |
| 9       | 1001   | 09          |
| 10      | 1010   | 0A          |
| 11      | 1011   | 0B          |
| 12      | 1100   | 0C          |
| 13      | 1101   | 0D          |
| 14      | 1110   | 0E          |
| 15      | 1111   | 0F          |

Top 4 bits of an 8 bit byte

128 + 64 + 32 + 16 = 240

11111111 = FF = 255 

128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 255 = FF


| decimal | binary | hexadecimal |
|:------- |:-------|:------------|
| 0       | 00000000   | 00      |
| 16      | 00010000   | 10      |
| 32      | 00100000   | 20      |
| 48      | 00110000   | 30      |
| 64      | 01000000   | 40      |
| 80      | 01010000   | 50      |
| 96      | 01100000   | 60      |
| 112     | 01110000   | 70      |
| 128     | 10000000   | 80      |
| 144     | 10010000   | 90      |
| 160     | 10100000   | A0      |
| 176     | 10110000   | B0      |
| 192     | 11000000   | C0      |
| 208     | 11010000   | D0      |
| 224     | 11100000   | E0      |
| 240     | 11110000   | F0      |

If you want a little practice with binary numbers try the cisco binary game 

[cisco binary game](https://learningnetwork.cisco.com/s/binary-game)

[cisco binary game NOTES](https://learningcontent.cisco.com/games/binary/index.html)

If you want a little practice with Hexadecimal numbers try the HEX game

[HEX GAME](https://studio.code.org/projects/applab/q5Mw0Zhs58a_Chr-zn75thpwnjMTw6n2hh_2aN1hwSE)  Enter the hexadecimal value in the green box. If you see a hexadecimal number on the right, click the bits to make the binary number match.

Also try using the [hex calculator](https://www.calculator.net/hex-calculator.html)

## Binary Addition and 2s compliment Arithmetic

The above examples all used unsigned (i.e. positive) integer numbers (0-254). 
In a real system, we also need to represent negative numbers.

Although other representations are possible, modern computers use 2's compliment arithmetic to represent negative numbers. 

An 8 bit byte can represent 0-254 if it is unsigned or -128 to +127 if it is signed.

With a signed binary number, the first bit tells about the sign. 
The convention is that a number with a leading 1 is negative, while a leading 0 denotes a positive value.

To convert a positive binary number to a negative number a simple trick is to a) invert all of the bits in the number and b) add 1

| decimal | binary of decimal | invert    | 2s compliment (add 1)| negative decimal |
|:--------|:------------------|:----------|:---------------------|:-----------------|
|123      | 01111011          | 10000100  | 10000101             | -123             |

You can prove that 10000101 is the negative value of 01111011 by adding them together.


|         | decimal | binary of decimal |
|:--------|:--------|:------------------|
|         | 123     | 01111011         | 
|ADD      |-123     | 10000101         | 
|RESULT   |   0     | 00000000         | 


You can also use the [twos-complement calculator](https://www.omnicalculator.com/math/twos-complement) to check your calculations and try other examples.

Note that to simplify circuit design, computers often avoid subtraction by changing the number to be subtracted to its 2s compliment and then adding it.

e.g. 144 – 156 = 144 + (-156) = 1001 0000 + 0110 0100 = 1111 0100.

To understand this better, have a look at [Tom Finley 2000 Tutorial on 2s Compliment](https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html)

## Binary Multiplication

A naively simple way to multiply binary numbers would be to use a loop to add the multiplicand to the total repeatedly for the number of times in the multiplier. 
This would work but could take a very long time. 

The faster method is to shift and add the multiplicand (which for an 8 bit multiplier would require a maximum of 8 iterations).

Binary multiplication involves shifting and adding the multiplicand for each 1 encountered in the multiplier.
Note that the result can require 2 times as many bits as the original operands.

```
   00001011   (this is binary for decimal 11)
 * 00001110   (this is binary for decimal 14)
   ========
   00000000   (this is 1011 × 0)
   00010110   (this is 1011 × 1, shifted one position to the left)
   00101100   (this is 1011 × 1, shifted two positions to the left)
   01011000   (this is 1011 × 1, shifted three positions to the left)
  =========
   10011010   (this is binary for decimal 154)

```

See [wikipedia Binary Multiplication](https://en.wikipedia.org/wiki/Binary_multiplier)

This also works for negative numbers but you must sign-extend the intermediate products.
For some examples and explanation see [Mark Hill Two's Complement Multiplication](https://pages.cs.wisc.edu/%7Emarkhill/cs354/Fall2008/beyond354/int.mult.html)

## Binary Division
A naively simple way to multiply binary numbers would be to use a loop to count how many times you can subtract the divisor from the total until it is no longer possible to subtract the divisor. 
The number left after repeated subtraction would be the remainder.

Like multiplication, binary division can be speeded up using shifting . 

```
Divisor = 1011(11 decimal) and Dividend = 10010011 (147 decimal)
      00001101    Quotient
    |---------
1011| 10010011
    - 01011000
      --------  
      00111011    Partial remainder
    - 00101100
      --------
      00001111    Partial remainder
      00000000    (note cannot subtract 00010110 from 00001111 without going negative - hence 0 multiplier)
      --------
      00001111    Partial remainder
    - 00001011
      --------
           100    Remainder

Answer(decimal) = 13 remainder 4 
```

## Fraction and Floating point number representation

(this is for interest but more complex than foundation computing requires)

For very large or very small numbers, we usually want to use scientific notation to avoid having unfeasibly large numbers of bits. 

[Tom Finley 2000 Tutorial on binary floating point](https://www.cs.cornell.edu/~tomf/notes/cps104/floating.html) explains a commonly used  IEEE 754 floating-point standard.

In this case we can use 32 bits to represent a positive or negative number in the range ±1.18×10^−38 to ±3.4×10^38

| Sign | Exponent |  Mantissa |
|:---- |:---------|:----------|
|1 bit |8 bits    |23 bits    |  
|X     |XXXXXXXX  |XXXXXXXXXXXXXXXXXXXXXXX|






