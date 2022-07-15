# Group Anagrams

## Question:

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example:**

```text
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

## How to Solve:

Maintain a map that has a string as the key and a vector of strings as
the value. For every string in the input array, sort it alphabetically
to determine which key it should belong, then append the unsorted
version of the string after the key's value.

After iterating every string in the input array, collect all the
values as a vector of vector of strings, which is our final answer.

## My C++ Solution:

```cpp
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> ans;
    for (const auto &s : strs) {
      auto s_sorted = s;
      sort(s_sorted.begin(), s_sorted.end());
      m[s_sorted].push_back(s);
    }
    for (const auto &elem : m) {
      ans.push_back(elem.second);
    }
    return ans;
  }
};
```