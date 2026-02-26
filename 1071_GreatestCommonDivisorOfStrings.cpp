// 1071_GreatestCommonDivisorOfStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/greatest-common-divisor-of-strings/
//

#include <iostream>
#include <vector>
#include <numeric>

// My first approach.
class Solution {
public:
    static std::string gcdOfStrings(std::string str1, std::string str2)
    {
      std::string out = str1.substr(0, std::gcd(str1.length(), str2.length()));

      int i = 0;

      while (i < str2.size() || i < str1.size())
      {
        if (i < str2.size() && out != str2.substr(i, out.length()))
        {
          return "";
        }

        if (i < str1.size() && out != str1.substr(i, out.length()))
        {
          return "";
        }

        i += out.length();
      }

      return str1.substr(0, std::gcd(str1.length(), str2.length()));
    }
};

// Smart approach by AI (concatenate strings in both directions to filter out wrong cases).
class Solution {
public:
    static std::string gcdOfStrings(std::string str1, std::string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, std::gcd(str1.length(), str2.length()));
    }
};

int main()
{
  std::string str1 = "abc";
  std::string str2 = "pqr";

  std::cout << Solution::gcdOfStrings(str1, str2);
}
