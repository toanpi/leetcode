/*
 * @lc app=leetcode id=367 lang=c
 *
 * [367] Valid Perfect Square
 */

// @lc code=start

bool isPerfectSquare(int num)
{
  long hi = num / 2;
  long lo = 1;
  long mid = 0;

  while (lo <= hi)
  {
    mid = (lo + hi) / 2;
   
    long val = mid * mid;

    if (val == num)
    {
      return true;
    }
    else if (val < num)
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }

  return num == 1;
}

// @lc code=end

