class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    vector<int> rob(n + 1);
    rob[0] = 0;  // important initialization
    rob[1] = nums[0];
    for (int i = 2; i < n + 1; ++i) {
      int currentHouseValue = nums[i - 1];
      rob[i] = max(rob[i - 2] + currentHouseValue, rob[i - 1]);
    }
    return rob[n];
  }
};
