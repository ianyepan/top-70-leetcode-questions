#include <unordered_set>
#include <vector>

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_set<int> s(nums.begin(), nums.end());
    return nums.size() > s.size();
  }
};
