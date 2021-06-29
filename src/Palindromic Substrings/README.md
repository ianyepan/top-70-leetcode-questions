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
