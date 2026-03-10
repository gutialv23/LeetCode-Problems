// 1456_MaximumNumberOfVowelsInASubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  static int maxVowels(std::string s, int k)
  {
    int out = 0;

    for (int i = 0; (i < k && i < s.size()); ++i)
    {
      if (isVowel(s[i]))
      {
        ++out;
      }
    }

    if (s.size() <= k)
    {
      return out;
    }

    int windowVowels = out;

    for (int i = k; (i < s.size()); ++i)
    {
      if (isVowel(s[i])) ++windowVowels;
      if (isVowel(s[i - k])) --windowVowels;
      
      out = std::max(out, windowVowels);
    }

    return out;
  }

private:
  static bool isVowel(char c)
  {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
};

int main()
{
  std::string s = "acbiiidef";
  int n = 3;

  Solution::maxVowels(s, n);
}
