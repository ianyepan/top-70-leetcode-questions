# Product of Array Except Self

## Question:

Given an array `nums` of n integers where n > 1, return an array
`output` such that `output[i]` is equal to the product of all the
elements of nums except nums[i].

Note: Solve without division.

Challenge: Can you do with O(1) space?

## How to Solve:

The bruteforce approach is obvious: we calculate the product of the
whole array, and then at each position divide this big product by that
position's number.

To solve this problem without using division we need multiple
loops. In the first loop, we construct an array `L` where `L[i]` is
the product of all elements left of position `i` in `nums`. (`L[0]` is
initialized as 1 as there are no numbers to the left of the first
element).

### If space is not a concern

If space is not a concern, we may construct a second array `R`, where
similarly, `R[i]` is the product of all elements right of position
`i`. After we obtained `L` and `R`, the answer is straightforward: we
create our final answer array where each element is simply `L[i] *
R[i]`.


### If O(1) space is required

If space is a concern, we can modify the approach above to be a bit
more space-efficient. The idea is to first create `L` as usual, then
overwriting `L` with a running `r` value (single integer, lowercased
to differentiate from `R`), eventually transforming `L` into our final
answer array.

Understandably, we must overwrite `L` from right to left, since the
running `r` value increases by multiplication of `nums[i]` from right
to left as well.

The rest is implementation details: for example, `r` (type int) should
be initialized to 1.

## My C++ Solution:

```cpp
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> L(n);
    L[0] = 1;
    for (int i = 1; i < n; ++i) {
      L[i] = L[i - 1] * nums[i - 1];
    }
    int r = 1;
    for (int i = n - 1; i >= 0; --i) {
      L[i] *= r;
      r *= nums[i];
    }
    return L;
  }
};
```