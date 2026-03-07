// 300_LongestIncreasingSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-increasing-subsequence/
//

#include <iostream>
#include <vector>

class Solution
{
public:
  static int lengthOfLIS(std::vector<int>& nums)
  {
    std::vector<int> dp(nums.size() + 1, -1);
    return lengthOfLIS(0, -1, dp, nums);
  }

  // Third approach (BS) - O(nlogn)
  static int lengthOfLIS(std::vector<int>& nums)
  {
    int length = 0;
    for (auto num : nums)
    {
      if (length == 0 || nums[length - 1] < num)
      {
        nums[length] = num;
        ++length;
      }
      else
      {
        *std::lower_bound(nums.begin(), nums.begin() + length, num) = num;
      }
    }

    return length;
  }

  // Second approach (memoization) - O(n^2).
  static int lengthOfLIS(int index, int lastIndex, std::vector<int>& dp, std::vector<int>& nums)
  {
    if (index >= nums.size()) return 0;

    // Check if we already have calculated the value.
    if (dp[lastIndex + 1] != -1)
    {
      return dp[lastIndex + 1];
    }

    int take = 0;
    int dontTake = lengthOfLIS(index + 1, lastIndex, dp, nums);

    if (lastIndex == -1 || nums[index] > nums[lastIndex])
    {
      take = 1 + lengthOfLIS(index + 1, index, dp, nums);
    }
    
    dp[lastIndex + 1] = std::max(take, dontTake);

    return dp[lastIndex + 1];
  }

  // First approach (recursion) - O(2^n).
  static int lengthOfLIS(int index, std::vector<int>& queue, std::vector<int>& nums)
  {
    int maxLength = queue.size();

    for (int i = index; (i < nums.size()); ++i)
    {
      if (queue.empty() || nums[i] > queue.back())
      {
        queue.push_back(nums[i]);
        maxLength = std::max(lengthOfLIS(i + 1, queue, nums), maxLength);
        queue.pop_back();
      }
    }

    return maxLength;
  }
};

int main()
{
  std::vector<int> nums = { 10,9,2,5,3,7,101,18 };

  Solution::lengthOfLIS(nums);

  return 0;
}
