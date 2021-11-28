#include <algorithm>
#include <vector>

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    const int size = (int)nums.size();
    if (size < 3) {
      return ans;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; ++i) {
      // Skip duplicates
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      // Check conditions where nums[i] cannot possibly be part of an answer
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0 || nums[i] + nums[size - 1] + nums[size - 2] < 0) {
        continue;
      }

      const int target = 0 - nums[i];
      int low = i + 1, high = size - 1;
      while (low < high) {
        const int sum = nums[low] + nums[high];
        if (sum == target) {
          ans.push_back({nums[i], nums[low], nums[high]});
          ++low;
          --high;
          while (low < high && nums[low] == nums[low - 1]) {
            ++low;
          }
          while (low < high && nums[high] == nums[high + 1]) {
            --high;
          }
        } else if (sum > target) {
          --high;
        } else {
          ++low;
        }
      }
    }
    return ans;
  }
};
