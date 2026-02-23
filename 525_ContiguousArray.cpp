// 525_ContiguousArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/contiguous-array/
//

#include <iostream>
#include <vector>

class Solution
{
public:
  static int findMaxLength(const std::vector<int>& nums)
  {
    int maxLength = 0;
    int acc = 0;

    std::unordered_map<int, int> prefixMap;

    prefixMap.insert({ 0, 0 });

    for (int i = 0; (i < nums.size()); ++i)
    {
      acc += (nums[i] ? 1 : -1);

      const auto it = prefixMap.find(acc);

      if (it != prefixMap.end())
      {
        const int dist = (i + 1 - it->second);

        if (dist > maxLength)
          maxLength = dist;
      }
      else
      {
        prefixMap.insert({ acc, i + 1 });
      }
    }

    return maxLength;
  }
};

int main()
{
  const std::vector<int> nums{ 0,1,1,1,1,1,0,0,0 };

  std::cout << Solution::findMaxLength(nums);

  return 0;
}
