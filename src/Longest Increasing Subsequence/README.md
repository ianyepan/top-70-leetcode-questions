# Longest Increasing Subsequence

## Question:

Given an integer array `nums`, return the length of the longest
strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by
deleting some or no elements without changing the order of the
remaining elements. For example, `[3,6,2,7]` is a subsequence of the
array `[0,3,1,6,2,2,7]`.

Note: a subsequence doesn't have to be contiguous.

## How to Solve:

This is a dynamic programming problem. If `nums` is empty, we just
return `0`. Otherwise, we maintain a DP array of size `nums.length()`,
initialized all to `1`'s. Each entry in the DP array represents the
Longest Increasing Subsequence's length using `dp[i]` as the ending.

The main body consists of a double for-loop. We loop through the input
array `nums`, at each iteration using the current number as the
subsequence end. And we compare each number (index denoted by `l`)
before the current number (index denoted by `r`), and see if they are
strictly increasing (i.e. `nums[l] < nums[r]`). If this is the case,
we update `dp[r]` to `std::max(dp[r], dp[l]+1)`. That is, either we
use the current value, or we use the length of `dp[l]` plus 1 because
we're taking into account the current number.

In the end we simply return the maximum element in vector `dp`.
