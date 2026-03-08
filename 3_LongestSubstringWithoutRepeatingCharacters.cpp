// 3_LongestSubstringWithoutRepeatingCharacters.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//

#include <iostream>
#include <vector>
#include <set>


class Solution
{
public:
  // Second approach (DP)
  static int lengthOfLongestSubstring(std::string s)
  {
    if (s.size() == 0)
    {
      return 0;
    }

    std::vector<int> dp(s.size(), 1);

    for (int i = 1; (i < s.size()); ++i)
    {
      dp[i] = std::min(1 - )
    }

    return lengthOfLongestSubstring(0, dp, s);
  }

  // First approach (hash) - O(n)
  static int lengthOfLongestSubstring(std::string s)
  {
    if (s.empty())
    {
      return 0;
    }

    int maxLength = 1;
    std::set<char> hits;

    int l = 0;
    int r = 0;

    while (r < s.length())
    {
      if (hits.insert(s[r]).second)
      {
        maxLength = std::max(maxLength, r - l + 1);
      }
      else
      {
        while (l < r && s[l] != s[r])
        {
          hits.erase(s[l]);
          l++;
        }

        ++l;
      }

      ++r;
    }

    return maxLength;
  }
};

int main()
{
  //std::vector<int> nums{ 1,12,-5,-6,50,3 };
  //int k = 4;

  std::string str = "pwwkew";

  std::cout << Solution::lengthOfLongestSubstring(str);

  return 0;
}
