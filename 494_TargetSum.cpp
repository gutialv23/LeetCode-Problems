// 494_TargetSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// DESCRIPTION:
// - You are given an integer array nums and an integer target.
// 
// - You want to build an expression out of nums by adding one of the symbols '+' and '-'
//   before each integer in nums and then concatenate all the integers.
// 
// - For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1"
// 
// - Return the number of different expressions that you can build, which evaluates to target.
//
// https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<unordered_map<int, int>> vmap_t;

int32_t findTargetSumWaysRecursiveMap(vector<int32_t>& nums, int32_t target, int32_t index, int32_t sum, vmap_t& vmap)
{
  int32_t out = 0;

  if (index == nums.size( ))
  {
    out = ((sum == target) ? 1 : 0);
  }
  else
  {
    if (!vmap[index].count(sum))  // Avoid multiple recursion for the same sum.
    {
      // Kind of Depth first search.

      vmap[index][sum] = (findTargetSumWaysRecursiveMap(nums, target, (index + 1), (sum + nums[index]), vmap) +
                          findTargetSumWaysRecursiveMap(nums, target, (index + 1), (sum - nums[index]), vmap));
    }

    out = vmap[index][sum];
  }

  return out;
}

int32_t findTargetSumWaysRecursive(vector<int32_t>& nums, int32_t target, int32_t index = 0, int32_t sum = 0)
{
  int32_t out = 0;

  if (index == nums.size())
  {
    out = ((sum == target) ? 1 : 0);
  }
  else
  {
    out += findTargetSumWaysRecursive(nums, target, (index + 1), (sum + nums[index]));
    out += findTargetSumWaysRecursive(nums, target, (index + 1), (sum - nums[index]));
  }

  return out;
}

int32_t findTargetSumWays(vector<int32_t>& nums, int32_t target)
{
  return findTargetSumWaysRecursive(nums, target);
}

int main()
{
  vector<int32_t> nums = { 1,2,5,7 };

  cout << findTargetSumWays(nums, 1);
}



// Solution from discussion.
// 
// (SO MUCH FASTER BUT... WTF? SOMETHING WITH BINARY WORK?)
#if 1

class Solution
{
public:

  int32_t findTargetSumWays(vector<int>& nums, int target)
  {
    int32_t out = 0;

	  int32_t sum = 0;

    int32_t N = nums.size();

    // Calculating sum of elements of array.

    for (int i = 0; (i <N); ++i)
    {
      sum += nums[i];
    }

    // Calculating the number of zeros that can multiply the ways exponencially.

    int zero = 0;

    for (int i = 0; (i <N); ++i)
    {
      if (nums[i] == 0) ++zero;
    }

    // Make the target positive.

    if (target <0) target *= -1;

    if ((sum + target) % 2 == 0)  // Boundary condition.
    {
      sum = (sum + target) / 2;

      vector<vector<int32_t>> t((N + 1), vector<int32_t>((sum + 1), 0));  // [N + 1] x [sum + 1]

      for (int32_t i = 0; (i < (N   + 1)); ++i) { t[i][0] = 1; }
      for (int32_t j = 1; (j < (sum + 1)); ++j) { t[0][j] = 0; }

      for (int32_t i = 1; (i < (N   + 1)); ++i)
      for (int32_t j = 1; (j < (sum + 1)); ++j)
      {
        if ((nums[i - 1] <= j) &&
            (nums[i - 1] != 0))
        {
          t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
        }
        else
        {
          t[i][j] = t[i - 1][j];
        }
      }

      out = (pow(2, zero) * t[N][sum]);
    }

    return out;
  }

};
#endif


