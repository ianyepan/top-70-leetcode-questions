# 3Sum

## Question:
Given an integer array nums, return all the triplets `[nums[i],
nums[j], nums[k]]` such that `i != j, i != k, and j != k`, and
`nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

## How to Solve:
Before we start looping the array, we sort it (ascending order) for
easier future processing.

We use a simple for-loop to iterate the array. At each position, we
see if the current element is a duplicate of the previous position --
if so, then we simply skip it. Then we check if the current element
could possibly be part of the answer. This is done by checking that
the following condition cannot be fulfilled:`nums[i] + nums[i + 1] +
nums[i + 2] > 0 || nums[i] + nums[size - 1] + nums[size - 2] < 0`.

If the current element passes both checks, we then search for the
right subarray for a pair `{nums[low], nums[high]}` that adds up to
`0 - nums[i]`, which then yields `{nums[i], nums[low], nums[high]}` as
an answer, to be appended to our final result. The technique to find
such a pair (or pairs) in the right subarray utilizes "two pointers":
a `low` and a `high`.

We initialize `low` to be the position `i+1`, and `high` to be
`size-1`, and iterate until `low` is no longer smaller than `high`. At
each iteration we check whether `nums[low]` and `nums[high]` can add
up to `0 - nums[i]`, then update `low` and `high` accordingly
(i.e. `++low` and `--high`). We also handle skipping duplicates when
possible.

## Reference:
For Chinese speakers, I recommend watching [this video](https://www.youtube.com/watch?v=zQDbMjNsuvY).

Specifically, the explanation of the method I'm using starts at around
11:48.
