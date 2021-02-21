# Best Time to Buy and Sell Stock

## Question:
You are given an array `prices` where `prices[i]` is the price of a
given stock on the i-th day.

You want to maximize your profit by choosing a single day to buy one
stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If
you cannot achieve any profit, return 0.

## How to Solve:

Keep track of two variables, `curr_min` and `curr_max_profit`, where
the former is simply the smallest `prices[i]` seen thus far.

The latter variable is the key to solving this problem. It maintains
the current maximum possible profit. In other words, at every
iteration we check the optimal profit that the current price can
achieve, which is simply the difference between the current price and
the current minimum price (before it). Then we check if the maximum
possible profit is exceeded and thus needs to be updated. Hence, the
way to calculate `curr_max_profit` at every iteration is:

```cpp
curr_max_profit = std::max(curr_max_profit, prices[i] - curr_min);
```

Without loss of generality, we may initialize `curr_min` to be
`prices[0]` and `curr_max_profit` to be zero.
