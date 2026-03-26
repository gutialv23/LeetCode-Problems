// 718_MaximumLengthOfRepeatedSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// DESCRIPTION:
//  - Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
// 
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//


#include <iostream>
#include <vector>

using namespace std;

int32_t findLength(vector<int32_t>& nums1, vector<int32_t>& nums2)
{
  int32_t max_length = 0;

  const int32_t nums1_sz = nums1.size();
  const int32_t nums2_sz = nums2.size();

  vector<vector<int32_t>> dp(nums1_sz, vector<int32_t>(nums2_sz));

  for (int32_t i = 0; (i < nums1_sz); ++i)
  for (int32_t j = 0; (j < nums2_sz); ++j)
  {
    if (!i || !j)
    {
      dp[i][j] = (nums1[i] == nums2[j]);
    }
    else if (nums1[i] == nums2[j])
    {
      dp[i][j] = (dp[i - 1][j - 1] + 1);
    }
    else
    {
      dp[i][j] = 0;
    }

    max_length = max(max_length, dp[i][j]);
  }

  return max_length;
}

int main()
{
  vector<int32_t> nums1 = { 0,1,1,1,1 };
  vector<int32_t> nums2 = { 1,0,1,0,1 };

  cout << findLength(nums1, nums2);
}
