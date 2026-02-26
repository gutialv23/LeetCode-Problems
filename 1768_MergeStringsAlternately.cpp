// 1768_MergeStringsAlternately.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/merge-strings-alternately/
//


#include <iostream>
#include <vector>

class Solution {
public:
    static std::string mergeAlternately(std::string word1, std::string word2) {
      std::string out;
      int i = 0;

      for (; (i < word1.size()) || (i < word2.size()); ++i)
      {
        out += word1[i];
        out += word2[i];
      }

      if (i < word1.size())
      {
        out += word1.substr(i);
      }
      else if (i < word2.size())
      {
        out += word2.substr(i);
      }

      return out;
    }
};

int main()
{
  std::string nums1 = "abc";
  std::string nums2 = "pqr";

  std::cout << Solution::mergeAlternately( nums1, nums2 );
}
