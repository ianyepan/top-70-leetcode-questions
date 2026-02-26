# Sum of Two Integers (without using `+`)

## Question:

Given two integers a and b, return the sum of the two integers without using the operators `+` and `-`.

## How to Solve:

This problem tests "bit shifting" and the "half adder" logic. Simply
put, the sum of two bits can be obtained by performing XOR (`^`) of
the two bits. Carry bit can be obtained by performing AND (`&`) of two
bits, leftshift by one.

Adding `x` and `y` is equal to adding `(x + y without carry)` and
`carry`. The former is obtained from `x ^ y` and the latter is the
result of `(x & y) << 1`. These two numbers serve as the new `x` and
`y` in our next iteration, and we iterate until the carry becomes
zero.

At each iteration, `x` holds the running answer, and `y` holds the
leftshifted carry.

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
      y = carry << 1;              // leftshift carry
    }

    return x;
  }
};
```
