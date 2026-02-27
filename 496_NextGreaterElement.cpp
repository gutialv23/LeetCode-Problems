// 496_NextGreaterElement.cpp.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/next-greater-element-i/description/
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
    {
      std::vector<int> out(nums1.size(), -1);

      std::unordered_map<int, int> idxMap;

      for (int i = 0; (i < nums1.size()); ++i)
      {
        idxMap.insert({nums1[i], i});
      }

      std::vector<int> stack;

      for (int i = 0; (i < nums2.size()); ++i)
      {
        while (!stack.empty() && nums2[i] > nums2[stack.back()]) {
          const auto item = idxMap.find(nums2[stack.back()]);
          if (item != idxMap.end()) {
            out[item->second] = nums2[i];
          }

          stack.pop_back();
        }

        stack.push_back(i);
      }
     
      return out;
    }
};

int main()
{
  //std::vector<int> nums{ 1,12,-5,-6,50,3 };
  ListNode n5(5);
  ListNode n4(4, &n5);
  ListNode n3(3, &n4);
  ListNode n2(2, &n3);
  ListNode n1(1, &n2);

  std::cout << Solution::swapPairs(&n1);

  return 0;
}
