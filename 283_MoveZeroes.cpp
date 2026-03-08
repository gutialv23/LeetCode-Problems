// 283_MoveZeroes.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/move-zeroes/description/
//

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
  static void moveZeroes(std::vector<int>& nums)
  {
    int insertPos = 0;

    for (int i = 0; (i < nums.size()); ++i)
    {
      if (nums[i] != 0)
      {
        int aux = nums[insertPos];
        nums[insertPos] = nums[i];
        nums[i] = aux;

        insertPos++;
      }
    }
  }
};

int main()
{
  std::vector<int> nums{ 0,1,0,3,12 };

  Solution::moveZeroes(nums);

  return 0;
}
