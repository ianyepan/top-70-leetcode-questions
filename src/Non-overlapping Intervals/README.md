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
