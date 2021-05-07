#include <algorithm>
#include <string>
#include <unordered_map>

class Solution
{
public:
  int characterReplacement(std::string s, int k)
  {
    int n = (int)s.length();
    std::unordered_map<char, int> count; // character frequencies in the sliding window
    int max_length = 0;                  // longest consecutive substring (after operations) so far
    int max_count = 0;                   // most frequent char occurence in the sliding window

    // j: sliding window start, i: sliding window end
    for (int j = 0, i = 0; i < n; ++i) // 'i' loops through the string normally
    {
      ++count[s[i]];                                // update current char count
      max_count = std::max(max_count, count[s[i]]); // whether current char has higher freq
      while (i - j + 1 - max_count > k)             // compare no. of operations we must do with k
      {
        --count[s[j]]; // decrease s[j]'s freq because we're going to shrink
        ++j;           // shrink window on the left
      }
      max_length = std::max(max_length, i - j + 1);
    }
    return max_length;
  }
};
