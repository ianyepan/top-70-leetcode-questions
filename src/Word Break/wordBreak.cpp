class Solution {
 public:
  bool wordBreak(const string &s, const vector<string> &wordDict) {
    for (auto &word : wordDict) {
      dp[word] = true;
    }
    return helper(s);
  }

 private:
  unordered_map<string, bool> dp;
  bool helper(const string &s) {
    if (dp.find(s) != dp.end()) {
      return dp[s];
    }
    int n = s.length();
    for (int i = 1; i < n; ++i) {
      auto leftHalf = s.substr(0, i);
      auto rightHalf = s.substr(i);
      auto it = dp.find(leftHalf);
      if (it != dp.end() && dp[leftHalf] && helper(rightHalf)) {
        dp[s] = true;
        return true;
      }
    }
    dp[s] = false;
    return false;
  }
};
