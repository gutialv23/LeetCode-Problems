// 70_ClimbingStairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/climbing-stairs/
//

#include <iostream>
#include <vector>

class Solution {
public:
  static int climbStairs(int n)
  {
    std::vector<int> acc(n + 1, -1);

    acc[0] = 1;
    acc[1] = 1;

    for (int i = 2; (i < acc.size()); ++i)
    {
      acc[i] = acc[i - 1] + acc[i - 2];
    }

    return acc[n];
  }
};

int main()
{
  Solution::climbStairs(3);

  return 0;
}
