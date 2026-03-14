// 1207_UniqueNumberOfOccurrences.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/unique-number-of-occurrences/
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    static bool uniqueOccurrences(std::vector<int>& arr)
    {
      std::vector<int> map(2001, 0);

      for (auto& num : arr)
      {
        map[num + 1000]++;
      }

      std::unordered_set<int> set;

      for (auto& num : map)
      {
        if (num)
        {
          if (set.count(num))
          {
            return false;
          }

          set.insert(num);
        }
      }
        
      return true;
    }
};

int main()
{
  std::vector<int> nums1 = { 1,2,2,1,1,3 };

  Solution::uniqueOccurrences(nums1);
}
