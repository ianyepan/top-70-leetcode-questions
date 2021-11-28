#include <iterator>
#include <string>

class Solution
{
public:
  int countSubstrings(string s)
  {
    int n = (int)s.length();

    if (n == 0)
    {
      return 0;
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
      expand(s, n, i, i, count);     // odd expand
      expand(s, n, i, i + 1, count); // even expand
    }

    return count;
  }

private:
  void expand(const string &s, const int len, int start, int end, int &count)
  {
    while (start >= 0 && end < len && s[start] == s[end])
    {
      ++count;
      --start;
      ++end;
    }
  }
};
