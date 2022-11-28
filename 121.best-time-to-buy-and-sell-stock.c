/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#define max(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int *prices, int pricesSize)
{
  int profit = 0;
  int min = 10001;

  for (int i = 0; i < pricesSize; i++)
  {
    if (prices[i] < min)
    {
      min = prices[i];
    }
    else
    {
      profit = max(prices[i] - min, profit);
    }
  }

  return profit;
}

// @lc code=end

