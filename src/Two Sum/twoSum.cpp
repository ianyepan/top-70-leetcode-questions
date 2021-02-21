#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<int> twoSum(std::vector<int> &nums, int t)
  {
    std::unordered_map<int, int> seen;
    int n = (int)nums.size();
    for (int i = 0; i < n; ++i)
    {
      if (seen.find(nums[i]) != seen.end())
      {
        return {seen[nums[i]], i};
      }
      else
      {
        seen.insert({t - nums[i], i});
      }
    }
    return {-1, -1}; // error, not found
  }
};
