

class Solution {
 public:
  bool isPalindrome(string s) {
    string new_str;
    for (const auto &ch : s) {
      if (isalnum(ch)) {
        new_str.push_back(tolower(ch));
      }
    }

    int n = (int)new_str.length();
    for (int i = 0; i < n / 2; ++i) {
      if (new_str[i] != new_str[n - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};
