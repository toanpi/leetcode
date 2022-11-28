/*
 * @lc app=leetcode id=461 lang=c
 *
 * [461] Hamming Distance
 */

// @lc code=start
int hammingDistance(int a, int b)
{
  return __builtin_popcount(a ^ b);
}
// @lc code=end

