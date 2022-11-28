/*
 * @lc app=leetcode id=724 lang=c
 *
 * [724] Find Pivot Index
 */

// @lc code=start

int pivotIndex(int *nums, int numsSize)
{
  int lSum = 0;
  int rSum = 0;

  for (int i = 1; i < numsSize; i++)
  {
    rSum += nums[i];
  }

  for (int i = 0; i < numsSize; i++)
  {
    lSum += i ? nums[i - 1] : 0;
    rSum -= i ? nums[i] : 0;

    if (lSum == rSum)
    {
      return i;
    }
  }

  return -1;
}

// @lc code=end

