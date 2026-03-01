// 1679_MaxNumberOfKSumPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/max-number-of-k-sum-pairs/
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
  public:
  // First approach.
  static int maxOperations(std::vector<int>& nums, int k)
  {
    int out = 0;

    std::unordered_map<int, int> search;

    for (auto& num : nums)
    {
      const auto it = search.find(num);
      if (it != search.end() && search[num] > 0)
      {
        ++out;
        search[num]--;
      }
      else
      {
        search[k - num]++;
      }
    }

    return out;
  }
  
  // Similar approach (two pointers).
  static int maxOperations(std::vector<int>& nums, int k)
  {
    int out = 0;

    std::sort(nums.begin(), nums.end());

    int l = 0, r = nums.size() - 1;

    while (l < r)
    {
      const auto sum = nums[l] + nums[r];

      if (sum == k)
      {
        ++out;
        ++l;
        --r;
      }
      else if (sum < k)
      {
        ++l;
      }
      else
      {
        --r;
      }
    }

    return out;
  }
};

int main()
{
  std::vector<int> nums = {1,2,3,4};
  int k = 5;

  Solution::maxOperations(nums, k);

  return 0;
}
