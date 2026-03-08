// 438_AnagramsInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// DESCRIPTION:
// - Given two strings s and p, return an array of all the start indices of p's anagrams in s.
//   You may return the answer in any order.
// 
// - An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
//   typically using all the original letters exactly once.
//
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Second approach map.
vector<int> findAnagrams(string s, string p)
{
  vector<int> out;
  
  vector<int> maps(128, 0);
  vector<int> mapr(128, 0);

  for (char c: p)
  {
    mapr[c]++;
  }

  int l = 0, r = 0;

  while (l <= r && r < s.size())
  {
    maps[s[r]]++;

    if (r - l != p.size() -1)
    {
      ++r;
      continue;
    }

    if (maps == mapr)
    {
      out.push_back(l);
    }

    maps[s[l++]]--;
    ++r;
  }

  return out;
}

// First approach (ordering).
vector<int> findAnagrams(string s, string p)
{
  vector<int> out;

  int l = 0, r = 0;
  
  std::sort(p.begin(), p.end());

  while (l <= r && r < s.size())
  {
    if (r - l != p.size() -1)
    {
      ++r;
      continue;
    }

    string str = s.substr(l, r - l + 1);
    std::sort(str.begin(), str.end());

    if (str == p)
    {
      out.push_back(l);
    }

    ++l;
    ++r;
  }

  return out;
}

int main()
{
  vector<int> anagrams = findAnagrams( "cbaebabacd", "abc" );

  for (int32_t id : anagrams)
  {
    cout << id;
  }
}
