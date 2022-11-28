/*
 * @lc app=leetcode id=693 lang=c
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start

bool hasAlternatingBits(int n)
{
  int a = (n >> 1) ^ n;

  return ((a >> 1) & a) == a >> 1;
}

// @lc code=end

