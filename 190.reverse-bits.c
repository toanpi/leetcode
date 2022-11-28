/*
 * @lc app=leetcode id=190 lang=c
 *
 * [190] Reverse Bits
 */

// @lc code=start
uint32_t reverseBits(uint32_t n)
{
  uint32_t out = 0;

  for (int i = 0; i < 32; i++)
  {
    out <<= 1;
    out |= n & 0x1;
    n >>= 1;
  }

  return out;
}

// @lc code=end

