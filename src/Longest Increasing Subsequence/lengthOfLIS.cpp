#include <algorithm>
#include <vector>

class Solution
{
public:
  int lengthOfLIS(std::vector<int> &nums)
  {
    if (nums.empty())
    {
      return 0;
    }

    int n = (int)nums.size();
    std::vector<int> dp(n, 1); // LIS with dp[i] as ending

    for (int r = 0; r < n; ++r)
    {
      for (int l = 0; l < r; ++l)
      {
        if (nums[r] > nums[l])
        {
          dp[r] = std::max(dp[r], dp[l] + 1);
        }
      }
    }

    return *std::max_element(dp.begin(), dp.end());
  }
};
