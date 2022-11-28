/*
 * @lc app=leetcode id=509 lang=c
 *
 * [509] Fibonacci Number
 */

// @lc code=start

int fib(int n)
{
  int fn1 = 0;
  int fn2 = 1;
  int fn = 0;

  for (int i = 1; i <= n; i++)
  {
    fn = fn1 + fn2;
    fn2 = fn1;
    fn1 = fn;
  }

  return fn;
}

// @lc code=end

