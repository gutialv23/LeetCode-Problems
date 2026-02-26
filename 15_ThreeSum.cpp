// 15_ThreeSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/3sum/
//

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
  {
    std::vector<std::vector<int>> out;

    std::sort(nums.begin(), nums.end()); // Default is ascending order.

    int a = 0;

    while (a < nums.size() - 2)
    {
      int b = a + 1; // starts on the first one after the base.
      int c = nums.size() - 1; // starts in the end.

      while (b < c)
      {
        const int sum = nums[a] + nums[b] + nums[c];
        if (sum == 0)
        {
          out.push_back({ nums[a], nums[b], nums[c] });

          // Avoid duplicates.
          while (b < c && nums[b] == nums[b + 1]) ++b;
          while (b < c && nums[c] == nums[c - 1]) --c;

          ++b;
          --c;
        }
        else if (sum > 0)
        {
          while (b < c && nums[c] == nums[c - 1]) --c;
          --c;
        }
        else
        {
          while (b < c && nums[b] == nums[b + 1]) ++b;
          ++b;
        }
      }

      // Avoid duplicates in a.
      while (a < nums.size() - 2 && nums[a] == nums[a + 1]) ++a;
      ++a;
    }

    return out;
  }
};

int main()
{
  const std::vector<int> nums{ -1,0,1,2,-1,-4 };

  std::cout << Solution::threeSum(nums);

  return 0;
}
