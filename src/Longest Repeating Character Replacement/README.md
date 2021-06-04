# Longest Repeating Character Replacement

## Question:
You are given a string `s` and an integer `k`. You can choose any
character of the string and change it to any other uppercase English
character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter
you can get after performing the above operations.

## How to Solve:

The solution uses the sliding window technique. The right bound
increases with each iteration. But the left bound only increases (and
decreases the size of the sliding window) if the current window needs
more than 'k' steps to become a substring of uniform characters. How
do we calculate the steps that the current window needs? We take the
length of the window (end - start + 1) and subtract that with the
occurrence of the most frequent letter in the window. This means that
we must also keep track of each letter's frequency in an unordered
map.
