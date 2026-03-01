// 392_IsSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/is-subsequence/
//

#include <iostream>
#include <vector>

class Solution {
public:
  static bool isSubsequence(std::string s, std::string t)
  {
    int sid = 0;
    int tid = 0;

    while (sid < s.size() && tid < t.size())
    {
      if (t[tid] == s[sid])
      {
        ++sid;
      }

      ++tid;
    }

    return sid >= s.size();
  }
};

int main()
{
  std::string str1 = "abc";
  std::string str2 = "ahbgdc";

  Solution::isSubsequence(str1, str2);

  return 0;
}
