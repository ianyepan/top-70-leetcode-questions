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
