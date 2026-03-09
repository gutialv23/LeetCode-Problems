// 238_ProductOfArrayExceptSelf.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/product-of-array-except-self/
//

#include <iostream>
#include <vector>

// First approach (brute force)
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
      std::vector<int> out(nums.size(), 1);

      for (int i = 0; (i < nums.size()); ++i)
      {
        for (int j = 0; (j < nums.size()); ++j)
        {
          if (i != j)
          {
            out[i] *= nums[j];
          }
        }
      }

      return out;
    }
};

// Second approach (DP).
class Solution {
public:
    static std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
      std::vector<int> out(nums.size(), 1);

      std::vector<int> lProduct(nums.size(), 1);
      std::vector<int> rProduct(nums.size(), 1);

      for (int i = 1; (i < nums.size()); ++i)
      {
        lProduct[i] = lProduct[i - 1] * nums[i - 1];
      }

      for (int i = nums.size() - 2; (i >= 0); --i)
      {
        rProduct[i] = rProduct[i + 1] * nums[i + 1];
      }

      for (int i = 0; (i < nums.size()); ++i)
      {
        out[i] = lProduct[i] * rProduct[i];
      }

      return out;
    }
};

// Third approach (DP - leetcode solution).
class Solution {
public:
    static std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
      std::vector<int> out(nums.size(), 1);

      // Accumulate left products.
      for (int i = 1; (i < nums.size()); ++i)
      {
        out[i] = out[i - 1] * nums[i - 1];
      }

      // Accumulate right product and multiply.
      int right = 1;
      for (int i = nums.size() - 1; (i >= 0); --i)
      {
        out[i] *= right;
        right *= nums[i + 1];
      }

      return out;
    }
};

int main()
{
  std::vector<int> nums{ 3,2,1,5,6,4 };

  Solution::productExceptSelf(nums);

  return 0;
}
