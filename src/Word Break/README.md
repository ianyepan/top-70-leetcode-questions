# Word Break

## Question:

Given a string `s` and a dictionary of strings `wordDict`, return true
if `s` can be segmented into a space-separated sequence of one or more
dictionary words.

**Note** that the same word in the dictionary may be reused multiple
times in the segmentation.

Example 1:

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

Example 2:

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

Example 3:

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

## How to Solve:

This question can be seen as a recursive DP/memoization problem. We
create a `dp` hashmap, where `dp[word]` returns a boolean that says
`word` "can" be segmented into one or more dictionary words. As a
first step, we add all the words in `wordDict` into the `dp` hashmap
(obviously, they can be segmented into themselves, hence their value
should be true.)

We then define a recursive helper function that attempts to slice the
the target string into different left halves and right halves, and for
every left-half-right-half pair, determine if the left half is already
in the `dp` hashmap "and" its value is true, and then recursively call
the helper function on the right half to see whether its value is true
as well.
