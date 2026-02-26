// 167_TwoSumSorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//

#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& numbers, int target) {
      std::vector<int> out;

      int a = 0;
      int b = numbers.size() - 1;

      while (a < b) {
        const auto sum = numbers[a] + numbers[b];
        if (sum == target) {
          out.push_back(a+1);
          out.push_back(b+1);
          return out;
        }
        else if (sum > target) {
          --b;
        }
        else {
          ++a;
        }
      }
      
      return out;
    }
};

int main()
{
  const std::vector<int> nums{ 5,20,25,30,75,85 };
  const int k = 100;

  std::cout << Solution::twoSum(nums, k);

  return 0;
}
