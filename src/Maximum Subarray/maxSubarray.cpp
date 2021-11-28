#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;
    for (const auto &num : nums)
    {
      maxEndingHere = max(maxEndingHere + num, num);

      maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
  }
};
