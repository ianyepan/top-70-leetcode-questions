#include <algorithm>
#include <ios>
#include <vector>

class Solution
{
public:
  int maxArea(vector<int> &heights)
  {
    int left = 0, right = (int)heights.size() - 1, cur_max_area = 0;
    while (left < right)
    {
      cur_max_area = max(cur_max_area, min(heights[left], heights[right]) * (right - left));

      // Always keep the longer one and move the shorter.
      if (heights[left] < heights[right])
      {
        ++left;
      }
      else
      {
        --right;
      }
    }
    return cur_max_area;
  }
};
