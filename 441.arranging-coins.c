/*
 * @lc app=leetcode id=441 lang=c
 *
 * [441] Arranging Coins
 */

// @lc code=start
int arrangeCoins(int n)
{
  // n = x(x + 1) / 2
  return (int)(sqrt(2 * (long)n  + 0.25) - 0.5);
}

// @lc code=end

