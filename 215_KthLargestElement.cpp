// 215_KthLargestElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/kth-largest-element-in-an-array/
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    static int findKthLargest(std::vector<int>& nums, int k)
    {
      std::priority_queue<int> maxHeap;

      for (int i = 0; (i < nums.size()); ++i)
      {
        const int currNum = nums[i] * -1;

        if (i < k)
        {
          maxHeap.push(currNum);
        }
        else if (currNum < maxHeap.top())
        {
          maxHeap.pop();
          maxHeap.push(currNum);
        }
      }

      return maxHeap.top() * -1;
    }
};

int main()
{
  std::vector<int> nums{ 3,2,1,5,6,4 };

  std::cout << Solution::findKthLargest(nums, 2);

  return 0;
}
