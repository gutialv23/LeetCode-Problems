// RangeSumQuery2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/range-sum-query-2d-immutable/description/
//

#include <iostream>
#include <vector>

class NumMatrix
{
public:
  NumMatrix(const std::vector<std::vector<int>>& matrix)
  {
    const int numRows = matrix.size();
    const int numCols = numRows ? matrix[0].size() : 0;
    mPrefixSum = std::vector<std::vector<int>>(numRows + 1, std::vector<int>(numCols + 1, 0));

    for (int i = 1; (i <= numRows); ++i)
    {
      int rowSum = 0;

      for (int j = 1; (j <= numCols); ++j)
      {
        rowSum += matrix[i-1][j-1];

        mPrefixSum[i][j] = rowSum + mPrefixSum[i - 1][j];
      }
    }
  }

  int sumRegion(const int row1, const int col1, const int row2, const int col2)
  {
    return mPrefixSum[row2 + 1][col2 + 1] - mPrefixSum[row2 + 1][col1] - mPrefixSum[row1][col2 + 1] + mPrefixSum[row1][col1];
  }
private:
  std::vector<std::vector<int>> mPrefixSum;
};

int main()
{
  const std::vector<std::vector<int>> matrix{ {3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5}, {4,1,0,1,7}, {1,0,3,0,5} };

  NumMatrix nm{ matrix };

  std::cout << nm.sumRegion(2, 1, 4, 3);

  return 0;
}
