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

## My C++ Solution:

```cpp
class Solution {
 public:
  int characterReplacement(string s, int k) {
    int n = (int)s.length();
    unordered_map<char, int> count;  // character frequencies in the sliding window
    int max_length = 0;              // longest consecutive substring so far (after operations). Eventually our answer.
    int most_freq_letter = 0;        // most frequent char in the sliding window
    int start = 0;
    for (int end = 0; end < n; ++end)  // 'end' loops through the string normally
    {
      ++count[s[end]];                                          // update current char count
      most_freq_letter = max(most_freq_letter, count[s[end]]);  // whether current char has higher freq
      if ((end - start + 1) - most_freq_letter > k)             // compare "no. of operations we must do", with k
      {
        --count[s[start]];  // decrease s[start]'s freq because we're about to shrink
        ++start;            // shrink window on the left
      }
      max_length = max(max_length, end - start + 1);
    }
    return max_length;
  }
};
```