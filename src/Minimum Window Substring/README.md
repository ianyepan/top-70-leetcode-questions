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
unordered_maps to speed up the performance. Below, I
implement both solutions.

## My C++ Solution:

```cpp
// Hash map solution
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> tMap;
    for (auto ch : t) {
      ++tMap[ch];
    }
    int l = 0, r = 0;
    int required = tMap.size(), satisfied = 0;
    unordered_map<char, int> windowMap;
    vector<int> ans{INT_MAX, l};
    const int n = s.length();
    for (r = 0; r < n; ++r) {
      ++windowMap[s[r]];
      if (tMap.find(s[r]) != tMap.end() && windowMap[s[r]] == tMap[s[r]]) {
        ++satisfied;
      }
      // Try to shrink on the left side, see if we can get a smaller
      // satisfying substring.
      while (l <= r && satisfied == required) {
        if (ans[0] == -1 || r - l + 1 < ans[0]) {
          ans[0] = r - l + 1;
          ans[1] = l;
        }
        cout << s[l] << " " << windowMap[s[l]] << "\n";
        --windowMap[s[l]];
        if (tMap.find(s[l]) != tMap.end() && windowMap[s[l]] < tMap[s[l]]) {
          --satisfied;
          ++l;
          break;
        } else {
          ++l;
        }
      }
    }
    return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
  }
};

// Same solution, except using vectors
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> tMap(128, 0);
    for (auto ch : t) {
      ++tMap[ch];
    }
    int l = 0, r = 0;
    int required = unordered_set<char>(begin(t), end(t)).size(), satisfied = 0;
    vector<int> windowMap(128, 0);
    vector<int> ans{INT_MAX, l};
    const int n = s.length();
    for (r = 0; r < n; ++r) {
      ++windowMap[s[r]];
      if (tMap[s[r]] != 0 && windowMap[s[r]] == tMap[s[r]]) {
        ++satisfied;
      }
      // Try to shrink on the left side, see if we can get a smaller
      // satisfying substring.
      while (l <= r && satisfied == required) {
        if (ans[0] == -1 || r - l + 1 < ans[0]) {
          ans[0] = r - l + 1;
          ans[1] = l;
        }
        --windowMap[s[l]];
        if (tMap[s[l]] != 0 && windowMap[s[l]] < tMap[s[l]]) {
          --satisfied;
          ++l;
          break;
        } else {
          ++l;
        }
      }
    }
    return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
  }
};
```
