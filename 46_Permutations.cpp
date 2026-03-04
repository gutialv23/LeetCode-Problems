// 46_Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/permutations/
//

#include <iostream>
#include <vector>
#include <unordered_set>

// First solution that came to my mind.
class Solution
{
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums)
  {
    std::vector<std::vector<int>> out;

    std::vector<int> curr;

    std::unordered_set<int> inserted;

    backtrack1(curr, inserted, nums, out);

    return out;
  }

  // First solution that came to my mind.
  void backtrack1(std::vector<int>& curr, std::unordered_set<int>& inserted, std::vector<int>& nums, std::vector<std::vector<int>>& out)
  {
    if (curr.size() == nums.size())
    {
      out.push_back(curr);
      return;
    }

    for (int i = 0; (i < nums.size()); ++i)
    {
      if (inserted.find(nums[i]) == inserted.end())
      {
        curr.push_back(nums[i]);
        inserted.insert(nums[i]);
        backtrack1(curr, inserted, nums, out);
        curr.pop_back();
        inserted.erase(nums[i]);
      }
    }
  }

  // Improved solution just swapping.
  void backtrack2(int index, std::vector<int>& nums, std::vector<std::vector<int>>& out)
  {
    if (index == nums.size() - 1)
    {
      out.push_back(nums);
      return;
    }

    for (int i = index; (i < nums.size()); ++i)
    {
      swap(nums[index], nums[i]);
      backtrack2(index + 1, nums, out);
      swap(nums[index], nums[i]);
    }
  }

  void swap(int& num1, int& num2)
  {
    int aux = num1;
    num1 = num2;
    num2 = aux;
  }
};

int main()
{
  std::vector<int> nums{ 1,2,3 };

  Solution::permute(nums);

  return 0;
}
