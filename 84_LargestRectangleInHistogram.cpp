// 739_DailyTemperatures.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/daily-temperatures/description/
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        int maxArea = 0;

        std::vector<int> stack;

        std::vector<int> maxWidth(heights.size(), 0);

        // Find next smaller element and store distance.
        for (int i = 0; (i < heights.size()); ++i)
        {
          while (!stack.empty() && heights[i] < heights[stack.back()])
          {
            maxWidth[stack.back()] = (i - stack.back() - 1);
            stack.pop_back();
          }

          stack.push_back(i);
        }
        
        while (!stack.empty())
        {
          maxWidth[stack.back()] = (maxArea - stack.back() - 1);
          stack.pop_back();
        }

        // Find previous smaller element and add distance.
        for (int i = (heights.size() - 1); (i >= 0); --i)
        {
          while (!stack.empty() && heights[i] < heights[stack.back()])
          {
            maxWidth[stack.back()] += (stack.back() - i - 1);
            stack.pop_back();
          }

          stack.push_back(i);
        }
        
        while (!stack.empty())
        {
          maxWidth[stack.back()] += stack.back();
          stack.pop_back();
        }

        // Find biggest area.
        for (int i = 0; (i < heights.size()); ++i)
        {
          const int area = (maxWidth[i] + 1) * heights[i];

          if (area > maxArea)
          {
            maxArea = area;
          }
        }

        return maxArea;
    }
};

int main()
{
  std::vector<int> nums{ 2,4 };

  std::cout << Solution::dailyTemperatures(nums);

  return 0;
}
