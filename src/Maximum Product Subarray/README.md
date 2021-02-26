# Maximum Product Subarray

## Question:

Given an integer array `nums`, find the contiguous subarray within an
array (containing at least one number) which has the largest product.

## How to Solve:

At each iteration, there are 3 variables we need to keep track of: the
maximum product that ends at the current index (`cur_max`), the
minimum product that ends at the current index (`cur_min`), and the
maximum product that we have seen so far (`max_prod`), which would
eventually be our answer.

At each timestep, `cur_max` and `cur_min` can be updated as one of the
following values:
1. The current `cur_max` multiplied by `nums[i]`
2. The current `cur_min` multiplied by `nums[i]`
3. Simply `nums[i]`

Note that `cur_min` and `nums[i]` could be both very small negative
numbers with a large absolute value, which when multiplied together
can result in a large positive number. This is why we must consider
all three candidates.

After we updated `cur_max` and `cur_min`, we check whether `cur_max`
has exceeded the current `max_prod` and update the latter
accordingly. By the end of the loop, `max_prod` will be our answer.
