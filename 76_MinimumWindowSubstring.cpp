// 76_MinimumWindowSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/minimum-window-substring/description/
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
      std::vector<int> tmap(128, 0);

      for (char &c : t) {
        ++tmap[c];
      }

      int minSubstrStart = 0;
      int minSubstrLength = INT_MAX;
      
      int l = 0;
      int r = 0;
      int cnt = t.length();

      while (r < s.length())
      {
        if (tmap[s[r]] > 0)
        {
          --cnt; // Keep track of the num of valid letters.
        }

        --tmap[s[r]];  // Update map.
        ++r;

        while (cnt == 0)
        {
          // Complete string found -> store minimum size.
          if (r - l < minSubstrLength)
          {
            minSubstrLength = r - l;
            minSubstrStart = l;
          }

          // Check if it is the smallest.
          if (tmap[s[l]] == 0) {
            cnt++;
          }

          ++tmap[s[r]];
          ++l;
        }
      }

      return minSubstrLength == INT_MAX ? "" : s.substr(minSubstrStart, minSubstrLength);
    }
};

int main()
{
  //std::vector<int> nums{ 1,12,-5,-6,50,3 };
  //int k = 4;

  std::string stra = "ADOBECODEBANC";
  std::string strb = "ABC";

  std::cout << Solution::minWindow(stra, strb);

  return 0;
}
