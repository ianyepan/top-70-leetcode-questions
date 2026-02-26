# Missing Number


## Question:

Reverse bits of a given 32 bits signed integer.


## How to Solve:

We may use a one-bit bitmask to iterate through every bit in the given
integer, and build our output in the opposite direction of the iteration.

It's important to note that we should always use unsigned integer for
our bitmasks (see comment in code).


## My C++ Solution:

```log
class Solution {
public:
    int reverseBits(int n) {
        int output = 0;

        // Important, must be unsigned otherwise when we later rightshift
        // we would pad left with 1s due to arithmetic rightshift.
        uint32_t mask = 1 << 31;

        for (int i = 0; i < 32; ++i) {
            auto bit = (n & mask) != 0 ? 1 : 0;
            output |= (bit << i);
            mask >>= 1;
        }

        return output;
    }
};

```
