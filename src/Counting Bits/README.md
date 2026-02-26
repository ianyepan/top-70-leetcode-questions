# Counting Bits

## Question:

Given an integer n, return an array ans of length n + 1 such that for
each i (0 <= i <= n), ans[i] is the number of 1's in the binary
representation of i.

## How to Solve:

Iteratively count set bits at each `i`.

TODO: Use DP approach with bit manipulation.


## My C++ Solution:

```log
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1);

        for (int i = 0; i < n + 1; ++i) {
            output[i] = __builtin_popcount(i);
        }

        return output;
    }
};
```
