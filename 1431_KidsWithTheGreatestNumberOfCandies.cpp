// 1431_KidsWithTheGreatestNumberOfCandies.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
    {
      std::vector<int> sortedCandies = candies;
      std::sort(sortedCandies.begin(), sortedCandies.end());

      const int max = sortedCandies.back();

      std::vector<bool> out(candies.size(), false);

      for (int i = 0; (i < candies.size()); ++i)
      {
        out[i] = (candies[i] + extraCandies >= max);
      }

      return out;
    }
};

int main()
{
  std::vector<int> candies = {2,3,5,1,3};
  int extraCandies = 3;

  Solution::kidsWithCandies(candies, extraCandies);
}
