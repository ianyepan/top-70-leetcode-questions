# Minimum Window Substring

## Question:

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example:

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B',
and 'C' from string t.
```

## How to Solve:

The solution is fairly straightforward for a "LeetCode Hard"
problem. We maintain two hash maps, one that records the frequency of
characters in string `t` (which we will not modify throughout the
program), and another hash map recording the frequency of characters
in the "current sliding window".

We also make use of two pointers, left and right, to slide the
window.

The next two variables are a bit tricky: we need 2 counts, `required`
and `satisfied`. `required` is simply the number of unique characters
in `t` (i.e. the size of `t`'s hash map). On the other hand,
`satisfied` is the "number of characters in the window that is also in
`t` which is also satisfying the correct frequency". This is arguably
the hardest part of the problem.

At each iteration, we expand on the right, and if this new character
has allowed for a character `t` to be satisfied with its correct
frequency (in the window), we increment `satisfied`. Whenever
`satisfied` is equal to `required`, we want to shrink the window from
the left side to see if we can get a satisfying window with a shorter
length. We do so with a normal while-loop.

Finally, we realize that we can actually use vectors of size 128
(which will definitely include `a..z` and `A..Z`) instead of
unordered_maps to speed up the performance. In `minWindow.cpp`, I
implement both solutions.
