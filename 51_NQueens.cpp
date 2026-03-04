// 78_Subsets.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/subsets/
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
      std::vector<std::vector<std::string>> out;

      std::vector<int> currSolution;

      backtrack(0, n, out);
    }

    void backtrack(std::vector<int>& currSolution, int n, std::vector<std::vector<std::string>>& out)
    {
      if (currSolution.size() == n)
      {
        out.push_back(currSolution);
        return;
      }

      for (int row = currSolution.size(); (row < n); ++row)
      {
        for (int col = 0; (col < n); ++col)
        {
          std::string row(4, '.');
          row[col] = 'Q';

          if (isValid(col, currSolution))
          { 
            currSolution.push_back(string);
            backtrack(currSolution, n, out);
            currSolution.pop_back();
          }
        }
      }
    }

    bool isValid(const int c, std::vector<int>& currSolution)
    {
      const int r = currSolution.size();

      for (int qRow = 0; (qRow < currSolution.size()); ++qRow)
      {
        const int qCol = currSolution[i];

        if (qCol == c || (c - qCol) == (r - qRow))
        {
          return false;
        }
      }

      return true;
    }
};

int main()
{
  std::vector<int> nums{ 1,2,3 };

  Solution::merge(nums1, nums2, 3);

  return 0;
}
