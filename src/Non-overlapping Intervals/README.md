# Non-overlapping Intervals

## Question:

Given an array of intervals intervals where intervals[i] = [`start_i`,
`end_i`], return the minimum number of intervals you need to remove to
make the rest of the intervals non-overlapping.

## How to Solve:

Firstly, we sort the intervals by their end time. Then, We let the
variable `prev` hold the first interval. We iterate from the second
interval till the last one, each time checking whether we should
update `prev` to the current interval or increase the `remove_count`
(i.e. our final answer to return):

If the current interval's start time is greater or equal to `prev`'s
end time, no overlapping has occurred, and we simply move on to the
next iteration.

Otherwise, we increment `remove_count` and move on. Without updating
`prev`, we have essentially dropped the current interval. Note: if an
overlapping, we always drop the current interval, and never `prev`.

Finally, we return `remove_count`.

## My C++ Solution:

```cpp
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = (int)intervals.size();
    if (n == 0) {
      return 0;
    }
    // Ascending sort by end-time
    sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) { return v1[1] < v2[1]; });
    vector<int> prev = intervals[0];
    int remove_count = 0;
    for (int i = 1; i < n; ++i) {
      vector<int> cur = intervals[i];
      if (prev[1] <= cur[0]) {
        prev = cur;
      } else {
        ++remove_count;
      }
    }
    return remove_count;
  }
};
```