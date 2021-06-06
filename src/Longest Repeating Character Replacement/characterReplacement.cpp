#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>

class Solution
{
public:
  int characterReplacement(std::string s, int k)
  {
    int n = (int)s.length();
    std::unordered_map<char, int> count; // character frequencies in the sliding window
    int max_length = 0;       // longest consecutive substring so far (after operations). Eventually our answer.
    int most_freq_letter = 0; // most frequent char in the sliding window

    int start = 0;
    for (int end = 0; end < n; ++end) // 'end' loops through the string normally
    {
      ++count[s[end]];                                              // update current char count
      most_freq_letter = std::max(most_freq_letter, count[s[end]]); // whether current char has higher freq
      if ((end - start + 1) - most_freq_letter > k)                 // compare "no. of operations we must do", with k
      {
        --count[s[start]]; // decrease s[start]'s freq because we're about to shrink
        ++start;           // shrink window on the left
      }
      max_length = std::max(max_length, end - start + 1);
    }
    return max_length;
  }
};
