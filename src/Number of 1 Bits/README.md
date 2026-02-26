# Number of 1 Bits

## Question:

Given a positive integer `n`, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

## How to Solve:

Given an integer `n`, performing `n & (n - 1)` flips the least
significant 1-bit to zero. Example:


```log
n         = 1010011000
n-1       = 1010010111
----------------------
n & (n-1) = 1010010000
```

Using this property, we may iteratively remove set bits until `n`
becomes zero. The number of times we iterate is the number of set bits
in the original `n`.

Alternatively, use C++'s `__builtin_popcount()` for a one-liner.

## My C++ Solution:

```cpp
class Solution {
public:
  int hammingWeight(int n) {
    int count = 0;

    while (n) {
      n &= (n - 1); // remove rightmost 1
      ++count;
    }

    return count;
  }
};

```
