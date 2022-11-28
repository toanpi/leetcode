/*
 * @lc app=leetcode id=1009 lang=c
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
int bitwiseComplement(int n)
{
  int cnt = (int)log2(n) + 1;

  return n ? ~n & ((1 << cnt) - 1) : 1;
}

// @lc code=end


