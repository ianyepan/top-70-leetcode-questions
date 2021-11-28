#include <algorithm>
#include <vector>

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int n = (int)nums.size();
    if (n == 0)
    {
      return 0;
    }
    int max_prod = nums[0]; // eventually our answer
    int cur_max = nums[0];  // max prod up till current num

    int cur_min = nums[0];  // min prod up till current min
    for (int i = 1; i < n; ++i)
    {
      int cand1 = cur_max * nums[i]; // candidate 1
      int cand2 = cur_min * nums[i]; // candidate 2
      int cand3 = nums[i];           // candidate 3
      cur_max = max({cand1, cand2, cand3});
      cur_min = min({cand1, cand2, cand3});
      max_prod = max(max_prod, cur_max);
    }
    return max_prod;
  }
};
