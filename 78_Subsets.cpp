// 78_Subsets.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/subsets/
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
      std::vector<std::vector<int>> out;

      std::vector<int> curr;

      backtrack(0, curr, nums, out);

      return out;
    }

    void backtrack(int index, std::vector<int>& curr, std::vector<int>& nums, std::vector<std::vector<int>>& out)
    {
      out.push_back(curr);

      for (int i = index; (i < nums.size()); ++i)
      {
        curr.push_back(nums[i]);
        backtrack(i + 1, curr, nums, out);
        curr.pop_back();
      }
    }
};

int main()
{
  std::vector<int> nums{ 1,2,3 };

  Solution::merge(nums1, nums2, 3);

  return 0;
}
