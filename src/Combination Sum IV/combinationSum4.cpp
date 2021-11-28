class Solution {
 public:
  int combinationSum4(vector<int> &nums, int target) {
    if (target == 0) {
      return 1;
    }
    if (combs4.find(target) != combs4.end()) {
      return combs4[target];
    }
    int result = 0;
    for (int num : nums) {
      if (target - num >= 0) {
        result += combinationSum4(nums, target - num);
      }
    }
    combs4[target] = result;
    return result;
  }

 private:
  unordered_map<int, int> combs4;
};
