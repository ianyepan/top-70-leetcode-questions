# Palindromic Substrings

## Question:

Given a string `s`, return the number of palindromic substrings in
it. A string is a palindrome when it reads the same backward as
forward. A substring is a contiguous sequence of characters within the
string.

Example:

```text
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

## How to Solve:

The idea of this problem is to utilize the "expand" technique for
palindromes. We iterate through the given string and try an odd-expand
and even-expand using the current character as the middle point. With
`expand()` implemented as a helper function, we must pass in variable
`count` by reference, so that the increments persist throughout the
program.

## My C++ Solution:

```cpp
class Solution {
 public:
  int countSubstrings(string s) {
    int n = (int)s.length();
    if (n == 0) {
      return 0;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
      expand(s, n, i, i, count);      // odd expand
      expand(s, n, i, i + 1, count);  // even expand
    }
    return count;
  }

 private:
  void expand(const string &s, const int len, int start, int end, int &count) {
    while (start >= 0 && end < len && s[start] == s[end]) {
      ++count;
      --start;
      ++end;
    }
  }
};
```