#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> answer;
    if (digits.empty()) {
      return answer;
    }
    answer.push_back("");

    vector<string> buffer;
    for (const char &digit : digits) {
      for (const char &letter : mappings[digit]) {
        for (const string &s : answer) {
          buffer.push_back(s + letter);
        }
      }
      answer.swap(buffer);  // overwrite answer with 'buffer'
      buffer.clear();
    }
    return answer;
  }

 private:
  unordered_map<char, string> mappings = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                          {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};
