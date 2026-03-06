// 322_CoinChange.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/coin-change/description/
//

#include <iostream>
#include <vector>

class Solution {
public:

    // Third version (DP - Unbounded Knapsack with optimized space)
    static int coinChange(std::vector<int>& coins, int amount)
    {
      std::vector<int> minCoins(amount + 1, INT_MAX);

      minCoins[0] = 0;

      for (int coin : coins)
      {
        for (int i = 1; (i <= amount); ++i)
        {
          if (coin <= i)  // Coin can be used.
          {
            minCoins[i] = std::min(minCoins[i], minCoins[i - coin] + 1);
          }
        }
      }

      return (minCoins[amount] == INT_MAX) ? -1 : minCoins[amount];
    }
    

    // Second version (DP - Top-Down with Memoization).
    static int coinChange(std::vector<int>& coins, int amount)
    {
      std::vector<int> acc(amount + 1, INT_MAX);      
      return coinChange(acc, coins, amount);
    }

    static int coinChange(std::vector<int>& acc, std::vector<int>& coins, int currAmount)
    {
      if (currAmount < 0)
      {
        return -1;
      }

      if (currAmount == 0)
      {
        return 0;
      }

      if (acc[currAmount] != INT_MAX)
      {
        return acc[currAmount];
      }
      
      int minCoins = INT_MAX;
      
      for (int coin : coins)
      {
        const int coinCount = coinChange(acc, coins, amount - coin);
        
        if (coinCount >= 0 && coinCount < minCoins)
        {
          // We only save the minimum one.
          minCoins = coinCount + 1;
        }
      }

      acc[currAmount] = ((minCoins == INT_MAX) ? -1 : minCoins);
      
      return acc[currAmount];
    }

    // First version too slow (not DP) -> coinChange(0, 0, coins, amount);
    static int coinChange(std::vector<int>& coins, int amount)
    {
      if (amount < 0)
      {
        return -1;
      }

      if (amount == 0)
      {
        return 0;
      }
      
      int minCoins = INT_MAX;
      
      for (int i = 0; (i < coins.size()); ++i)
      {
        const int coinCount = coinChange(coins, amount - coins[i]);
        
        if (coinCount >= 0 && coinCount < minCoins)
        {
          // We only save the minimum one.
          minCoins = coinCount + 1;
        }
      }
      
      return ((minCoins == INT_MAX) ? -1 : minCoins);
    }
    
};

int main()
{
  Solution::coinChange(3);

  return 0;
}
