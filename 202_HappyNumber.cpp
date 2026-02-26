// 202_HappyNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/happy-number/
//

#include <iostream>
#include <vector>
#include <unordered_set>

// Slower with map.
class Solution {
public:
    bool isHappy(int n)
    {
      if (!mNumbers.insert(n).second) {
        return false;
      }

      int nextNumber = 0;
        
      while (n > 0) {
        int digit = n % 10;
        n = n / 10;

        nextNumber += digit * digit;
      }

      if (nextNumber == 1) {
        return true;
      }
      
      return isHappy(nextNumber);
    }

private:
    std::set<int> mNumbers;
};

// Faster using "two pointer" solution.
class Solution {
public:
    bool isHappy(int n)
    {
      int n1 = n;
      int n2 = getNextNumber(n);

      while (n1 != n2 && n1 != 1 && n2 != 1)
      {
        n1 = getNextNumber(n1);
        n2 = getNextNumber(getNextNumber(n2));
      }

      return n2 == 1;
    }

private:
    int getNextNumber(int n) {
      int nextNumber = 0;
        
      while (n > 0) {
        int digit = n % 10;
        n = n / 10;

        nextNumber += digit * digit;
      }

      return nextNumber;
    }
};

int main()
{
  //std::vector<int> nums{ 1,12,-5,-6,50,3 };
  int n = 19;

  std::cout << Solution::isHappy(n);

  return 0;
}
