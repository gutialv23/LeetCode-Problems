// 347_TopKFrequentElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/top-k-frequent-elements/description/
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

// To compare two pairs: https://www.geeksforgeeks.org/cpp/implement-min-heap-using-stl/
class myComparator
{
public:
  int operator() (const std::pair<int, int>& p1, const std::pair<int, int>& p2)
  {
    return p1.second > p2.second;
  }
};

class Solution
{
public:
  static std::vector<int> topKFrequent(std::vector<int>& nums, int k)
  {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, myComparator> minHeap;
    std::unordered_map<int, int> cntMap;

    for (auto& num : nums)
    {
      ++cntMap[num];
    }

    int i = 0;
    for (auto& [num, cnt] : cntMap)
    {
      if (i < k)
      {
        minHeap.push(std::make_pair(num, cnt));
      }
      else if (minHeap.top().second < cnt)
      {
        minHeap.pop();
        minHeap.push(std::make_pair(num, cnt));
      }

      ++i;
    }

    std::vector<int> out;
    while (!minHeap.empty())
    {
      out.push_back(minHeap.top().first);
      minHeap.pop();
    }

    return out;
  }
};

int main()
{
  std::vector<int> nums{ 1,1,1,2,2,3 };

  Solution::topKFrequent(nums, 2);

  return 0;
}
