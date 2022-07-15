# Longest Substring Without Repeating Characters

## Question:

Given a string `s`, find the length of the longest substring without
repeating characters.

##### Example 1:

```text
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

##### Example 2:

```text
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

##### Example 3:

```text
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
```

## How to Solve:

Maintain two pointers and a hash map which stores string characters as
keys and their positions as values. Move the right pointer to scan
through the string: if the current character is already in the hashmap
AND the position of the same character last found is greater than the
left pointer's position, we move the left pointer to the right of the
same character last found (trim the substring to avoid having same
characters in the substring). In every iteration we update the hashmap
with the current character and position, as well as the max substring
length we've seen so far, which eventually will be our answer after
the whole string is traversed.

## My C++ Solution:

```cpp
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = (int)s.length();
    if (n == 0) {
      return 0;
    }
    unordered_map<char, int> mm;
    int left_ptr = 0, curr_max = 1;
    for (int right_ptr = 0; right_ptr < n; ++right_ptr) {
      char ch = s[right_ptr];
      if (mm.find(ch) != mm.end()) {
        left_ptr = max(left_ptr, mm[ch] + 1);
      }
      mm[ch] = right_ptr;
      curr_max = max(curr_max, right_ptr - left_ptr + 1);
    }
    return curr_max;
  }
};
```