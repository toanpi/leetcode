/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */

// @lc code=start

int calHappy(n)
{
  int sum = 0;
  while (n)
  {
    int d = n % 10;
    sum += d * d;

    n /= 10;
  }

  return sum;
}

bool isHappy(int n)
{
  bool ret = false;
  int sumN = n;
  int sumM = n;

  while (1)
  {
    sumN = calHappy(sumN);
    sumM = calHappy(calHappy(sumM));

    if ((sumN == 1) || (sumM == 1))
    {
      ret = true;
      break;
    }

    if (sumN == sumM)
    {
      // Enter endless loop
      break;
    }
  }

  return ret;
}
// @lc code=end

