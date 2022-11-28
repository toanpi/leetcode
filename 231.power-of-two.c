/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start
bool isPowerOfTwo(int n)
{
  return (n > 0) && (((~(n - 1)) & n) == n);
}

// @lc code=end

