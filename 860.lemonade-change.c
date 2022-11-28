/*
 * @lc app=leetcode id=860 lang=c
 *
 * [860] Lemonade Change
 */

// @lc code=start

bool lemonadeChange(int *bills, int billsSize)
{
  // $5 -> No return
  // $10 -> $5
  // $20 -> ($10, $5) or ($5, $5, $5)

  int cash[5] = {0};
  bool ret = true;

  for (int i = 0; i < billsSize; i++)
  {
    cash[bills[i] / 5]++;

    if (((bills[i] - 5) >= 10) && cash[2])
    {
      cash[2] -= (bills[i] - 5) / 10;
      cash[1]--;
    }
    else
    {
      cash[1] -= (bills[i] - 5) / 5;
    }

    if ((cash[2] < 0) || (cash[1] < 0))
    {
      ret = false;
      break;
    }
  }

  return ret;
}

// @lc code=end

