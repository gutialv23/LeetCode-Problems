// 169_MajorityElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/majority-element/description/
//

#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
      int cnt = 0;
      int curr = 0;

      for (int i = 0; (i < nums.size()); ++i)
      {
        if (cnt == 0)
        {
          curr = nums[i];
        }

        if (nums[i] == curr)
        {
          ++cnt;
        }
        else
        {
          --cnt;
        }
      }

      return curr;
    }
};

int main()
{
  std::vector<int> nums{ 0,1,0,3,12 };

  Solution::moveZeroes(nums);

  return 0;
}
