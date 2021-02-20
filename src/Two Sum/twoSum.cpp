#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<int> twoSum(std::vector<int> &nums, int t)
  {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); ++i)
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
