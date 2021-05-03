# Container With Most Water

## Question:
Given array `heights` of `n` non-negative integers `a_1, a_2, ..., a_n` , where each
represents a point at coordinate `(i, a_i)`. `n` vertical lines are
drawn such that the two endpoints of the line i is at (i, ai) and (i,
0). Find two lines, which, together with the x-axis forms a container,
such that the container contains the most water.

## How to Solve:
We maintain two pointers, `left` and `right`, starting respectively
from 0, and size-1.

We iterate until `left` is no longer smaller than `right`. At each
iteration, we calculate the max possible area bounded by the heights
at `left` and `right`, which can be calculated as follows:

```cpp
cur_area = std::min(heights[left], heights[right]) * (right - left);
```

We also maintain a variable that keeps track of the max area seen so
far -- which eventually will be our final answer by the end of the
while loop.

Before we move on to the next iteration, we update the position with
the shorter height, i.e. if `heights[left] < heights[right]`, then
`++left`, otherwise `--right`.
