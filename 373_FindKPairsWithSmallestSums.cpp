// 373_FindKPairsWithSmallestSums.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
//

#include <iostream>
#include <vector>
#include <queue>

class Triplet
{
public:
  Triplet(int a, int b) : mA(a), mB(b), mSum(a + b) {}

  bool operator>(const Triplet& other) const
  {
    return mSum < other.mSum;
  }

  int mA, mB, mSum;
};

class Solution
{
public:
  static std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
  {
    std::priority_queue<Triplet, std::vector<Triplet>, std::greater<Triplet>> maxHeap;

    for (int i = 0; (i < nums1.size() && i < k); ++i)
    {
      for (int j = 0; (j < nums2.size() && j < k); ++j)
      {
        if (maxHeap.size() < k)
        {
          maxHeap.push(Triplet(nums1[i], nums2[j]));
        }
        else
        {
          const int sum = nums1[i] + nums2[j];

          if (sum < maxHeap.top().mSum)
          {
            maxHeap.pop();
            maxHeap.push(Triplet(nums1[i], nums2[j]));
          }
          else
          {
            break;
          }
        }
      }
    }

    std::vector<std::vector<int>> out;

    while (!maxHeap.empty())
    {
      std::vector<int> nums;
      nums.push_back(maxHeap.top().mA);
      nums.push_back(maxHeap.top().mB);

      out.push_back(nums);
      maxHeap.pop();
    }

    return out;
  }
};

// Improved solution.
class Triplet2
{
public:
  Triplet2(int a, int b, int sum) : mA(a), mB(b), mSum(sum) {}

  bool operator>(const Triplet2& other) const
  {
    return mSum > other.mSum;
  }

  int mA, mB, mSum;
};
class Solution2
{
public:
  static std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
  {
    std::vector<std::vector<int>> out;

    std::priority_queue<Triplet2, std::vector<Triplet2>, std::greater<Triplet2>> minHeap;

    for (int i = 0; (i < nums1.size() && i < k); ++i)
    {
      minHeap.push(Triplet2(i, 0, nums1[i] + nums2[0]));
    }

    while (k > 0 && !minHeap.empty())
    {
      const auto triplet = minHeap.top();
      minHeap.pop();

      out.push_back({ nums1[triplet.mA], nums2[triplet.mB] });

      if (triplet.mB + 1 < nums2.size())
      {
        minHeap.push(Triplet2(triplet.mA, triplet.mB + 1, nums1[triplet.mA] + nums2[triplet.mB + 1]));
      }

      --k;
    }

    return out;
  }
};

int main()
{
  std::vector<int> nums1{ 1,7,11 };
  std::vector<int> nums2{ 2,4,6 };

  Solution2::kSmallestPairs(nums1, nums2, 3);

  return 0;
}
