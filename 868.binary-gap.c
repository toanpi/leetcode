/*
 * @lc app=leetcode id=868 lang=c
 *
 * [868] Binary Gap
 */

// @lc code=start


int binaryGap(int n)
{
  // 10110
  int count = 0;
  int max = -1;
  bool started = false;

  while (n)
  {
    if ((n & 1) == 0)
    {
      count++;
    }
    else
    {
      if (started && (count > max))
      {
        max = count;
      }

      count = 0;
      started = true;
    }

    n = n >> 1;
  }

  return max + 1;
}

// @lc code=end

