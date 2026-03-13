// 1493_LongestSubarrayOf1sAfterDeletingOneElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:

  // First approach.
  static int longestSubarray(std::vector<int>& nums)
  {
    int out = 0;
    
    std::vector<int> acc(nums.size(), 0);

    for (int i = 1; (i < nums.size()); ++i)
    {
      if (nums[i - 1] == 0)
      {
        acc[i] = 0;
      }
      else
      {
        acc[i] = acc[i - 1] + 1;
      }
    }

    int racc = 0;
    
    for (int i = nums.size() - 2; (i < nums.size()); ++i)
    {
      if (nums[i + 1] != 0)
      {
        racc += 1;
        acc[i] += racc;
      }
      else
      {
        racc = 0;
      }
    }

    for (int i = 0; (i < nums.size()); ++i)
    {
      out = std::max(out, acc[i]);
    }

    return out;
  }

  // Fastest approach (Sliding Window).
  static int longestSubarray(std::vector<int>& nums)
  {
    int out = 0;

    int l = 0;
    int z = 0;

    for (int r = 0; (r < nums.size()); ++r)
    {
      if (nums[r] == 0)
      {
        ++z;
      }

      while (z > 1)
      {
        if (nums[l] == 0)
        {
          --z;
        }
        ++l;
      }

      out = std::max(out, r - l);
    }

    return out;
  }
};

int main()
{
  std::vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
  int n = 2;

  Solution::longestSubarray(nums);
}
