#include <stack>
#include <string>
#include <unordered_map>

class Solution
{
public:
  bool isValid(std::string s)
  {
    std::stack<char> stk;
    std::unordered_map<char, char> m{{'}', '{'}, {']', '['}, {')', '('}};
    for (const auto &ch : s)
    {
      if (is_opening(ch))
      {
        stk.push(ch);
      }
      else
      {
        if (stk.empty() || stk.top() != m[ch])
        {
          return false;
        }
        stk.pop();
      }
    }
    return stk.empty();
  }

private:
  bool is_opening(char ch)
  {
    return ch == '{' || ch == '(' || ch == '[';
  }
};
