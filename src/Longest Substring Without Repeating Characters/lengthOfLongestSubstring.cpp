

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = (int)s.length();
    if (n == 0) {
      return 0;
    }

    unordered_map<char, int> mm;
    int left_ptr = 0, curr_max = 1;

    for (int right_ptr = 0; right_ptr < n; ++right_ptr) {
      char ch = s[right_ptr];
      if (mm.find(ch) != mm.end()) {
        left_ptr = max(left_ptr, mm[ch] + 1);
      }
      mm[ch] = right_ptr;
      curr_max = max(curr_max, right_ptr - left_ptr + 1);
    }
    return curr_max;
  }
};
