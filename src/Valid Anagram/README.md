# Valid Anagram

## Question:
Given two strings `s` and `t`, return true if `t` is an anagram of
`s`, and false otherwise.

P.s. An anagram is a word or phrase formed by rearranging the letters
of a different word or phrase, typically using all the original
letters exactly once.

## How to Solve:

First of all, we check whether `s` and `t` are even the same
length. Then we maintain a hash table (`unordered_map` in C++) that
uses the letters as keys and the frequency of each letter as the
corresponding value. We traverse each character of `s` and increase
the corresponding frequencies, then later traverse each character of
`t` and **decrease** the corresponding frequencies. In the end, we
check whether all frequencies are back at zero.

## My C++ Solution:

```cpp
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    unordered_map<char, int> m;
    for (const auto &ch : s) {
      m[ch] += 1;
    }
    for (const auto &ch : t) {
      m[ch] -= 1;
    }
    for (const auto &pp : m) {
      if (pp.second != 0) {
        return false;
      }
    }
    return true;
  }
};
```