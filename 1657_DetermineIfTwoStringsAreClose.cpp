// 1657_DetermineIfTwoStringsAreClose.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/determine-if-two-strings-are-close/
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    static bool closeStrings(std::string word1, std::string word2)
    {
      if (word1.length() != word2.length())
      {
        return false;
      }

      std::vector<int> freq1(256, 0), freq2(256, 0);
      std::unordered_set<char> set1, set2;

      for (int i = 0; (i < word1.size()); ++i)
      {
        freq1[word1[i]]++;
        freq2[word2[i]]++;

        set1.insert(word1[i]);
        set2.insert(word2[i]);
      }

      sort(freq1.begin(), freq1.end());
      sort(freq2.begin(), freq2.end());

      return (freq1 == freq2) && (set1 == set2);
    }
};

int main()
{
  std::string str1 = "hola";
  std::string str2 = "hola";

  Solution::closeStrings(str1, str2);
}
