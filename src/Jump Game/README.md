# Jump Game

## Question:

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

## How to Solve:

We iterate through the array, at each step updating the current
furthest reachable point. By the end of the loop, we check whether the
furthest reachable index is at or beyond the last position.

## My C++ Solution:

```cpp
class Solution {
 public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int reachable = 0;  // current furthest reachable index
    for (int i = 0; i < n; ++i) {
      if (i > reachable) {
        return false;
      }
      reachable = max(reachable, nums[i] + i);
    }
    return reachable >= n - 1;
  }
};
```