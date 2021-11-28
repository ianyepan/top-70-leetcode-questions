#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int reachable = 0; // current furthest reachable index
    for (int i = 0; i < n; ++i)
    {
      if (i > reachable)
      {
        return false;
      }
      reachable = max(reachable, nums[i] + i);
    }
    return reachable >= n - 1;
  }
};
