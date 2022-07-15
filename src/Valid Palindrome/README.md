# Valid Palindrome

## Question:

Given a string `s`, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

## How to Solve:

The first step is to trim all the non-alphanumeric characters and make
everything lowercase (or uppercase, as long as it's the same case).

Let the resulting string length be "n". We loop index `i` from 0 to
`n/2`, each time comparing positions `s[i]` and `s[n-1-i]`.

## My C++ Solution:

```cpp
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
```