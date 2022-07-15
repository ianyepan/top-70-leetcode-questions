# Maximum Subarray

## Question:

Given an integer array `nums`, find the contiguous subarray (containing
at least one number) which has the largest sum and return its sum.


## How to Solve:

This classic problem is solved by the Kadane's Algorithm.

We loop through the array once (O(n)), and we maintain two variables
at each step, namely `maxEndingHere` and `maxSoFar`.

The former variable, as the name suggests computes the subarray with
the largest sum ending at the current position, while the latter
computes the subarray with the largest sum anywhere between the start
and the current position. Normally, `maxEndingHere` would just keep
accumulating numbers. However, there is a special case: when
`maxEndingHere`'s current value is negative and we just encountered a
positive number. Intuitively, it would be best if we just discard the
previous subarray and start a new subarray from scratch at the current
position, which would result in a subarray (of one element) with the
largest sum ending at the current position.

Maintaining the variable `maxSoFar` is easy, at each iteration we just
check if `maxEndingHere` ever exceeds `maxSoFar`: if so, we update the
latter to be the former.

## My C++ Solution:

```cpp
class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;
    for (const auto &num : nums) {
      maxEndingHere = max(maxEndingHere + num, num);
      maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
  }
};
```