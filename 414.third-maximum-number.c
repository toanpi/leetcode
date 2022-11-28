/*
 * @lc app=leetcode id=414 lang=c
 *
 * [414] Third Maximum Number
 */

// @lc code=start

int thirdMax(int *nums, int numsSize)
{
  long m0 = LONG_MIN;
  long m1 = LONG_MIN;
  long m2 = LONG_MIN;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] > m0)
    {
      m2 = m1;
      m1 = m0;
      m0 = nums[i];
    }
    else if (nums[i] > m1 && nums[i] != m0)
    {
      m2 = m1;
      m1 = nums[i];
    }
    else if (nums[i] > m2 && nums[i] != m0 && nums[i] != m1)
    {
      m2 = nums[i];
    }
  }

  return m2 == LONG_MIN ? m0 : m2;
}

// @lc code=end

