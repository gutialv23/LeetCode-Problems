// 11_ContainerWithMostWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/container-with-most-water/
//

#include <iostream>
#include <vector>

class Solution {
public:
    static int maxArea(std::vector<int>& height)
    {
      int maxArea = 0;

      int a = 0;
      int b = height.size() - 1;

      while (a < b) {
        int minh = std::min(height[a], height[b]);
        int area = (b - a) * minh;

        if (area > maxArea)
        {
          maxArea = area;
        }

        if (height[a] < height[b])
        {
          const int k = a++;
          while (a < b && height[a] <= height[k]) ++a;
        }
        else
        {
          const int k = b--;
          while (a < b && height[b] <= height[k]) --b;
        }
      }

      return maxArea;
    }
};

int main()
{
  const std::vector<int> nums{ 1,8,6,2,5,4,8,3,7 };

  std::cout << Solution::maxArea(nums);

  return 0;
}
