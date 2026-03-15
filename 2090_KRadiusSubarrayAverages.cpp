// 2090_KRadiusSubarrayAverages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// DESCRIPTION:
//  - You are given a 0-indexed array nums of n integers, and an integer k.
// 
//  - The k-radius average for a subarray of nums centered at some index i with the radius k
//    is the average of all elements in nums between the indices i - k and i + k (inclusive).
//    If there are less than k elements before or after the index i, then the k-radius average is -1.
// 
//  - Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.
// 
//  - The average of x elements is the sum of the x elements divided by x, using integer division.
//    The integer division truncates toward zero, which means losing its fractional part.
// 
// https://leetcode.com/problems/k-radius-subarray-averages/
//


#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int32_t> getAverages(vector<int32_t>& nums, int32_t k)
{
  vector<int32_t> out(nums.size(), -1);

  int32_t c = k;
  int32_t l = (c - k);
  int32_t r = (c + k);

  const int32_t sz = nums.size();

  const int32_t amt = ((2 * k) + 1);
        int64_t sum = 0;

  for (int32_t i = l; ((i <= r) && (i < sz)); ++i)
  {
    sum += nums[i];
  }

  while (r < sz)
  {
    out[c++] = (sum / amt);

    ++r;

                sum -= nums[l++];
    if (r < sz) sum += nums[r  ];
  }

  return out;
}

int main()
{
  int32_t k = 3;

  vector<int32_t> nums = { 7,4,3,9,1,8,5,2,6 };

  unordered_map<int32_t, unordered_set<int32_t> > num_to_indices;

  const vector<int32_t> out = getAverages(nums, k);

  for (auto it = out.begin(); (it != out.end()); ++it)
  {
    cout << *it << " ";
  }

  cout << endl;
}
