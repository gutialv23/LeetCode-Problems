// 287_FindTheDuplicateNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-the-duplicate-number/description/
//

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
      int id1 = 0;
      int id2 = 1;

      while (id1 != id2)
      {
        id1 = nums[id1];
        id2 = nums[nums[id2]];
      }

      id1 = 0;
      

      while (id1 != id2)
      {
        id1 = nums[id1];
        id2 = nums[id2];
      }
      
      return id1;
    }
};

int main()
{
  std::vector<int> nums{ 1,3,4,2,2 };
  int n = 19;

  std::cout << Solution::findDuplicate(nums);

  return 0;
}
