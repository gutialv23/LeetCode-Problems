// 400_NthDigit.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// DESCRIPTION:
//  - Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
// 
// https://leetcode.com/problems/nth-digit/
//


#include <iostream>
#include <string>

using namespace std;

int32_t findNthDigit(int32_t digit)
{
  int32_t out = digit;

  int64_t n = 9;
  int32_t i = 1;

  while (((digit - (n * i)) > 0) && (i < 9))
  {
    digit -= (n * i);

    n *= 10;

    ++i;
  }

  if (i > 1)
  {
    const int32_t pos_in_range  = ((digit - 1) / i);
    const int32_t pos_in_number = ((digit - 1) % i);

    const int32_t start = (pow(10, (i - 1))    );
  //const int32_t end   = (pow(10,  i     ) - 1);

    const int32_t number = (start + pos_in_range);

    const string str = to_string(number);

    out = (str[pos_in_number] - '0');
  }

  return out;
}

int main()
{
  cout << findNthDigit(1000000000);
}
