# Valid Palindrome

## Question:

Given a string `s`, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

## How to Solve:

The first step is to trim all the non-alphanumeric characters and make
everything lowercase (or uppercase, as long as it's the same case).

Let the resulting string length be "n". We loop index `i` from 0 to
`n/2`, each time comparing positions `s[i]` and `s[n-1-i]`.
