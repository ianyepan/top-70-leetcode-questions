#include <algorithm>
#include <ios>
#include <vector>

class Solution
{
public:
  int maxArea(std::vector<int> &heights)
  {
    int left = 0, right = (int)heights.size() - 1, cur_max_area = 0, cur_area;
    while (left < right)
    {
      cur_area = std::min(heights[left], heights[right]) * (right - left);
      cur_max_area = std::max(cur_max_area, cur_area);

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
