#include <string>
#include <unordered_map>

class Solution
{
public:
  bool isAnagram(std::string s, std::string t)
  {
    if (s.length() != t.length())
    {
      return false;
    }

    std::unordered_map<char, int> m;
    for (const auto &ch : s)
    {
      m[ch] += 1;
    }
    for (const auto &ch : t)
    {
      m[ch] -= 1;
    }
    for (const auto &pp : m)
    {
      if (pp.second != 0)
      {
        return false;
      }
    }
    return true;
  }
};
