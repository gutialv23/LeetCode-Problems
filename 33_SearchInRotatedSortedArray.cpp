// 33_SearchInRotatedSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
  static int search(std::vector<int>& nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;

    int out = -1;

    while (left <= right)
    {
      int mid = (left + right) / 2;

      if (nums[mid] == target)
      {
        out = mid;
        break;
      }

      if (nums[left] <= nums[mid])
      {
        if (target < nums[mid] && target >= nums[left])
        {
          right = mid - 1;
        }
        else
        {
          left = mid + 1;
        }
      }
      else
      {
        if (target > nums[mid] && target <= nums[right])
        {
          left = mid + 1;
        }
        else
        {
          right = mid - 1;
        }
      }
    }

    return out;
  }
};

int main()
{
  std::vector<int> nums{ 3,1 };

  Solution::search(nums, 1);

  return 0;
}
