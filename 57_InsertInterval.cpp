// 57_InsertInterval.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/insert-interval/
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
    {
      std::vector<std::vector<int>> out;

      bool newIntervalInserted = false;

      for (int i = 0; (i < intervals.size()); ++i)
      {
        auto& interval = intervals[i];

        if (!newIntervalInserted)
        {
          // Check if we need to insert newInterval.

          if (newInterval[0] < interval[0])
          {
            if (out.empty())
            {
              // Just insert.
              out.push_back(newInterval);
            }
            else
            {
              // Check if we need to merge with the previous one.
              auto& lastInterval = out.back();
              
              if (newInterval[0] <= lastInterval[1])
              {
                if (newInterval[1] > lastInterval[1])
                {
                  // Merge.
                  lastInterval[1] = newInterval[1];
                }
                // Skip.
              }
              else
              {
                // Just insert.
                out.push_back(newInterval);
              }
            }
            
            newIntervalInserted = true;
          }
        }

        if (out.empty() || !newIntervalInserted)
        {
          // Just insert.
          out.push_back(interval);
        }
        else
        {
          // Check if we need to merge with the previous one.
          auto& lastInterval = out.back();
          
          if (interval[0] <= lastInterval[1])
          {
            if (interval[1] > lastInterval[1])
            {
              // Merge.
              lastInterval[1] = interval[1];
            }
            // Skip.
          }
          else
          {
            // Just insert.
            out.push_back(interval);
          }
        }
      }

      if (!newIntervalInserted)
      {
        // It could go last.
        if (out.empty())
        {
          // Just insert.
          out.push_back(newInterval);
        }
        else
        {
          // Check if we need to merge with the previous one.
          auto& lastInterval = out.back();
          
          if (newInterval[0] <= lastInterval[1])
          {
            if (newInterval[1] > lastInterval[1])
            {
              // Merge.
              lastInterval[1] = newInterval[1];
            }
            // Skip.
          }
          else
          {
            // Just insert.
            out.push_back(newInterval);
          }
        }
      }

      return out;
    }
};

int main()
{
  std::vector<std::vector<int>> intervals{ {1,5} };
  std::vector<int> newInterval{2,3};

  Solution::merge(intervals, newInterval);

  return 0;
}
