# Combination Sum IV

## Question:
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

Example:

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

## How to Solve:

This can be solved with recursion and memoization. Here, we observe
that the number of combination sums for a given target, is simply the
"sum" of all possible of combination sums for that given target
subtracted by each number in the `nums` vector. Mathematically, we can
express it as such:

```
combs4(target) = combs4(target-nums[0]) + combs4(target-nums[1]) +
... + combs4(target-nums.back())
```

One detail to note is that `target-nums[i]` must be non-negative,
otherwise we won't call the recursive function.

Our base case would be `combs4(0)`, which is simply `1`.

As for the memoization, we can make use of a hashmap that records
pre-calculated `combs4(number)`.

## My C++ Solution:

```cpp
class Solution {
 public:
  int combinationSum4(vector<int> &nums, int target) {
    if (target == 0) {
      return 1;
    }
    if (combs4.find(target) != combs4.end()) {
      return combs4[target];
    }
    int result = 0;
    for (int num : nums) {
      if (target - num >= 0) {
        result += combinationSum4(nums, target - num);
      }
    }
    combs4[target] = result;
    return result;
  }

 private:
  unordered_map<int, int> combs4;
};
```