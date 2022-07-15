# Decode Ways

## Question:

A message containing letters from A-Z can be encoded into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

```
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
```

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

## How to Solve:

This problem can be solved by bottom-up dynamic programming. We create
a `dp` array, where `dp[i]` = Number of ways to decode the substring
`s[:i]` (note how `s[i]` is not included!). In the end, we return
`dp[s.length()]`.

We iterate through the string, at each point looking back one
character to obtain the value of "one digit", or looking back two
characters to obtain the value of "two digits". We then add the values
(if valid) to the `dp` array at the current index.

The rest is to handle edge cases. Obviously, if we have a leading zero
in the string, we can simply return 0. The next part is a bit tricky,
that is, to set both `dp[0]` and `dp[1]` to 1.

Why?

Well, that simply because we don't want the calculation of `dp[2]` to crash!

## My C++ Solution:

```cpp
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
```