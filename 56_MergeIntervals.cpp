// 56_MergeIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/merge-intervals/description/
//

#include <iostream>
#include <vector>
#include <queue>


class Solution {
public:
    static std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
      struct
      {
        bool operator()(std::vector<int>& v1, std::vector<int>& v2)
        {
          return v1[0] < v2[0];
        }
      } myComparator;

      std::sort(intervals.begin(), intervals.end(), myComparator);

      std::vector<std::vector<int>> out;

      for (auto& v : intervals)
      {
        if (out.empty())
        {
          out.push_back({v[0], v[1]});
        }
        else
        {
          auto& lastInterval = out.back();

          if (v[0] <= lastInterval[1])
          {
            lastInterval[1] = std::max(v[1], lastInterval[1]);
          }
          else
          {
            out.push_back({v[0], v[1]});
          }
        }
      }

      return out;
    }
};

int main()
{
  std::vector<std::pair<int>> intervals{ {1,3},{2,6},{8,10},{15,18} };

  Solution::merge(nums1, nums2, 3);

  return 0;
}
