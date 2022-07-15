# Merge Intervals

## Question:

Given an array of intervals where intervals[i] = [`start_i`, `end_i`],
merge all overlapping intervals, and return an array of the
non-overlapping intervals that cover all the intervals in the input.

Example:

```text
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

## How to Solve:

We maintain a new vector `merged` (initially empty), which will be our
eventual answer. The trick is to leave the most recent addition (last
position) of `merged`, aka `merged.back()`, modifiable. We'll only
push a new pair if `merged` is empty, or if the current candidate
pair's start value is greater than `merged.back()`'s end
value. Otherwise, we modify `merged.back()`'s end value to be the
current candidate pair's end value (essentially merging the two), and
move on to the next iteration (and next candidate in the input
vector).

## My C++ Solution:

```cpp
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &v) {
    sort(v.begin(), v.end());  // sort by start-time (default)
    vector<vector<int>> merged;
    for (const auto &pair : v) {
      if (!merged.empty() && merged.back()[1] >= pair[0]) {
        merged.back()[1] = max(merged.back()[1], pair[1]);
      } else {
        merged.push_back(pair);
      }
    }
    return merged;
  }
};
```