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
