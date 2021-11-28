# Insert Interval

## Question:

You are given an array of non-overlapping intervals intervals where
intervals[i] = [starti, endi] represent the start and the end of the
ith interval and intervals is sorted in ascending order by starti. You
are also given an interval newInterval = [start, end] that represents
the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted
in ascending order by starti and intervals still does not have any
overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with
[3,5],[6,7],[8,10].
```

## How to Solve:

This problem can be solved by a greedy approach. Firstly, we add all
the intervals whose start time is less than or equal to our
newInterval's start time. Next, we push newInterval into our answer
vector and merge it with the last interval in `answer` if needed. For
the rest of the intervals, we do the same thing: we push it into our
`answer` vector, and merge it with the most recently pushed interval
if needed.

### Optimization:

We can use binary search (`upper_bound()` in C++) to determine
beforehand, the pivot at which the start times are no longer smaller
or equal to newInterval's start time. However, empirical testing shows
that a simple linear scan (worst case two-pass) is actually faster
than binary searching for the pivot. Nevertheless, in `insert.cpp` you
can find both solutions.
