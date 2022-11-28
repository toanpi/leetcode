/*
 * @lc app=leetcode id=1137 lang=c
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start


int tribonacci(int n)
{
  int tn3 = 0;
  int tn2 = 1;
  int tn1 = 1;
  int tn = 0;

  for (int i = 3; i <= n; i++)
  {
    tn3 = tn + tn1 + tn2;
    tn = tn1;
    tn1 = tn2;
    tn2 = tn3;
  }

  return n >= 3 ? tn3 : (n == 0 ? 0 : 1);
}
// @lc code=end

