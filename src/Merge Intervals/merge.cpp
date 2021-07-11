#include <algorithm>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &v)
  {
    sort(v.begin(), v.end()); // sort by start-time (default)
    std::vector<std::vector<int>> merged;

    for (const auto &pair : v)
    {
      if (!merged.empty() && merged.back()[1] >= pair[0])
      {
        merged.back()[1] = std::max(merged.back()[1], pair[1]);
      }
      else
      {
        merged.push_back(pair);
      }
    }

    return merged;
  }
};
