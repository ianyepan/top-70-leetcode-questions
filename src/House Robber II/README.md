# House Robber II

## Question:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3
(money = 2), because they are adjacent houses.
```

## How to Solve:

The answer is either the DP from first house till second-to-last
house, or the second house till last house. Because we cannot have the
first house "and" the last house in the same solution. With this in
mind, this problem is essentially doing "House Robber I" twice.

## My C++ Solution:

```cpp
class Solution {
 public:
  // Two paths: first house till second-to-last house,
  // or second house till last house
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return nums[0];
    }
    int ans1 = helper(nums, 0, n - 2);
    int ans2 = helper(nums, 1, n - 1);
    return max(ans1, ans2);
  }

 private:
  int helper(vector<int> &nums, int start, int end) {
    int m = end - start + 2;
    vector<int> dp(m);
    dp[0] = 0;
    dp[1] = nums[start];
    for (int i = 2; i < m; ++i) {
      auto currentHouseValue = nums[start + i - 1];
      dp[i] = max(dp[i - 2] + currentHouseValue, dp[i - 1]);
    }
    return dp.back();
  }
};
```