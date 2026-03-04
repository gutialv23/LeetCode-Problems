// 240_SearchA2DMatrix2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/search-a-2d-matrix-ii/
//

#include <iostream>
#include <vector>
#include <queue>

// Binary search solution.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
      int m = matrix.size();
      int n = matrix[0].size();

      int rowL = 0;
      int rowR = m - 1;

      int colL = 0;
      int colR = n - 1;

      for (int i = 0; (i < m); ++i)
      {
        if (matrix[i][n-1] > target && searchMatrix(matrix[i], target))
        {
          return true;
        }
      }

      return false;
    }

    bool searchMatrix(std::vector<int>& row, int target)
    {
      int rowL = 0;
      int rowR = row.size() - 1;

      while (rowL <= rowR)
      {
        const int rowM = (rowL + rowR) / 2;

        if (row[rowM] == target)
        {
          return true;
        }
        else if (row[rowM] < target)
        {
          rowL = rowM + 1;
        }
        else
        {
          rowR = rowM - 1;
        }
      }

      return false;
    }
};

// Faster solution (idea).
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
      int m = matrix.size();
      int n = matrix[0].size();

      int col = n - 1;
      int row = 0;

      while (col >= 0 && row < m)
      {
        if (matrix[row][col] == target)
        {
          return true;
        }

        if (matrix[row][col] < target)
        {
          ++row;
        }
        else
        {
          --col;
        }
      }

      return false;
    }
};

int main()
{
  std::vector<int> nums{ 3,4,5,1,2 };

  Solution::search(nums, 1);

  return 0;
}
