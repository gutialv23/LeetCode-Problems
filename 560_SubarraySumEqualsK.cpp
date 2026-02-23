// 560_SubarraySumEqualsK.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/subarray-sum-equals-k/description/
//

#include <iostream>
#include <vector>

class Solution {
public:
    static int subarraySum(std::vector<int>& nums, int k) {
      
      std::unordered_map<int, int> accMap;
      int acc = 0;
      int cnt = 0;

      accMap.insert({acc, 1});

      for (int& i : nums) {
        acc += i;
        
        auto it = accMap.find(acc - k);

        if (it != accMap.end()) {
          cnt += it->second;
        }
        
        it = accMap.find(acc);

        if (it != accMap.end()) {
          it->second++;
        } else {
          accMap.insert({acc, 1});
        }
      }

      return cnt;
    }
};

int main()
{
  const std::vector<int> nums{ 1,1,1 };
  const int k = 2;

  std::cout << Solution::subarraySum(nums, k);

  return 0;
}
