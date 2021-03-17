# Find Minimum In Rotated Sorted Array

## Question:

Suppose an array of length n sorted in ascending order is rotated
between 1 and n times. Given the sorted rotated array nums of unique
elements, return the minimum element of this array.

## How to Solve:

At first glance, this problem seems to be asking for a simple O(n)
scan for the minimum -- but can we do better than O(n)? It turns out
we can.

We can use binary search to search for the "breakpoint" between the
largest number and the smallest number. For instance, if the original
array was [1,2,3,4,5] and is rotated to [4,5,1,2,3], then there's a
"breakpoint" between 5 and 1 (index 1 and 2 respectively). Before we
start, we must check whether the array is rotated at all (by comparing
the last element and the first element) -- if the array wasn't
rotated, then we return the first number and call it a day.

As in binary search, we maintain two indices -- a `low` and a `high` ,
which are prone to updates after every iteration -- and we also
calculate `mid` for every loop. Within every iteration, we check both
sides of `mid` and see whether we have found the breakpoint (by
comparing the numbers). If not, then we proceed to either update `low`
or `high`. We update index `low` to be `mid + 1` if the current
`mid`'s number is greater than `low`'s (because the breakpoint must be
on the right of `mid`. Note that this is only true if we are sure the
array is rotated and different to the original), and we update `high`
to be `mid` if the current `mid`'s number is smaller than `low`,
meaning that the breakpoint must be on the left of `mid`.
