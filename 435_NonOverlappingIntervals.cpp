// 435_NonOverlappingIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/non-overlapping-intervals/
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
      std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) { return a[1] < b[1]; });

      int keep = 0;
      int keepID = 0;

      for (int i = 1; (i < intervals.size()); ++i)
      {
        if (intervals[keepID][1] > intervals[i][0])
        {
          ++keep;
        }
        else
        {
          keepID = i;
        }
      }

      return keep;
    }
};

int main()
{
  std::vector<std::vector<int>> intervals{ {1,2},{2,3},{3,4},{1,3} };

  Solution::eraseOverlapIntervals(intervals);

  return 0;
}
