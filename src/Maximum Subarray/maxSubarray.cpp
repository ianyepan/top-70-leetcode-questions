#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
  int maxSubArray(std::vector<int> &nums)
  {
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;
    for (const auto &num : nums)
    {
      maxEndingHere = std::max(maxEndingHere + num, num);

      maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
  }
};
