// 695_CanPlaceFlowers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://leetcode.com/problems/can-place-flowers/
//

#include <iostream>
#include <vector>
#include <algorithm>

// My first approach.
class Solution {
public:
    static bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
    {
      int i = 0;

      while (i < flowerbed.size() && n > 0)
      {
        if (flowerbed[i] == 0)
        {
          if ((i - 1 < 0 || flowerbed[i - 1] == 0) &&
              (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0))
          {
            --n;
            i = i + 2;
          }
          else
          { 
            ++i;
          }
        }
        else
        {
          i = i + 2;
        }
      }

      return n <= 0;
    }
};

int main()
{
  std::vector<int> flowerbed = {1,0,0,0,0,1};
  int n = 2;

  std::cout << Solution::canPlaceFlowers(flowerbed, n);
}
