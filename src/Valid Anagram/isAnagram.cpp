class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    unordered_map<char, int> m;
    for (const auto &ch : s) {
      m[ch] += 1;
    }
    for (const auto &ch : t) {
      m[ch] -= 1;
    }
    for (const auto &pp : m) {
      if (pp.second != 0) {
        return false;
      }
    }
    return true;
  }
};
