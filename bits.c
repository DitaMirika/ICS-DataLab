/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void){
	return 1<<31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x,int y){
	return ~(~x&~y)&~(x&y);
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
	return (~x+1)&(x>>31);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x,int src,int dst){
	int l=src<<3,r=dst<<3;
	int b=(x>>l)&255,m=255<<r;
	return (x&~m)|(b<<r);
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x,int n){
	int m=~(1<<31);
	m=((m>>n)<<1)|1;
	return (x>>n)&m;
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x){
	int m=15|(15<<8);
	int l,r;
	m=m|(m<<16);
	l=(x&m)<<4; r=(x>>4)&m;
	return l|r;
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x){
	int y=~x;
	y=y&(y+~0);
	return y&(~y+1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x){
	x=x^(x>>16);
	x=x^(x>>8);
	x=x^(x>>4);
	x=x^(x>>2);
	x=x^(x>>1);
	return !(x&1);
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x,int n){
	int k=n&31,l=(~k+1)&31;
	int m=~(1<<31),a,b;
	m=((m>>k)<<1)|1;
	a=(x>>k)&m; b=x<<l;
	return a|b;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x,int n){
	int q=x>>n,m=(1<<n)+~0;
	int r=x&m,h=1<<(n+~0);
	int gt=((h+~r+1)>>31)&1,eq=!(r^h);
	int up=gt|(eq&(q&1));
	return (q+up)<<n;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x,int y){
	int a=x>>1,b=y>>1,rx=x&1,ry=y&1;
	int mid=a+b+(rx&ry),d=b+~a+1;
	int gt=((d>>31)&1)|((!d)&rx&(!ry));
	return mid+((rx^ry)&gt);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x,int a,int b){
	int s=x>>31,sa=a>>31,sb=b>>31;
	int da=(x+~a+1)>>31,db=(x+~b+1)>>31;
	int pa=s^sa,pb=s^sb;
	int la=((pa&s)|(~pa&da))&1,lb=((pb&s)|(~pb&db))&1;
	int ea=!(x^a),eb=!(x^b);
	int gea=!la,lea=la|ea,geb=!lb,leb=lb|eb;
	return (gea&leb)|(geb&lea);
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x){
	int a=x+x,b=a+a,c=b+x;
	int s=x>>31;
	int o1=(x^a)>>31,o2=(a^b)>>31,o3=(x^c)>>31;
	int o=o1|o2|o3;
	int lo=1<<31,hi=~lo;
	int t=(s&lo)|(~s&hi);
	return (o&t)|(~o&c);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x,int y,int z){
	int s=x+y,t=s+z;
	int o1=(~(x^y)&(x^s))>>31;
	int o2=(~(s^z)&(s^t))>>31;
	int d1=o1&((x>>31)|1),d2=o2&((s>>31)|1);
	return d1+d2;
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf){
	unsigned s=uf&0x80000000,e=(uf>>23)&255,m=uf&0x7fffff;
	unsigned r;
	if(e==255) return uf;
	if(e) m=m|0x800000;
	m=m*3;
	if(!e){
		r=m&1; m=m>>1;
		if(r&&(m&1)) m=m+1;
		return s|m;
	}
	if(m>=0x2000000){
		r=m&3; m=m>>2; e=e+1;
		if(r>2||(r==2&&(m&1))) m=m+1;
	}else{
		r=m&1; m=m>>1;
		if(r&&(m&1)) m=m+1;
	}
	if(e==255) return s|0x7f800000;
	return s|(e<<23)|(m&0x7fffff);
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf){
	unsigned s=uf&0x80000000,e=(uf>>23)&255,m=uf&0x7fffff;
	unsigned mask,r,h;
	int k;
	if(e>=150) return uf;
	if(e<126) return s;
	if(e==126){
		if(m) return s|0x3f800000;
		return s;
	}
	k=150-e;
	mask=(1u<<k)-1;
	r=m&mask; h=1u<<(k-1);
	m=(m|0x800000)&~mask;
	if(r>h||(r==h&&((m>>k)&1))) m=m+(1u<<k);
	if(m&0x1000000){
		m=m>>1; e=e+1;
	}
	return s|(e<<23)|(m&0x7fffff);
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x){
	unsigned s=x&0x80000000,u=x,m,r,h;
	int k=0,e;
	if(!x) return 0;
	if(x<0) u=~u+1;
	m=u;
	while(m>>1){
		m=m>>1; k=k+1;
	}
	e=k+127;
	if(k<=23) m=u<<(23-k);
	else{
		k=k-23;
		m=u>>k;
		r=u&((1u<<k)-1); h=1u<<(k-1);
		if(r>h||(r==h&&(m&1))) m=m+1;
		if(m&0x1000000){
			m=m>>1; e=e+1;
		}
	}
	return s|(e<<23)|(m&0x7fffff);
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x){
	int m=1|(1<<8),s;
	m=m|(m<<16);
	s=x&m;
	s=s+((x>>1)&m);
	s=s+((x>>2)&m);
	s=s+((x>>3)&m);
	s=s+((x>>4)&m);
	s=s+((x>>5)&m);
	s=s+((x>>6)&m);
	s=s+((x>>7)&m);
	return (s&255)+((s>>8)&255)+((s>>16)&255)+((s>>24)&255);
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x){
	int m=255|(255<<8);
	x=(x<<16)|((x>>16)&m);
	m=m^(m<<8);
	x=((x>>8)&m)|((x&m)<<8);
	m=m^(m<<4);
	x=((x>>4)&m)|((x&m)<<4);
	m=m^(m<<2);
	x=((x>>2)&m)|((x&m)<<2);
	m=m^(m<<1);
	return ((x>>1)&m)|((x&m)<<1);
}
