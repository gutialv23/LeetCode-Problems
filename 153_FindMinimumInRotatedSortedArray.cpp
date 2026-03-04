// 153_FindMinimumInRotatedSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    static int findMin(std::vector<int>& nums)
    {
      int left = 0;
      int right = nums.size() - 1;

      int out = nums[0];

      while (left <= right)
      {
        const int mid = (left + right) / 2;

        if (nums[mid] < out)
        {
          out = nums[mid];
        }

        if (nums[left] <= nums[mid])
        {
          if (nums[left] < out)
          {
            out = nums[left];
          }
          left = mid + 1;
        }
        else
        {
          right = mid - 1;
        }
      }

      return out;
    }
};

int main()
{
  std::vector<int> nums{ 3,4,5,1,2 };

  Solution::search(nums, 1);

  return 0;
}
