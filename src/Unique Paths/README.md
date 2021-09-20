# Unique Paths

## Question:

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

## How to Solve:

This is a dynamic programming problem. We create a DP table, where each entry represents the number of ways to get to that grid position. The top row and leftmost column are all obviously "1". For any other entry, there are 2 possible ways of getting there, either right from its top, or right from its left.

Putting the idea together, we may calculate any entry dynamically as such:

```cpp
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```

Finally, we return `dp[m-1][n-1]`.

An alternative method is to use "combinations" (i.e. n-choose-k),
specifically, "(m-1 + n-1) choose min(m-1, n-1)".
