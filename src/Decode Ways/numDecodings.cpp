class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int oneDigit = s[i - 1] - '0';
      int twoDigits = s[i - 1] - '0' + (s[i - 2] - '0') * 10;
      if (oneDigit > 0) {
        dp[i] += dp[i - 1];
      }
      if (twoDigits >= 10 && twoDigits <= 26) {
        dp[i] += dp[i - 2];
      }
    }
    return dp[n];
  }
};
