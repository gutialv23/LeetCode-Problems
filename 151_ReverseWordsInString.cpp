// 151_ReverseWordsInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/reverse-words-in-a-string
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string reverseWords(std::string s)
    {
      std::string out;
      int lchar = s.size() - 1;
      int rchar = s.size() - 1;

      while (lchar >= 0)
      {
        if (s[rchar] == ' ')
        {
          --rchar;
          --lchar;
          continue;
        }

        if (s[lchar] != ' ')
        {
          --lchar;
          continue;
        }

        if (!out.empty()) out += ' ';
        out += s.substr(lchar + 1, rchar - lchar);
        rchar = lchar;
      }

      if (rchar >= 0)
      {
        if (!out.empty()) out += ' ';
        out += s.substr(lchar + 1, rchar - lchar);
      }

      return out;
    }
};

int main()
{
  // TODO: fill.
  return 0;
}
