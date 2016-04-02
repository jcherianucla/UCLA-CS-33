/*
 * CS:APP Data Lab
 *
 * <Jahan Kuruvilla Cherian 104436427>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right counters arithmetically.
  3. Has unpredictable behavior when countering an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of counters to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of counters to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int bitNumber = 0;
	int sixteen, eight, four, two, one,counter;
	counter = (x>>31)^ x; //If we have a negative, then give its complement to get rid of any excess leading ones as we care only about the minimum, else just give the positive version
	//We now wish to perform a binary search on the entir 32-bit vector to check for the positions of the 1's in a log2(x) operation
	sixteen = !!(counter >> 16) << 4;
	counter >>= sixteen;
	bitNumber +=  sixteen;	//Add all the bits found in the two halves of 16's
	eight = !!(counter >> 8) << 3;
	counter >>= eight;
	bitNumber +=  eight;	//Add all the bits found in the two halves of 8's;
	four = !!(counter >> 4) << 2;
	counter >>= four;
	bitNumber += four;	//Add all the bits found in the two halves of 4's;
	two = !!(counter >> 2) << 1;
	counter >>= two;
	bitNumber += two; //Add all the bits found in the two halves of 2's;
	one = !!(counter >> 1);
	bitNumber += one; //Add all the bits found in the one;
	bitNumber +=  2; //We then add all the bits found in the different searches and add an offset of two to account for the signed bit and the 0 in the change from negative to positive.
	return (bitNumber& (!counter+~0)) | !counter;	//This then returns the counter unless we had a 0 or -1 where it return 1, because we mask bitNumber with a mask thats all 1's or all 0's depending on whether we had 0 or a nonzero value, and we then OR it with 0 if the value was nonzero or 1 if the value was 0..
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
        int negativeDeterminer = x >> 31;	//Is 0xFFFFFFFF (negative) or 0x00000000 (positive)
        int mask = ~(~0 << 31);	//Create a mask of 0x7FFFFFFF to mask out the signed bit
        return ((negativeDeterminer) & (~(x&mask)+1)) | ((~negativeDeterminer)&x);	//If x is negative we mask the wanted bits and make it absolute value else return x
}/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
	return !(x>>31);	//Returns the ! of 0xFFFFFFF which means it was negative, which will evaluate to 0 or 0x00000000 which means it was positive and thus 1.
}

/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
	int shifter = (!n + ~0) & (32 + ~n + 1);	//Determine if the shifter is 0 or 32-n depending on if n is zero or above respectively
	int mask_1 = (x>>n) & ~(~0 << shifter);		//Move x over to cover up the wanted bits and then ensure that a holder of size n is created at the leftmost end for the extracted bits
	int mask_2 = x << shifter;	//Extract the bits we want
	return mask_1 | mask_2;	//Or'ing the results will move the extracted bits into the holder spot
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	int negativeDeterminer = x >> 31;	//Is 0xFFFFFFFF if its negative and 0x00000000 if its positive
	int bias = (negativeDeterminer) & ((1 << n) + ~0);	//If x is positive make the bias zero else make the bias (1 << n) -n
	return (x+bias) >> n;	//Sum the bias and right shift to perform the division by power of 2
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int start = 0x55;	//Create a mask of all even 1's: 0101 0101
	int mask_one = start | (start << 8);
	int mask_two = mask_one | (mask_one << 16);	//Sign extend it to 32-bits
	return !(~((x & ~mask_two) + ~~mask_two));	//Invert this to make it a mask of odd 1's and then and it to get whether there are all odds or not
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	return ((~(~x & ~y)) & (~(x & y)));
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	return !((~x+1) ^  x) & !!(x);	//~x+1 == x for Tmin and 0, so we check that its not zero and return if this case is true
}
