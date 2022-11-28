/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */

// @lc code=start

bool isPowerOfThree(int n)
{
  while (n > 1)
  {
    if (n % 3)
    {
      return false;
    }

    n /= 3;
  }

  return n >= 1;
}

// @lc code=end

