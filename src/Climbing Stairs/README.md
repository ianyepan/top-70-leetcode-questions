# Climbing Stairs

## Question:

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways
can you climb to the top?

## How to Solve:

This problem is a classic one that can be solved either recursively
(with memoization) or through dynamic programming. The method is
identical to solving the Fibonacci sequence.

## My C++ Solution:

```cpp
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    } else if (seen.find(n) != seen.end()) {
      return seen[n];
    }
    seen[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return seen[n];
  }

 private:
  unordered_map<int, int> seen;
};
```