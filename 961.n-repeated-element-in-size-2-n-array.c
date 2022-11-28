/*
 * @lc app=leetcode id=961 lang=c
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
int repeatedNTimes(int *nums, int numsSize)
{
  int ret = 0;

  for (int i = 1; i < numsSize; i++)
  {
    if (((i >= 3) && nums[i] == nums[i - 3]) ||
        ((i >= 2) && nums[i] == nums[i - 2]) ||
        (nums[i] == nums[i - 1]))
    {
      ret = nums[i];
      break;
    }
  }

  return ret;
}

// @lc code=end

