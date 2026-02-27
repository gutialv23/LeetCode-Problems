// 739_DailyTemperatures.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/daily-temperatures/description/
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
      std::vector<int> out(temperatures.size(), 0);
      std::vector<int> stack;

      for (int i = 0; (i < temperatures.size()); ++i)
      {
        while (!stack.empty() && temperatures[i] > temperatures[stack.back()])
        {
          out[stack.back()] = (i - stack.back());
          stack.pop_back();
        }

        stack.push_back(i);
      }

      return out;
    }
};

int main()
{
  std::vector<int> nums{ 73,74,75,71,69,72,76,73 };

  std::cout << Solution::dailyTemperatures(nums);

  return 0;
}
