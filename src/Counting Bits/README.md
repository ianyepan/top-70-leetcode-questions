# Counting Bits

## Question:

We may solve this problem using a combination of bit manipulation and
DP. Intuition: for any number x, its number of bits would the number
of bits of x right-shifted by one, i.e. (x >> 1), **plus** whether x's
LSB is 1 or not. If we build the DP array from the bottom up starting
with small numbers, we can deduce the number of bits of larger numbers
iteratively.

In other words, if we already have the answer for `1101000`, then we
can easily arrive at the answer of both `11010000` and `11010001` in
constant time.

We initialize our DP array to all zeros, since the number of bits of
`0` is zero. We begin the actual iteration from 1 until n. Each element
of the DP array represents the number of bits of the array index. The
DP array happens to also be our final output.

## My C++ Solution:

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);

        for (int i = 1; i < n + 1; ++i) {
            output[i] = output[i >> 1] + (i & 1);
        }

        return output;
    }
};
```
