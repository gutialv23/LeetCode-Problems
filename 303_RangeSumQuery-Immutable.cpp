// RangeSumQuery.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/range-sum-query-immutable/
//

#include <iostream>
#include <vector>

class NumArray
{
public:
  NumArray(const std::vector<int>& nums)
  {
    int sum = 0;
    for (const int& n : nums)
    {
      sum += n;
      mPrefixSum.push_back(sum);
    }
  }

  int sumRange(const int idxl, const int idxr)
  {
    if (!idxl) return mPrefixSum[idxr];

    return mPrefixSum[idxr] - mPrefixSum[idxl - 1];
  }

private:
  std::vector<int> mPrefixSum;
};


int main()
{
  const std::vector<int> nums = { -2,0,3,-5,2,-1 };

  NumArray na{ nums };

  std::cout << na.sumRange(0, 2);

  return 0;
}
