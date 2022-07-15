# Longest Common Subsequence

## Question:

Given two strings `text1` and `text2`, return the length of their
longest common subsequence. If there is no common subsequence, return
0.

Example:

```text
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
```

## How to Solve:

This is a famous dynamic programming problem, part of the ["Edit
Distance"
family](https://en.wikipedia.org/wiki/Edit_distance#Types_of_edit_distance). We
maintain a DP matrix of dimensions `text1.length() + 1` by
`text2.length() + 1`. `dp[i][j]` means the longest common subsequence
between `text1[:i]` and `text2[:j]`, and we slowly build up the DP
table until we may return `dp[text1.length()][text2.length()]`.

For the idea of building the table, visit the visual examples in the
following links.

[Reference 1: LeetCode Discussion](https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm))

[Reference 2: Back To Back SWE](https://www.youtube.com/watch?v=ASoaQq66foQ) (DP table visual explanation starts at 13:16)

## My C++ Solution:

```cpp
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = (int)text1.length(), len2 = (int)text2.length();
    int dp[len1 + 1][len2 + 1];  // init size of 2D matrix
    memset(dp, 0, sizeof(dp));   // init values to 0
    for (int i = 1; i < len1 + 1; ++i) {
      for (int j = 1; j < len2 + 1; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[len1][len2];
  }
};
```