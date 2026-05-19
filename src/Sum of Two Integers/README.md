# Sum of Two Integers (without using `+`)

## Question:

Given two integers a and b, return the sum of the two integers without using the operators `+` and `-`.

## How to Solve:

This problem tests "bit shifting" and the "half adder" logic. Simply
put, the sum of two bits can be obtained by performing XOR (`^`) of
the two bits. Carry bit can be obtained by performing AND (`&`) of two
bits and left-shift by one.

Adding `a` and `b` is equal to adding `(a + b without carry)` and
`carry`. The former is obtained from `a ^ b` and the latter is the
result of `(a & b) << 1`. These two numbers serve as the new `a` and
`b` in our next iteration, and we iterate until the carry (`b`) becomes
zero.

At each iteration, `a` holds the running answer, and `b` holds the
left-shifted carry.

The following answer uses additional variables `res` and `carry` for
better readability. Space complexity remains O(1).

[Reference 1:
GeeksForGeeks](https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/)

[Reference 2: Back to Back SWE](https://www.youtube.com/watch?v=qq64FrA2UXQ)

## My C++ Solution:

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        unsigned int res = a ^ b;
        unsigned int carry = (a & b) << 1;

        while (carry) {
            unsigned int tmp_carry = (res & carry) << 1;
            res ^= carry;
            carry = tmp_carry;
        }

        return (int)res;
    }
};
```
