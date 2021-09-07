# Jump Game

## Question:

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

## How to Solve:

We iterate through the array, at each step updating the current
furthest reachable point. By the end of the loop, we check whether the
furthest reachable index is at or beyond the last position.
