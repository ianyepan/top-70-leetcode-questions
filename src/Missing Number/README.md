# Missing Number


## Question:

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

## How to Solve:

We can take advantage of the property that `x & x` becomes `0` for any
integer `x`. We can construct an array with every number in the range
`[0, n]` and XOR with the input array. All that's left would be our
missing number in the input array.

For an O(1) space solution, we don't even need to construct the
size-(n+1) array with every number in `[0, n]`. Just iterate from `0` to
`n` and XOR each of them to achieve the same result.

## My C++ Solution:


```cpp
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int output = 0;
        int n = nums.size();

        for (auto num : nums) {
            output ^= num;
        }

        for (int i = 0; i <= n; ++i) {
            output ^= i;
        }

        return output;
    }
};
```
