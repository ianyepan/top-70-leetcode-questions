#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<std::string> letterCombinations(std::string digits)
  {
    std::vector<std::string> answer;
    if (digits.empty())
    {
      return answer;
    }
    answer.push_back("");

    for (const char &digit : digits)
    {
      std::vector<std::string> buffer;
      for (const char &letter : mappings[digit])
      {
        for (const std::string &s : answer)
        {
          buffer.push_back(s + letter);
        }
      }
      answer.swap(buffer); // overwrite answer with 'buffer'
    }
    return answer;
  }

private:
  std::unordered_map<char, std::string> mappings = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                                    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};
