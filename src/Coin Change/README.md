# Coin Change

## Question:
You are given an integer array `coins` representing coins of different
denominations and an integer `amount` representing a total amount of
money.

Return the fewest number of coins that you need to make up that
amount. If that amount of money cannot be made up by any combination
of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

## How to Solve:

This is a dynamic programming problem. We maintain an array `dp` of
size "`amount` + 1", where each element corresponds to the fewest
number of coins needed to make up the amount `index`. Therefore,
`dp[amount]` will be our eventual answer.

We iterate from 1 to `amount`, gradually filling up the DP
array. Within each iteration, we iterate through the variety of coins,
and if the coin value is smaller than or equal to the amount
(somewhere between 1 and `amount`) at hand, we perform the following
update:

```cpp
dp[i] = std::min(dp[i], 1 + dp[i - val]);
```
That is, we either keep the current value of `dp[i]`, or update it
with one plus the number of coins needed to make up the amount `i -
val`, whichever is smaller. The "one plus" comes from the fact that we will be using the current coin value once, totaling the amount `i`.
