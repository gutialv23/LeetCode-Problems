// 643_MaximumAverageSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/maximum-average-subarray-i/description/
//

#include <iostream>
#include <vector>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int acc = 0;

      for (int i = 0; (i < k); ++i) {
        acc += nums[i];
      }

      double maxAverage = (acc / (double)k);

      for (int i = k; (i < nums.size()); ++i) {
        acc -= nums[i - k];
        acc += nums[i];

        const double average = (acc / (double)k);

        if (average > maxAverage) {
          maxAverage = average;
        }
      }

      return maxAverage;
    }
};

int main()
{
  std::vector<int> nums{ 1,12,-5,-6,50,3 };
  int k = 4;

  std::cout << Solution::maxArea(nums);

  return 0;
}
