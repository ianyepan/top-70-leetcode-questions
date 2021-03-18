#include <algorithm>
#include <vector>

class Solution
{
public:
  int search(std::vector<int> &nums, int target)
  {
    int n = nums.size();
    if (n == 0)
      return -1;

    int low = 0, high = n - 1, mid = low + (high - low) / 2, min_idx;

    if (nums[low] < nums[high]) // already sorted
    {
      min_idx = 0;
    }
    else
    {
      while (low < high)
      {
        mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
          low = mid + 1; // look at right half
        }
        else
        {
          high = mid; // look at left half
        }
      }
      min_idx = low;

      // Reset low & high
      low = 0;
      high = n - 1;
    }
    // target happens to be the minimum num in the array
    if (target == nums[min_idx])
    {
      return min_idx;
    }
    // target in right half
    else if (target > nums[min_idx] && target <= nums[high])
    {
      low = min_idx + 1;
    }
    // target in left half
    else
    {
      high = min_idx - 1;
    }

    // Normal binary search after getting correct low & high
    while (low <= high)
    {
      mid = low + (high - low) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return -1; // not found
  }
};
