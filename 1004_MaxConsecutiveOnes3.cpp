// 1004_MaxConsecutiveOnes3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
//

#include <iostream>
#include <vector>
#include <algorithm>

// My first approach (meh...).
class Solution
{
public:
  static int longestOnes(std::vector<int>& nums, int k)
  {
    int out = 0;

    int l = 0, r = 0;

    int z = 0;

    while (r < nums.size())
    {
      if (nums[r] != 0)
      {
        ++r;
        continue;
      }

      if (z < k)
      {
        ++z;
        ++r;
        continue;
      }

      out = std::max(out, r - l);

      if (nums[l] != 0)
      {
        ++l;
        continue;
      }

      ++l;

      if (z == k && z > 0)
      {
        --z;
      }

      if (l > r) r = l;
    }

    return std::max(out, r - l);
  }
};

int main()
{
  std::vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
  int n = 2;

  Solution::longestOnes(nums, n);
}
