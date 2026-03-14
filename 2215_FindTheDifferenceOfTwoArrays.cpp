// 2215_FindTheDifferenceOfTwoArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/find-the-difference-of-two-arrays/
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    static std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2)
    {
      std::vector<int> out1, out2;

      std::unordered_set<int> set1(nums1.begin(), nums1.end());
      std::unordered_set<int> set2(nums2.begin(), nums2.end());
      
      for (auto& key : set1)
      {
        if (set2.find(key) == set2.end())
        {
          out1.emplace_back(key);
        }
      }
      
      for (auto& key : set2)
      {
        if (set1.find(key) == set1.end())
        {
          out2.emplace_back(key);
        }
      }
      
      return { out1, out2 };
    }
};

int main()
{
  std::vector<int> nums1 = { 1,2,3 };
  std::vector<int> nums2 = { 2,4,6 };

  Solution::findDifference(nums1, nums2);
}
