# House Robber

## Question:

You are a professional robber planning to rob houses along a
street. Each house has a certain amount of money stashed, the only
constraint stopping you from robbing each of them is that adjacent
houses have security systems connected and it will automatically
contact the police if two adjacent houses were broken into on the same
night.

Given an integer array nums representing the amount of money of each
house, return the maximum amount of money you can rob tonight without
alerting the police.

## How to Solve:

Figure out recursive relation.

A robber has 2 options:
- Rob current house i
- Don't rob current house.

If an option 1 is selected it means she can't rob previous i-1 house
but can safely proceed to the one before previous i-2 and gets all
cumulative loot that follows.

If an option 2 is selected the robber gets all the possible loot
from robbery of i-1 and all the following buildings.  So it boils down
to calculating which of two following cases is more profitable:

- Robbery of current house + loot from houses before the previous
- Loot from the previous house robbery and any loot captured before
  that.

If we let `rob(i)` be the max loot that we get from a cumulation up to
house i. We have the following relation:

`rob(i) = max(rob(i - 2) + currentHouseValue, rob(i - 1))`

## My C++ Solution:

```cpp
class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    vector<int> rob(n + 1);
    rob[0] = 0;  // important initialization
    rob[1] = nums[0];
    for (int i = 2; i < n + 1; ++i) {
      int currentHouseValue = nums[i - 1];
      rob[i] = max(rob[i - 2] + currentHouseValue, rob[i - 1]);
    }
    return rob[n];
  }
};
```
