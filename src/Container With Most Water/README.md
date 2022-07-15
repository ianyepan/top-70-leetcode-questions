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
min(heights[left], heights[right]) * (right - left);
```

We maintain a variable that keeps track of the max area seen so far --
which eventually will be our final answer by the end of the while
loop.

Before we move on to the next iteration, we update the position with
the shorter height, i.e. if `heights[left] < heights[right]`, then
`++left`, otherwise `--right`.

## My C++ Solution:

```cpp
class Solution {
 public:
  int maxArea(vector<int> &heights) {
    int left = 0, right = (int)heights.size() - 1, cur_max_area = 0;
    while (left < right) {
      cur_max_area = max(cur_max_area, min(heights[left], heights[right]) * (right - left));
      // Always keep the longer one and move the shorter.
      if (heights[left] < heights[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return cur_max_area;
  }
};
```