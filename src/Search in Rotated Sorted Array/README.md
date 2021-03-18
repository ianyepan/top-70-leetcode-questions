# Search in Rotated Sorted Array

## Question:

There is an integer array `nums` sorted in ascending order (with
distinct values).

Prior to being passed to your function, `nums` is rotated at an
unknown pivot index `k` (`0 <= k < nums.length`) such that the
resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0],
nums[1], ..., nums[k-1]]` (0-indexed). For example, `[0,1,2,4,5,6,7]`
might be rotated at pivot index 3 and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the rotation and an integer `target`,
return the index of `target` if it is in `nums`, or -1 if it is not in
nums.

## How to Solve:

The solution consists of two phases. In phase one, we find the index
of the minimum element in the array (i.e. the breakpoint of the
rotated array), which is reusing the algorithm from the problem: "Find
Minimum in Rotated Sorted Array".

After we have located the minimum index (i.e. the number of rotates
this array has undergone), we compare and see if the `target` belongs to
the right half of the breakpoint or the left half. Afterwards, we may
perform a normal binary search for `target` in the correct half.
