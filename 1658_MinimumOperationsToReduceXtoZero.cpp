// 1658_MinimumOperationsToReduceXtoZero.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// DESCRIPTION:
//  - You are given an integer array nums and an integer x.
//    In one operation, you can either remove the leftmost or
//    the rightmost element from the array nums and subtract its value from x.
// 
//  - Note that this modifies the array for future operations.
// 
//  - Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
// 
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
//


#include <iostream>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

// We can translate the problem as the opposite one:
//
//   "Finding the longest array which sum is the (total_sum - target)"

#if 0
int32_t minOperations(vector< int32_t >& nums, int32_t target)
{
  const int32_t total_sum = accumulate(nums.begin(), nums.end(), 0);

  const int32_t req_sum = (total_sum - target);

  // To find the longest subarray having sum = req_sum.

  int32_t i = 0, j = 0, cur_sum = 0, len = INT_MIN;

  while (j < nums.size())
  {
    cur_sum += nums[j];

    if (cur_sum > req_sum)
    {
      while ((i <= j) && (cur_sum > req_sum))
      {
        cur_sum -= nums[i++];
      }
    }

    if (cur_sum == req_sum) len = max(len, (j - i + 1));

    ++j;
  }

  return ((len == INT_MIN) ? -1 : (nums.size() - len));
}
#else
int32_t maxSubArrayLen(vector<int32_t>& nums, int32_t target)
{
  int32_t out = INT_MIN;

  const int32_t sz = nums.size();

  int32_t l = 0;
  int32_t r = 0;

  int32_t sum = 0;

  while (((r < sz) || (l < sz)) && (l <= r))
  {
    if ((sum < target) && (r < sz))
    {
      sum += nums[r++];
    }
    else
    {
      if (sum == target)
      {
        out = max(out, (r - l));
      }

      sum -= nums[l++];
    }
  }

  return out;
}

int32_t minOperations(vector<int32_t>& nums, int32_t target)
{
  const int32_t total_sum = accumulate(nums.begin(), nums.end(), 0);

  const int32_t req_sum = (total_sum - target);

  const int32_t len = maxSubArrayLen(nums, req_sum);

  return ((len == INT_MIN) ? -1 : (nums.size() - len));
}
#endif

int main()
{
  int32_t x = 4;

  vector<int32_t> nums2 = { 1,1 };

  cout << minOperations(nums2, x);
}

// WARNING: Both of this solutions exceed time.

int32_t minOperationsRecursive(vector<int32_t>& nums, const int32_t x, const int32_t l, const int32_t r)
{
  int32_t num_op = -1;

       if (x <  0) num_op = -1;
  else if (x == 0) num_op =  0;
  else
  {
    if (l <= r)
    {
      int32_t num_op_l = 0;
      int32_t num_op_r = 0;

      // Left recursion.
      {
        const int32_t front = nums[l];

        num_op_l = minOperationsRecursive(nums, (x - front), (l + 1), r);
      }

      // Right recursion.
      {
        const int32_t back = nums[r];

        num_op_r = minOperationsRecursive(nums, (x - back), l, (r - 1));
      }

           if ((num_op_l < 0) &&
               (num_op_r < 0)) num_op = -1;
      else if ((num_op_l < 0)) num_op = (num_op_r + 1);
      else if ((num_op_r < 0)) num_op = (num_op_l + 1);
      else
      {
        num_op = (min(num_op_l, num_op_r) + 1);
      }
    }
  }

  return num_op;
}

int32_t minOperationsRecursive(list< int32_t >& nums, int32_t x)
{
  int32_t num_op = -1;

       if (x <  0) num_op = -1;
  else if (x == 0) num_op =  0;
  else
  {
    if (!nums.empty())
    {
      int32_t num_op_l = 0;
      int32_t num_op_r = 0;

      // Left recursion.
      {
        const int32_t front = nums.front();

        nums.pop_front();

        num_op_l = minOperationsRecursive(nums, (x - front));

        nums.push_front(front);
      }

      // Right recursion.
      {
        const int32_t back = nums.back();

        nums.pop_back();

        num_op_r = minOperationsRecursive(nums, (x - back));

        nums.push_back(back);
      }

           if ((num_op_l < 0) &&
               (num_op_r < 0)) num_op = -1;
      else if ((num_op_l < 0)) num_op = (num_op_r + 1);
      else if ((num_op_r < 0)) num_op = (num_op_l + 1);
      else
      {
        num_op = (min(num_op_l, num_op_r) + 1);
      }
    }
  }

  return num_op;
}