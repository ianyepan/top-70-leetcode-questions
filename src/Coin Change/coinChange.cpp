#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
  int coinChange(std::vector<int> &coins, int amount)
  {
    std::vector<long> dp(amount + 1, INT_MAX);
    dp[0] = 0; // 0 coins required to achieve 0 sum

    for (int i = 1; i <= amount; ++i)
    {
      for (const auto &val : coins)
      {
        if (i >= val)
        {
          dp[i] = std::min(dp[i], 1 + dp[i - val]);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
