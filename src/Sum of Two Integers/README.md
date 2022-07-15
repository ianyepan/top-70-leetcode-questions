# Sum of Two Integers (without using `+`)

## Question:

Given two integers a and b, return the sum of the two integers without using the operators `+` and `-`.

## How to Solve:

This problem tests "bit shifting" and the "half adder" logic. Simply
put, the sum of two bits can be obtained by performing XOR (`^`) of
the two bits. Carry bit can be obtained by performing AND (`&`) of two
bits.

We can extend this logic for integers. If x and y don’t have set bits
at same position(s), then bitwise XOR (`^`) of x and y gives the sum
of x and y. To incorporate common set bits also, bitwise AND (`&`) is
used. Bitwise AND of x and y gives all carry bits. We calculate (`x &
y) << 1` and add it to `x ^ y` to get the required result. We stop
when the carry equals 0.

`x` holds the running answer, and `y` holds the carry at each
iteration, after it's been left-shifted.

[Reference 1:
GeeksForGeeks](https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/)

[Reference 2: Back to Back SWE](https://www.youtube.com/watch?v=qq64FrA2UXQ)

## My C++ Solution:

```cpp
class Solution {
 public:
  int getSum(int x, int y) {
    while (y != 0) {
      unsigned int carry = x & y;  // AND: calculate carry
      x = x ^ y;                   // XOR: actual addition for each current position
      y = carry << 1;              // left shift carry
    }
    return x;
  }
};
```