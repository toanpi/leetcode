/*
 * @lc app=leetcode id=191 lang=c
 *
 * [191] Number of 1 Bits
 */

// @lc code=start

int hammingWeight(uint32_t n)
{
  int cnt = 0;

  while (n)
  {
    if (n & 1) cnt++;
    n >>= 1;
  }

  return cnt;
}

// @lc code=end
