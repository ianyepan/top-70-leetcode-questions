

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = (int)s.length();
    int start = 0;    // starting index of current max palindrom
    int max_len = 0;  // max palindrome length seen so far

    for (int i = 0; i < n; ++i) {
      int cur = max(expandPalindromeLength(s, n, i, i),       // case odd
                    expandPalindromeLength(s, n, i, i + 1));  // case even

      if (cur > max_len)  // update both 'starting index' and 'max_len'
      {
        start = i - ((cur - 1) / 2);  // works for both odd and even len
        max_len = cur;
      }
    }

    return s.substr(start, max_len);
  }

 private:
  int expandPalindromeLength(string &s, int n, int l, int r) {
    while (l >= 0 && r <= n && s[l] == s[r]) {
      --l;
      ++r;
    }
    return (--r) - (++l) + 1;  // r - l - 1
  }
};
