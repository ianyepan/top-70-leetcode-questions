class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int t) {
    unordered_map<int, int> seen;
    int n = (int)nums.size();
    for (int i = 0; i < n; ++i) {
      if (seen.find(nums[i]) != seen.end()) {
        return {seen[nums[i]], i};
      } else {
        seen.insert({t - nums[i], i});
      }
    }
    return {-1, -1};  // error, not found
  }
};
