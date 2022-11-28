/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start


int mySqrt(int x)
{
  if ((x == 0) || (x == 1))
  {
    return x;
  }

  long l = 0;
  long h = x / 2;
  long mid = (l + h) / 2;
  int ret = 0;

  while (l <= h)
  {
    mid = (l + h) / 2;
    long long square = mid * mid;

    if (square == x)
    {
      ret = mid;
      break;
    }
    else if (square < x)
    {
      ret = mid;
      l = mid + 1;

      if(l * l > x)
      {
        break;
      }
    }
    else
    {
      h = mid - 1;
    }
  }

  return ret;
}

// @lc code=end

