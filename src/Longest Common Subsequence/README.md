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
