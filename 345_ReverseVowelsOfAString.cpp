// 345_ReverseVowelsOfAString.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/reverse-vowels-of-a-string/description/
//

#include <iostream>
#include <vector>
#include <algorithm>

// My first approach.
class Solution {
public:
  static std::string reverseVowels(std::string s)
  {
    int l = 0, r = s.size() - 1;

    while (l < r)
    {
      if (!isVowel(s[l]))
      {
        ++l;
        continue;
      }

      if (!isVowel(s[r]))
      {
        --r;
        continue;
      }
      
      std::swap(s[l], s[r]);

      ++l;
      --r;
    }
  }

private:
  static bool isVowel(char c)
  {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
};

int main()
{
  std::string str = "IceCreAm";

  std::cout << Solution::reverseVowels(str);
}
