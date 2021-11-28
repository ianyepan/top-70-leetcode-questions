class Solution {
 public:
  int findMin(const vector<int> &nums) {
    int n = (int)nums.size();

    // Check if the array is rotated at all (MUST check!)
    if (nums[n - 1] >= nums[0]) {
      return nums[0];
    }

    int low = 0, high = n - 1;

    while (low < high) {
      int mid = low + (high - low) / 2;
      // found the breakpoint
      if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }
      // found the breakpoint
      if (nums[mid - 1] > nums[mid]) {
        return nums[mid];
      }

      if (nums[mid] > nums[low]) {
        low = mid + 1;
      } else if (nums[mid] < nums[low]) {
        high = mid;
      }
    }

    return -1;  // on error
  }
};
