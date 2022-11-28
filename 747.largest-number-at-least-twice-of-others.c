/*
 * @lc app=leetcode id=747 lang=c
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start

int dominantIndex(int *nums, int numsSize)
{
  int m1 = -1;
  int m0 = -1;
  int idx = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] > m0)
    {
      m1 = m0;
      m0 = nums[i];
      idx = i;
    }
    else if (nums[i] > m1)
    {
      m1 = nums[i];
    }
  }

  return m0 >= 2 * m1 ? idx : -1;
}

// @lc code=end

