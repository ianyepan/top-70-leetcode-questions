#include <algorithm>
#include <cstring>
#include <string>

class Solution
{
public:
  int longestCommonSubsequence(std::string text1, std::string text2)
  {
    int len1 = (int)text1.length(), len2 = (int)text2.length();
    int dp[len1 + 1][len2 + 1]; // init size of 2D matrix
    memset(dp, 0, sizeof(dp));  // init values to 0

    for (int i = 1; i < len1 + 1; ++i)
    {
      for (int j = 1; j < len2 + 1; ++j)
      {
        if (text1[i - 1] == text2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[len1][len2];
  }
};
