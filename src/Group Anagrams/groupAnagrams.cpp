#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
  {
    std::unordered_map<std::string, std::vector<std::string>> m;
    std::vector<std::vector<std::string>> ans;

    for (const auto &s : strs)
    {
      auto s_sorted = s;
      std::sort(s_sorted.begin(), s_sorted.end());
      m[s_sorted].push_back(s);
    }

    for (const auto &elem : m)
    {
      ans.push_back(elem.second);
    }

    return ans;
  }
};
